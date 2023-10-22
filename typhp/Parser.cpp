#include "Parser.h"
#include "ASTNode.h"
#include "Lexer.h"
#include <iostream>
#include "ClassDecl.h"
#include "AssignExpr.h"
#include "FunctionCall.h"
#include "FunctionDecl.h"
#include "Block.h"
#include "InterfaceDecl.h"
#include "TraitDecl.h"
#include "ObjInstantiation.h"
#include "MethodDecl.h"
#include "MethodCall.h"
#include "PropAccess.h"
#include "PropDecl.h"
#include "RetStmt.h"
#include "Literal.h"
#include "VarDecl.h"
#include "IfStmt.h"
#include "ForLoop.h"
#include "ArrayExpr.h"
#include "NamespaceDecl.h"
#include "TryCatchStmt.h"
#include "CatchClause.h"
#include "ForeachLoop.h"
#include "ForeachValue.h"
#include "DynMethodCall.h"
#include "Comment.h"
#include "AnnotationStmt.h"
#include "EnumDecl.h"
#include "IncludeStmt.h"
#include "AnonymousFunction.h"
#include "Use.h"
#include "ConstDecl.h"
#include "ConstAccess.h"
#include "ThrowStmt.h"
#include "IncludeOnceStmt.h"
#include "PhpStartTag.h"
#include "PhpCloseTag.h"
#include "HtmlText.h"
#include <sstream>
#include "BinOp.h"
#include "Num.h"
#include <stack>
#include "VarAccess.h"

namespace typhp
{
    Token *Parser::next()
    {
        Token *token = look_ahead(1);

        cursor_++;

        return token;
    }

    Token *Parser::back()
    {
        if (cursor_ == 0)
            return nullptr;

        Token *token = look_ahead(-1);

        cursor_--;

        return token;
    }

    Token *Parser::look_ahead(int n)
    {
        if (cursor_ + n >= tokens_.size())
            return nullptr;

        return tokens_.at(cursor_ + n);
    }

    Token *Parser::curr()
    {
        return look_ahead(0);
    }

    ASTNode *Parser::parse()
    {
        ASTNode *root = new ASTNode();
        Token *curr_ = nullptr;
        while ((curr_ = next()) != nullptr)
        {
            switch (curr_->type)
            {
            case TokenType_NEWLINE:
            {
                root->children.push_back(new Literal(curr_->value));
                break;
            }
            break;
            case TokenType_PHP_START_TAG:
            {
                root->children.push_back(new PhpStartTag());
            }
            break;
            case TokenType_PHP_CLOSE_TAG:
            {
                root->children.push_back(new PhpCloseTag());
            }
            break;
            case TokenType_SLASH:
            {
                Token *next_ = look_ahead(1);
                if (next_ != nullptr)
                {
                    switch (next_->type)
                    {
                    case TokenType_SLASH:
                    case TokenType_TIMES:
                    {
                        root->children.push_back(parse_comment());
                    }
                    break;
                    }
                }
            }
            break;
            case TokenType_INCLUDE:
            case TokenType_INCLUDE_ONCE:
            case TokenType_REQUIRE:
            case TokenType_REQUIRE_ONCE:
            {
                root->children.push_back(parse_include_decl());
            }
            break;
            case TokenType_MIXED:
            case TokenType_ARRAY:
            case TokenType_BOOL:
            case TokenType_STRING:
            case TokenType_INT:
            case TokenType_ID:
            {
                Token *type_ = curr_;
                Token *next_ = look_ahead(1);
                if (next_ == nullptr)
                {
                    std::cout
                        << "Unexpected symbol"
                        << " "
                        << "on line"
                        << curr_->location.line
                        << "\n";
                }
                else
                {
                    if (is_space(next_))
                    {
                        skip_spaces();
                    }

                    if (next_->type == TokenType_LPAREN)
                    {
                        FunctionCall *child = new FunctionCall();
                        child->value = type_->value;

                        expect(TokenType_RPAREN);
                        expect(TokenType_SEMICOLON);

                        root->children.push_back(child);
                    }
                    else if (next_->type == TokenType_DOLLAR)
                    {
                        next();
                        root->children.push_back(parse_var_decl(curr_));
                    }
                    else
                    {
                        std::cout
                            << "Unexpected symbol"
                            << " "
                            << "on line"
                            << curr_->location.line
                            << "\n";
                    }
                }
            }
            break;
            case TokenType_DOLLAR:
            {
                Token *curr_ = curr();
                Token *name_ = next();
                if (name_ == nullptr || name_->type != TokenType_ID)
                {

                    std::cout
                        << "Variable name is not defined"
                        << " "
                        << "on line "
                        << curr_->location.line
                        << "\n";
                }
            }
            break;
            case TokenType_FUNCTION:
            {
                root->children.push_back(parse_function_decl());
            }
            break;
            case TokenType_FINAL:
            case TokenType_ABSTRACT:
            case TokenType_INTERFACE:
            case TokenType_CLASS:
            {
                // root->add(parse_class_decl());
            }
            break;
            case TokenType_ENUM:
            {
                // root->add(parse_enum_decl());
            }
            break;
            case TokenType_USE:
            {
                // root->add(parse_use_decl());
            }
            break;
            case TokenType_NAMESPACE:
            {
                // root->add(parse_namespace_decl());
            }
            break;
            case TokenType_HTML_TEXT:
            {
                root->children.push_back(new HtmlText(curr_->value));
            }
            break;
            case TokenType_LARROW:
            {
            }
            break;
            }
        }

        return root;
    }

