#ifndef TYPHP_LITERAL_H
#define TYPHP_LITERAL_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class Literal : public ASTNode
    {
    private:
    public:
        std::string value;

        Literal() : ASTNode() {}
        Literal(const std::string &new_val) : ASTNode(), value(new_val) {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_LIRETERAL_H