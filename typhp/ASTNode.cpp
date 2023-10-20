#include "ASTNode.h"
#include <algorithm>
#include <string>
#include <sstream>

namespace typhp
{
    const std::string ASTNode::generate() const
    {
        std::stringstream ss;
        for (const ASTNode *it : children)
        {
            ss << it->generate();
        }

        return ss.str();
    }
} // namespace typhp