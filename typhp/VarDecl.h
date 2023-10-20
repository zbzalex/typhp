#ifndef TYPHP_VARDECL_H
#define TYPHP_VARDECL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class VarDecl : public ASTNode
    {
    public:
        std::string type;

        VarDecl() : ASTNode()
        {
        }

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_VAR_H