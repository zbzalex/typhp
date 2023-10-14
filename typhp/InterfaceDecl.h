#ifndef TYPHP_INTERFACEDECL_H
#define TYPHP_INTERFACEDECL_H

#include "ASTNode.h"

namespace typhp
{
    class InterfaceDecl : public ASTNode
    {
    public:
        InterfaceDecl() : ASTNode() {}
    };
}

#endif // TYPHP_INTERFACEDECL_H