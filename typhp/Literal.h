#ifndef TYPHP_LITERAL_H
#define TYPHP_LITERAL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class Literal : public ASTNode
    {
    private:
        std::string value_;

    public:
        Literal(std::string &value) : ASTNode(), value_(value) {}
        Literal(const std::string &value) : ASTNode(), value_(value) {}

        const std::string &get_value() const
        {
            return value_;
        }
    };
}

#endif // TYPHP_LIRETERAL_H