#ifndef TYPHP_PHP_OPEN_TAG_H
#define TYPHP_PHP_OPEN_TAG_H

#include "ASTNode.h"

namespace typhp
{
    class PhpStartTag : public ASTNode
    {
    public:
        PhpStartTag() : ASTNode() {}
        virtual const std::string generate() const override ;
    };
}

#endif // TYPHP_PHP_OPEN_TAG_H