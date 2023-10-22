#ifndef TYPHP_INCLUDEONCESTMT_H
#define TYPHP_INCLUDEONCESTMT_H

#include "ASTNode.h"
#include <string>

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

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_INCLUDEONCESTMT_H