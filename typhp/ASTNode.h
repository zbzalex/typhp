#ifndef TYPHP_ASTNODE_H
#define TYPHP_ASTNODE_H

#include <vector>

namespace typhp {
class ASTNode {
    private:
        ASTNode* parent_;
        std::vector<ASTNode *> children_;
    public:
        ASTNode();
        ASTNode(ASTNode *parent): parent_(parent) {}
        void add(ASTNode *child);
        void remove(ASTNode *child);
        inline std::vector<ASTNode *> children() const { return children_; }
        inline void set_parent(ASTNode * parent) { parent_ = parent; }
        inline ASTNode* parent() const { parent_; }
};
} // namespace typhp

#endif // TYPHP_ASTNODE_H