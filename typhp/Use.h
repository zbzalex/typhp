#ifndef TYPHP_USE_H
#define TYPHP_USE_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class Use : public ASTNode
    {
    public:
        Use() : ASTNode()
        {
        }

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_USE_H