#ifndef TYPHP_PHPCODE_H
#define TYPHP_PHPCODE_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class PhpCode : public ASTNode
    {
    public:
        PhpCode() : ASTNode() {}

        const std::type_info &type() { return typeid(PhpCode); }
    };
}

#endif // TYPHP_PHPCODE_H