#ifndef TYPHP_METHODCALL_H
#define TYPHP_METHODCALL_H

#include "ASTNode.h"

namespace typhp
{
    class MethodCall : public ASTNode
    {
    public:
        MethodCall() : ASTNode() {}
    };
}

#endif // TYPHP_METHODCALL_H