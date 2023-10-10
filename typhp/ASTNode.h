#ifndef TYPHP_ASTNODE_H
#define TYPHP_ASTNODE_H

#include <vector>
#include <string>

namespace typhp
{

    class ASTNode
    {
    protected:
        ASTNode *parent_;
        std::vector<ASTNode *> children_;
        std::string type_;

    public:
        ASTNode() {}
        ASTNode(std::string &type) : type_(type) {}
        ASTNode(const std::string &type) : type_(type) {}
        ASTNode(ASTNode *parent) : parent_(parent) {}
        void add(ASTNode *child);
        void remove(ASTNode *child);
        inline std::vector<ASTNode *> children() const { return children_; }
        inline void set_parent(ASTNode *parent) { parent_ = parent; }
        inline ASTNode *parent() const { parent_; }
        inline const std::string &get_type() const { return type_; }
    };
} // namespace typhp

#endif // TYPHP_ASTNODE_H