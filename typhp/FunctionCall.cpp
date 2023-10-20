#include "FunctionCall.h"
#include <sstream>
#include <iostream>

namespace typhp
{
    const std::string FunctionCall::generate() const
    {
        std::stringstream ss;

        ss << value
           << "("
           << ")"
           << ";";

        return ss.str();
    }
}