#ifndef TYPHP_ASSIGNEXPR_H
#define TYPHP_ASSIGNEXPR_H

#include "ASTNode.h"

namespace typhp
{
    class AssignExpr : public ASTNode
    {
    public:
        AssignExpr() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_ASSIGNEXPR_H