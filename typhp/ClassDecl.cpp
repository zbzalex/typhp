#include "ClassDecl.h"
#include <string>
#include <sstream>

namespace typhp
{
    const std::string ClassDecl::generate() const
    {
        std::stringstream ss;

        ss << "class "
           << value
           << " "
           << "{"

           << "}";

        return ss.str();
    }
}