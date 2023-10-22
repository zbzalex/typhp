#include "NamespaceDecl.h"

#include <string>
#include <sstream>

namespace typhp
{
    const std::string NamespaceDecl::generate() const
    {
        std::stringstream ss;

        ss << "namespace "
           << value
           << ";";

        return ss.str();
    }
}