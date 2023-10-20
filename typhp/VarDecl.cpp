#include "VarDecl.h"
#include <sstream>

namespace typhp
{
    const std::string VarDecl::generate() const
    {
        std::stringstream ss;

        ss << "/** @var " << type << " $" << value << " */"
           << " $" << value;

        if (type == "int")
        {
            ss << " = 0";
        }
        else if (type == "float" || type == "double")
        {
            ss << " = 0.0";
        }
        else
        {
            ss << " = null";
        }

        ss << ";";

        return ss.str();
    }
}