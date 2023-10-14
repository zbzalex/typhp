#ifndef TYPHP_METHODDECL_H
#define TYPHP_METHODDECL_H

#include "ASTNode.h"

namespace typhp
{
    class MethodDecl : public ASTNode
    {
    public:
        MethodDecl() : ASTNode() {}
    };
}

#endif // TYPHP_METHODDECL_H