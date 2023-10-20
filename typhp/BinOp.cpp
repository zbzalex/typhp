#include "BinOp.h"
#include <sstream>

namespace typhp
{
    const std::string BinOp::generate() const
    {
        std::stringstream ss;

        for (const ASTNode *child : children)
        {
            ss << child->generate();
        }

        return ss.str();
    }
}