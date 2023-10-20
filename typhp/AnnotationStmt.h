#ifndef TYPHP_ANNOTATIONSTMT_H
#define TYPHP_ANNOTATIONSTMT_H

#include "ASTNode.h"
#include <typeinfo>

namespace typhp
{
    class AnnotationStmt : public ASTNode
    {
    public:
        AnnotationStmt() : ASTNode()
        {
        }

        const std::type_info &type() { return typeid(AnnotationStmt); }
    };
}

#endif // TYPHP_ANNOTATIONSTMT_H