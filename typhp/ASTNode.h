#ifndef TYPHP_ASTNODE_H
#define TYPHP_ASTNODE_H

#include <vector>
#include <string>

namespace typhp
{
    class ASTNode
    {
    protected:

    public:
        std::string value;
        ASTNode *parent = nullptr;
        std::vector<ASTNode *> children;
        ASTNode() {}
        virtual const std::string generate() const;
    };
} // namespace typhp

#endif // TYPHP_ASTNODE_H