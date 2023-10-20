#ifndef TYPHP_BINOP_H
#define TYPHP_BINOP_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class BinOp : public ASTNode
    {
    public:
        BinOp() : ASTNode() {}
        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_BINOP_H