    bool Parser::is_space(Token *tok)
    {
        return tok != nullptr && *tok->value == '\x20';
    }

    void Parser::skip_spaces()
    {
        Token *tok = nullptr;
        while (1)
        {
            tok = next();
            if (tok == nullptr || is_space(tok))
            {
                break;
            }
        }
    }

    bool Parser::expect(TokenType token_type)
    {
        Token *tok = nullptr;
        while (1)
        {
            tok = next();
            if (tok == nullptr)
            {
                break;
            }

            if (tok->type == token_type)
            {
                return true;
            }
        }

        return false;
    }

    ASTNode *Parser::parse_expr()
    {
        ASTNode *ast = new ASTNode();

        std::stack<ASTNode *> stack_;

        BinOp *top = nullptr;
        Token *tok = nullptr;
        while ((tok = next()) != nullptr)
        {
            if (tok->type == TokenType_SEMICOLON)
                break;

            switch (tok->type)
            {
            case TokenType_CONST_STRING:
            {
                Literal *child = new Literal(tok->value);
                stack_.push(child);
            }
            break;
            case TokenType_SEMI:
            case TokenType_PERIOD:
            {
                BinOp *op = new BinOp();
                op->value = tok->value;

                if (top == nullptr)
                {
                    top = op;
                }
                else
                {
                    top->children.push_back(op);
                    op->parent = top;

                    top = op;
                }

                if (!stack_.empty())
                {
                    top->children.push_back(stack_.top());
                    stack_.pop();
                }
            }
            break;
            case TokenType_ID:
            {
                ConstAccess *child = new ConstAccess();
                child->value = tok->value;
                stack_.push(child);
            }
            break;
            case TokenType_DOLLAR:
            {
                Token *name = next();

                VarAccess *child = new VarAccess();
                child->value = name->value;
                stack_.push(child);
            }
            break;
            case TokenType_DIGIT:
            {
                Num *child = new Num();
                child->value = tok->value;
                stack_.push(child);
            }
            break;
            }
        }

        if (top != nullptr)
        {
            if (!stack_.empty())
            {
                top->children.push_back(stack_.top());
                stack_.pop();
            }

            ASTNode *parent = top;
            while (parent != nullptr)
            {
                if (parent->parent == nullptr)
                    break;

                parent = parent->parent;
            }

            if (parent != nullptr)
            {
                ast->children.push_back(parent);
            }
        }

        return ast;
    }

    ASTNode *Parser::parse_include_decl()
    {
        Token *curr_ = curr();

        ASTNode *ast = new IncludeStmt();
        switch (curr_->type)
        {
        // case TokenType_INCLUDE:
        // {
        //     ast = new IncludeStmt();
        // }
        // break;
        case TokenType_INCLUDE_ONCE:
        {
            ast = new IncludeOnceStmt();
        }
        break;
        case TokenType_REQUIRE:
        {
            // ast = new RequireStmt();
        }
        break;
        case TokenType_REQUIRE_ONCE:
        {
            // ast = new RequireOnceStmt();
        }
        break;
        }

        ast->children.push_back(parse_expr());

        return ast;
    }

    ASTNode *Parser::parse_comment()
    {
        Comment *ast = new Comment();

        Token *curr_ = curr();
        Token *next_ = next();

        std::stringstream ss;

        ss << curr_->value
           << next_->value;

        bool multiline = false;

        switch (next_->type)
        {
        case TokenType_TIMES:
        {
            multiline = true;
        }
        break;
        }

        ast->multiline = multiline;

        if (multiline)
        {
            Token *tok = nullptr;
            Token *tmp = nullptr;
            while ((tok = next()) != nullptr)
            {

                ss << tok->value;

                if (tmp != nullptr && tmp->type == TokenType_TIMES && tok->type == TokenType_SLASH)
                    break;

                tmp = tok;
            }
        }
        else
        {
            Token *tok = nullptr;
            while ((tok = next()) != nullptr)
            {
                if (tok->type == TokenType_NEWLINE)
                    break;

                ss << tok->value;
            }
        }

        ss << "\n";

        ast->value = ss.str();

        return ast;
    }

    ASTNode *Parser::parse_var_decl(Token *type)
    {
        Token *name = next();

        VarDecl *child = new VarDecl();
        child->type = type->value;
        child->value = name->value;

        return child;
    }

    ASTNode *Parser::parse_function_decl()
    {
        next();
        Token *name = next();

        FunctionDecl *child = new FunctionDecl();
        child->value = name->value;

        expect(TokenType_LPAREN);
        expect(TokenType_RPAREN);
        expect(TokenType_LBRACE);
        expect(TokenType_RBRACE);

        return child;
    }

    ASTNode *Parser::parse_class_decl()
    {
        // Token *kind = nullptr;

        return nullptr;
    }

    ASTNode *Parser::parse_enum_decl()
    {
        return nullptr;
    }

    ASTNode *Parser::parse_use_decl()
    {
        return nullptr;
    }

    ASTNode *Parser::parse_namespace_decl()
    {
        return nullptr;
    }
} // namespace typhp