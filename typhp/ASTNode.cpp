#include "ASTNode.h"
#include <algorithm>
#include <string>
#include <typeinfo>

namespace typhp
{
    void ASTNode::add(ASTNode *child)
    {
        children_.push_back(child);
        child->set_parent(this);
    }

    void ASTNode::remove(ASTNode *child)
    {
        const auto it = std::find(children_.begin(), children_.end(), child);
        if (it != children_.end())
        {
            children_.erase(it);
        }
    }

    const std::type_info& ASTNode::type()
    {
        return typeid(ASTNode);
    }
} // namespace typhp