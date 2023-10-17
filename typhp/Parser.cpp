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
            const Token *current = next();
            if (current == nullptr)
                break;

            // skip spaces
            if (*current->value == '\x20' || *current->value == '\n')
                continue;

            // std::cout << current->value << "\t"
            //           << " type is " << current->type << "\n";

            Token *next = look_ahead(1);
            Token *nextnext = look_ahead(2);
            Token *nextnextnext = look_ahead(3);
            
        }

        return global_scope;
    }
} // namespace typhp;