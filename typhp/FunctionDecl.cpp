#include "FunctionDecl.h"
#include <sstream>

namespace typhp
{
    const std::string FunctionDecl::generate() const
    {
        std::stringstream ss;

        ss << "/**\n"
           << " * \n"
           << " */\n"
           << "function "
           << value
           << "("
           << ")"
           << " "
           << "{\n"
           << "}\n";

        return ss.str();
    }
}