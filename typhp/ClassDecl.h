#ifndef TYPHP_CLASSDECL_H
#define TYPHP_CLASSDECL_H

#include "ASTNode.h"

namespace typhp
{
    class ClassDecl : public ASTNode
    {
    public:
        ClassDecl() : ASTNode() {}
    };
}

#endif // TYPHP_CLASSDECL_H