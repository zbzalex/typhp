#ifndef TYPHP_FUNCTIONCALL_H
#define TYPHP_FUNCTIONCALL_H

#include "ASTNode.h"

namespace typhp
{
    class FunctionCall : public ASTNode
    {
    public:
        FunctionCall() : ASTNode() {}
    };
}

#endif // TYPHP_FUNCTIONCALL_H