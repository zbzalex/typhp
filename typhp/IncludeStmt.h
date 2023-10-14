#ifndef TYPHP_INCLUDESTMT_H
#define TYPHP_INCLUDESTMT_H

#include "ASTNode.h"

namespace typhp
{
    class IncludeStmt : public ASTNode
    {
    public:
        IncludeStmt() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_INCLUDESTMT_H