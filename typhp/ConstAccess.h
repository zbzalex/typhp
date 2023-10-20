#ifndef TYPHP_CONSTACCESS_H
#define TYPHP_CONSTACCESS_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class ConstAccess : public ASTNode
    {
    public:
        ConstAccess() : ASTNode() {}
        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_CONSTACCESS_H