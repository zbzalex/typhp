#ifndef TYPHP_NUM_H
#define TYPHP_NUM_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class Num : public ASTNode
    {
    public:
        Num() : ASTNode() {}
        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_NUM_H