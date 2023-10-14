#ifndef TYPHP_TRYCATCHSTMT_H
#define TYPHP_TRYCATCHSTMT_H

#include "ASTNode.h"

namespace typhp
{
    class TryCatchStmt : public ASTNode
    {
    public:
        TryCatchStmt() : ASTNode() {}
    };
}

#endif // TYPHP_TRYCATCHSTMT_H