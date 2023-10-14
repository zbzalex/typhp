#ifndef TYPHP_NAMESPACEDECL_H
#define TYPHP_NAMESPACEDECL_H

#include "ASTNode.h"

namespace typhp
{
    class NamespaceDecl : public ASTNode
    {
    public:
        NamespaceDecl() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_NAMESPACEDECL_H