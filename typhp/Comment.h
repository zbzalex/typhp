#ifndef TYPHP_COMMENT_H
#define TYPHP_COMMENT_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class Comment : public ASTNode
    {
    public:
        std::string value;
        bool multiline = false;

        Comment() : ASTNode()
        {
        }

        virtual const std::string generate() const;
    };
}

#endif // TYPHP_COMMENT_H