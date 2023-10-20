#ifndef TYPHP_VARACCESS_H
#define TYPHP_VARACCESS_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class VarAccess : public ASTNode
    {
    public:
        VarAccess() : ASTNode() {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_VARACCESS_H