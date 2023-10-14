#ifndef TYPHP_CONSTACCESS_H
#define TYPHP_CONSTACCESS_H

#include "ASTNode.h"

namespace typhp
{
    class ConstAccess : public ASTNode
    {
    public:
        ConstAccess() : ASTNode() {}
    };
}

#endif // TYPHP_CONSTACCESS_H