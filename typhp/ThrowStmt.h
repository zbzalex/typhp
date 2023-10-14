#ifndef TYPHP_THROWSTMT_H
#define TYPHP_THROWSTMT_H

#include "ASTNode.h"

namespace typhp
{
    class ThrowStmt : public ASTNode
    {
    public:
        ThrowStmt() : ASTNode() {}
    };
}

#endif // TYPHP_THROWSTMT_H