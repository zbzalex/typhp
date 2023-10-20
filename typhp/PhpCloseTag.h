#ifndef TYPHP_PHP_CLOSE_TAG_H
#define TYPHP_PHP_CLOSE_TAG_H

#include "ASTNode.h"

namespace typhp
{
    class PhpCloseTag : public ASTNode
    {
    public:
        PhpCloseTag() : ASTNode() {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_PHP_CLOSE_TAG_H