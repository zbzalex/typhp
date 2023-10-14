#ifndef TYPHP_RETSTMT_H
#define TYPHP_RETSTMT_H

#include "ASTNode.h"

namespace typhp
{
    class RetStmt : public ASTNode
    {
    public:
        RetStmt() : ASTNode() {}
    };
}

#endif // TYPHP_RETSTMT_H