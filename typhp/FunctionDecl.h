#ifndef TYPHP_FUNCTIONDECL_H
#define TYPHP_FUNCTIONDECL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class FunctionDecl : public ASTNode
    {
    public:
        FunctionDecl() : ASTNode()
        {
        }

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_FUNCTIONDECL_H