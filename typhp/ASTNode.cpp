#include "ASTNode.h"
#include <algorithm>

namespace typhp {

ASTNode::ASTNode() {}

void ASTNode::add(ASTNode *child) {
    children_.push_back(child);
    child->set_parent(this);
}

void ASTNode::remove(ASTNode *child) {
    const auto it = std::find(children_.begin(), children_.end(), child);
    if (it != children_.end()) {
        children_.erase(it);
    }
}

} // namespace typhp