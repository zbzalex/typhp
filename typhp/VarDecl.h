#ifndef TYPHP_VARDECL_H
#define TYPHP_VARDECL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class VarDecl : public ASTNode
    {
    public:
        VarDecl() : ASTNode() {}
    };
}

#endif // TYPHP_VAR_H