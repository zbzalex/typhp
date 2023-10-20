#ifndef TYPHP_ASTNODE_H
#define TYPHP_ASTNODE_H

#include <vector>
#include <string>
#include <typeinfo>

namespace typhp
{
    class ASTNode
    {
    protected:
        ASTNode *parent_;
        std::vector<ASTNode *> children_;

    public:
        std::string value;

        ASTNode() {}
        ASTNode(ASTNode *parent) : parent_(parent) {}
        void add(ASTNode *child);
        void remove(ASTNode *child);
        inline std::vector<ASTNode *> children() const { return children_; }
        inline void set_parent(ASTNode *parent) { parent_ = parent; }
        inline ASTNode *parent() const { return parent_; }
        virtual const std::type_info &type();
    };
} // namespace typhp

#endif // TYPHP_ASTNODE_H