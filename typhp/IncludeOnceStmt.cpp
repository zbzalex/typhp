#include "IncludeOnceStmt.h"

#include <sstream>

namespace typhp {
    const std::string IncludeOnceStmt::generate() const {
        std::stringstream ss;

        ss << "include_once ";
        
        for (const ASTNode *child : children)
        {
            ss << child->generate();
        }

        ss << ";";

        return ss.str();
    }
}