#include "IncludeStmt.h"
#include <string>
#include <sstream>

namespace typhp
{
    const std::string IncludeStmt::generate() const
    {
        std::stringstream ss;

        ss << "include ";

        for (const ASTNode *child : children)
        {
            ss << child->generate();
        }

        ss << ";";

        return ss.str();
    }
}