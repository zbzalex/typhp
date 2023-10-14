#ifndef TYPHP_COMMENT_H
#define TYPHP_COMMENT_H

#include "ASTNode.h"

namespace typhp
{
    class Comment : public ASTNode
    {
    public:
        Comment() : ASTNode()
        {
        }
    };
}

#endif // TYPHP_COMMENT_H