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
#include "PhpCode.h"
#include "HtmlText.h"

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

    Token *Parser::current()
    {
        return look_ahead(0);
    }

    ASTNode *Parser::parse()
    {
        ASTNode *root = new ASTNode();
        while (1)
        {
            const Token *curr = next();
            if (curr == nullptr)
                break;

            // skip spaces
            if (*curr->value == '\x20' || *curr->value == '\n')
                continue;

            switch (curr->type)
            {
            case TokenType_PHP_START_TAG:
            {
                // PhpCode *ast = new PhpCode();
                // root->add(ast);
                // root = ast;
            }
            break;
            case TokenType_PHP_CLOSE_TAG:
            {
                // root = root->parent();
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
                        root->add(parse_comment());
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
                // root->add(parse_include_decl());
            }
            break;
            case TokenType_MIXED:
            case TokenType_ARRAY:
            case TokenType_BOOL:
            case TokenType_STRING:
            case TokenType_INT:
            case TokenType_ID:
            case TokenType_DOLLAR:
            {
                // root->add(parse_var_decl());
            }
            break;
            case TokenType_FUNCTION:
            {
                // root->add(parse_function_decl());
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

                root->add(new HtmlText(curr->value));
            }
            break;
            case TokenType_LARROW:
            {
                if (!expect(TokenType_LARROW))
                {
                    std::cout << "left arrow expected\n";
                    break;
                }

                std::cout << "parse annotation\n";

                skip_spaces();

                if (!expect(TokenType_ID))
                {
                    std::cout << "id expected\n";
                    break;
                }
            }
            break;
            }
        }

        return root;
    }

    ASTNode *Parser::parse_include_decl()
    {
        IncludeStmt *ast = nullptr;
        Token *tok = nullptr;
        Token *curr = current();

        switch (curr->type)
        {
        case TokenType_INCLUDE:
        {
            ast = new IncludeStmt();
        }
        break;
        }

        do
        {
            tok = next();

            switch (tok->type)
            {
            case TokenType_PERIOD:
            {
            }
            break;
            case TokenType_CONST_STRING:
            {
                ast->add(new Literal(std::string(tok->value)));
            }
            break;
            }
        } while (tok != nullptr && tok->type != TokenType_SEMI);

        return ast;
    }

    void Parser::skip_spaces()
    {
        Token *tok = nullptr;
        while (1)
        {
            tok = next();
            if (tok == nullptr || *tok->value == '\x20')
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

    ASTNode *Parser::parse_comment()
    {
        Comment *ast = new Comment();

        Token *next_ = next();

        ast->value += current()->value;
        ast->value += next_->value;

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

                ast->value += tok->value;

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

                ast->value += tok->value;
            }
        }

        return ast;
    }

    ASTNode *Parser::parse_var_decl()
    {
        return nullptr;
    }

    ASTNode *Parser::parse_function_decl()
    {
        std::cout << "func decl\n";

        skip_spaces();

        Token *id = next();

        std::cout << id->value << "\n";

        return nullptr;
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
} // namespace typhp;