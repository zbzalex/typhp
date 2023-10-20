#ifndef TYPHP_INCLUDEONCESTMT_H
#define TYPHP_INCLUDEONCESTMT_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class IncludeOnceStmt : public ASTNode
    {
    public:
        IncludeOnceStmt(

            )
            : ASTNode()
        {
        }

        const std::type_info &type() { return typeid(IncludeOnceStmt); }
    };
}

#endif // TYPHP_INCLUDEONCESTMT_H