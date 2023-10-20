#ifndef TYPHP_ARRAYEXPR_H
#define TYPHP_ARRAYEXPR_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class ArrayExpr : public ASTNode
    {
    public:
        ArrayExpr() : ASTNode()
        {
        }

        const std::type_info& type() { return typeid(ArrayExpr); }
    };
}

#endif // TYPHP_ARRAYEXPR_H