#ifndef TYPHP_FUNCTIONDECL_H
#define TYPHP_FUNCTIONDECL_H

#include "ASTNode.h"

namespace typhp
{
    class FunctionDecl : public ASTNode
    {
    public:
        FunctionDecl() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_FUNCTIONDECL_H