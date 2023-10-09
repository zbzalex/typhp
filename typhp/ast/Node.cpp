#include "Node.h"
#include <algorithm>

namespace typhp {
namespace ast {

Node::Node() {}

void Node::add(Node *child) {
    children_.push_back(child);
    child->set_parent(this);
}

void Node::remove(Node *child) {
    const auto it = std::find(children_.begin(), children_.end(), child);
    if (it != children_.end()) {
        children_.erase(it);
    }
}

} // namespace ast
} // namespace typhp