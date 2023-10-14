#ifndef TYPHP_ENUMDECL_H
#define TYPHP_ENUMDECL_H

#include "ASTNode.h"

namespace typhp
{
    class EnumDecl : public ASTNode
    {
    public:
        EnumDecl() : ASTNode() {
            
        }
    };
}

#endif // TYPHP_ENUMDECL_H