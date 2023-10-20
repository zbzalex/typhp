#ifndef TYPHP_FUNCTIONCALL_H
#define TYPHP_FUNCTIONCALL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class FunctionCall : public ASTNode
    {
    public:
        FunctionCall() : ASTNode() {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_FUNCTIONCALL_H