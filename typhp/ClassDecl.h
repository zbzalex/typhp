#ifndef TYPHP_CLASSDECL_H
#define TYPHP_CLASSDECL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class ClassDecl : public ASTNode
    {
    public:
        ClassDecl() : ASTNode() {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_CLASSDECL_H