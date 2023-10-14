#ifndef TYPHP_DYNMETHODCALL_H
#define TYPHP_DYNMETHODCALL_H

#include "ASTNode.h"

namespace typhp
{
    class DynMethodCall : public ASTNode
    {
    public:
        DynMethodCall() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_DYNMETHODCALL_H