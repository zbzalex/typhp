#ifndef TYPHP_CONSTDECL_H
#define TYPHP_CONSTDECL_H

#include "ASTNode.h"

namespace typhp
{
    class ConstDecl : public ASTNode
    {
    public:
        ConstDecl() : ASTNode() {}
    };
}

#endif // TYPHP_CONSTDECL_H