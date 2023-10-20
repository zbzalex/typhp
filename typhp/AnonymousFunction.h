#ifndef TYPHP_ANONYMOUSFUNCTION_H
#define TYPHP_ANONYMOUSFUNCTION_H

#include "ASTNode.h"

namespace typhp
{
    class AnonymousFunction : public ASTNode
    {
    public:
        AnonymousFunction() : ASTNode() {}
    };
}

#endif // TYPHP_ANONYMOUSFUNCTION_H