#ifndef TYPHP_COMMENT_H
#define TYPHP_COMMENT_H

#include "ASTNode.h"
#include <string>
#include <typeinfo>

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

        const std::type_info &type() { return typeid(Comment); }
    };
}

#endif // TYPHP_COMMENT_H