#ifndef TYPHP_INCLUDESTMT_H
#define TYPHP_INCLUDESTMT_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class IncludeStmt : public ASTNode
    {
    public:
        IncludeStmt() : ASTNode()
        {
        }

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_INCLUDESTMT_H