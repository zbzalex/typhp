#ifndef TYPHP_CATCHCLAUSE_H
#define TYPHP_CATCHCLAUSE_H

#include "ASTNode.h"

namespace typhp
{
    class CatchClause : public ASTNode
    {
    public:
        CatchClause() : ASTNode() {}
    };
}

#endif // TYPHP_CATCHCLAUSE_H