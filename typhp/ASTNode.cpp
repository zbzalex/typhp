#include "ASTNode.h"
#include <algorithm>
#include <string>

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

    void ASTNode::remove(std::string &id)
    {
        const auto it = std::find_if(children_.begin(),
                                     children_.end(), [&id](auto it)
                                     { return it->get_id() == id; });
        if (it != children_.end())
        {
            children_.erase(it);
        }
    }

    void ASTNode::remove(const std::string &id)
    {
        remove(id);
    }

} // namespace typhp