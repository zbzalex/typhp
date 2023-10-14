#ifndef TYPHP_TRAITDECL_H
#define TYPHP_TRAITDECL_H

#include "ASTNode.h"

namespace typhp
{
    class TraitDecl : public ASTNode
    {
    public:
        TraitDecl() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_TRAITDECL_H