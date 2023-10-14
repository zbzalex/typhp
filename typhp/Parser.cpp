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

    Token *Parser::current() {
        return look_ahead(0);
    }

    ASTNode *Parser::parse()
    {
        ASTNode *global_scope = new ASTNode();
        while (1)
        {
            const Token *current = next();
            if (current == nullptr)
                break;
            
            // skip spaces
            if (*current->value == '\x20' || *current->value == '\n')
                continue;

            // std::cout << current->value << "\t"
            //           << " type is " << current->type << "\n";

            Token *next     = look_ahead(1);
            Token *nextnext = look_ahead(2);
            Token *nextnextnext = look_ahead(3);

            if ((current->type == TokenType_INT
                || current->type == TokenType_FLOAT
                || current->type == TokenType_DOUBLE
                || current->type == TokenType_STRING
                || current->type == TokenType_BOOL
                || current->type == TokenType_MIXED
                || current->type == TokenType_ARRAY)
                && next != nullptr
                && next->type == TokenType_SPACE
                && nextnext != nullptr
                && nextnext->type == TokenType_DOLLAR
                && nextnextnext != nullptr
                && nextnextnext->type == TokenType_ID) {
                parse_var_decl(global_scope);
            } else if (current->type == TokenType_FUNCTION
                && next != nullptr
                && next->type == TokenType_SPACE
                && nextnext != nullptr
                && nextnext->type == TokenType_ID) {
                parse_function_decl();
            } else if ((current->type == TokenType_CLASS
                || current->type == TokenType_INTERFACE)
                && next != nullptr
                && next->type == TokenType_SPACE
                && nextnext != nullptr
                && nextnext->type == TokenType_ID) {
                parse_class_decl();
            } else if ((current->type == TokenType_INCLUDE
                || current->type == TokenType_INCLUDE_ONCE
                || current->type == TokenType_REQUIRE
                || current->type == TokenType_REQUIRE_ONCE)) {
                
            } else if (current->type == TokenType_SLASH
                && next != nullptr
                && next->type == TokenType_SLASH) { // single line comment
                std::cout << "detect single line comment\n";
            } else if (current->type == TokenType_SLASH
                && next->type == TokenType_TIMES) {
                std::cout << "detect multiline comments\n";
            }
        }

        return global_scope;
    }

    void Parser::parse_var_decl(
        ASTNode *scope
    ) {

        std::cout << "var decl\n";

        Token *type = current();
        next(); // skip space
        next(); // $
        Token *name = next();

        std::cout << type->value << "\n";
        std::cout << name->value << "\n";
                
        if (look_ahead(1)->type == TokenType_SEMI) {
            next();
        } else if (look_ahead(1)->type == TokenType_EQ) {
            //
        }
    }

    void Parser::parse_function_decl() {
        std::cout << "function decl\n";
        
        next(); // skip space
        Token *name = next();

        std::cout << name->value << "\n";

        // skip space
        if (look_ahead(1) != nullptr
            && look_ahead(1)->type == TokenType_SPACE)
            next();

        // (
        if (look_ahead(1) != nullptr
            && look_ahead(1)->type == TokenType_LPAREN) {

        }

    }

    void Parser::parse_class_decl() {
        Token *class_ = look_ahead(0);

        std::cout <<
            (class_->type == TokenType_CLASS
                ? "detect class"
                : "detect interface") << "\n";

        next(); // skip space

        Token *classname = next();

        std::cout << classname->value << "\n";
    }
} // namespace typhp;