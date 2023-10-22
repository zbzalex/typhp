#ifndef TYPHP_NAMESPACEDECL_H
#define TYPHP_NAMESPACEDECL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class NamespaceDecl : public ASTNode
    {
    public:
        NamespaceDecl() : ASTNode()
        {
        }

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_NAMESPACEDECL_H