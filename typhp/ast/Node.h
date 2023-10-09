#ifndef TYPHP_AST_NODE_H
#define TYPHP_AST_NODE_H

#include <vector>

namespace typhp {
namespace ast {
class Node {
    private:
        Node* parent_;
        std::vector<Node *> children_;
    public:
        Node();
        Node(Node *parent): parent_(parent) {}
        void add(Node *child);
        void remove(Node *child);
        inline std::vector<Node *> children() const { return children_; }
        inline void set_parent(Node * parent) { parent_ = parent; }
        inline Node* parent() const { parent_; }
};
} // namespace ast
} // namespace typhp

#endif // TYPHP_AST_NODE_H