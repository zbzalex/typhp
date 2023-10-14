#ifndef TYPHP_PROPACCESS_H
#define TYPHP_PROPACCESS_H

#include "ASTNode.h"

namespace typhp
{
    class PropAccess : public ASTNode
    {
    public:
        PropAccess() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_PROPACCESS_H