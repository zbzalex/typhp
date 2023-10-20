#ifndef TYPHP_ANONYMOUSFUNCTION_H
#define TYPHP_ANONYMOUSFUNCTION_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class AnonymousFunction : public ASTNode
    {
    public:
        AnonymousFunction() : ASTNode() {}

        const std::type_info &type() { return typeid(AnonymousFunction); }
    };
}

#endif // TYPHP_ANONYMOUSFUNCTION_H