#ifndef TYPHP_OBJINSTANTIATION_H
#define TYPHP_OBJINSTANTIATION_H

#include "ASTNode.h"

namespace typhp
{
    class ObjInstantiation : public ASTNode
    {
    public:
        ObjInstantiation() : ASTNode() {}
    };
}

#endif // TYPHP_OBJINSTANTIATION_H