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

namespace typhp
{
    Token *Parser::next()
    {
        Token *token = look_ahead(1);

        cursor_++;

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
        ASTNode *global_scope = new ASTNode();
        while (1)
        {
            const Token *curr = next();
            if (curr == nullptr)
                break;

            // skip spaces
            if (*curr->value == '\x20' || *curr->value == '\n')
                continue;

            // std::cout << current->value << "\t"
            //           << " type is " << current->type << "\n";

            Token *next = look_ahead(1);
            Token *nextnext = look_ahead(2);
            Token *nextnextnext = look_ahead(3);

            switch (curr->type)
            {
            case TokenType_INCLUDE:
            case TokenType_INCLUDE_ONCE:
            case TokenType_REQUIRE:
            case TokenType_REQUIRE_ONCE:
            {
                global_scope->add(parse_include_decl());
            }
            break;
            case TokenType_MIXED:
            case TokenType_ARRAY:
            case TokenType_BOOL:
            case TokenType_STRING:
            case TokenType_INT:
            case TokenType_ID:
            {
                switch (next->type)
                {
                case TokenType_FUNCTION:
                {
                    global_scope->add(parse_function_decl());
                }
                break;
                case TokenType_DOLLAR:
                {
                    global_scope->add(parse_var_decl());
                }
                break;
                }
            }
            break;
            case TokenType_FINAL:
            case TokenType_ABSTRACT:
            case TokenType_INTERFACE:
            case TokenType_CLASS:
            {
                global_scope->add(parse_class_decl());
            }
            break;
            case TokenType_ENUM:
            {
                global_scope->add(parse_enum_decl());
            }
            break;
            case TokenType_USE:
            {
                global_scope->add(parse_use_decl());
            }
            break;
            case TokenType_NAMESPACE:
            {
                global_scope->add(parse_namespace_decl());
            }
            break;
            case TokenType_HTML_TEXT:
            {
            }
            break;
            }
        }

        return global_scope;
    }

    ASTNode *Parser::parse_include_decl()
    {
        IncludeStmt *ast = new IncludeStmt();
        Token *tok = nullptr;

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

    ASTNode *Parser::parse_var_decl()
    {
        return nullptr;
    }

    ASTNode *Parser::parse_function_decl()
    {
        return nullptr;
    }

    ASTNode *Parser::parse_class_decl()
    {
        Token *kind = nullptr;

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