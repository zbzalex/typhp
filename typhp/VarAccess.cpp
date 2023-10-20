#include "VarAccess.h"
#include <string>
#include <sstream>

namespace typhp
{
    const std::string VarAccess::generate() const
    {
        std::stringstream ss;
        ss << "$";
        ss << value;

        return ss.str();
    }
}