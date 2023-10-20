#ifndef TYPHP_INCLUDESTMT_H
#define TYPHP_INCLUDESTMT_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class IncludeStmt : public ASTNode
    {
    public:
        IncludeStmt() : ASTNode()
        {
        }

        const std::type_info& type() { return typeid(IncludeStmt); }
    };
}

#endif // TYPHP_INCLUDESTMT_H