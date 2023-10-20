#include "Literal.h"
#include <string>

namespace typhp
{
    const std::string Literal::generate() const
    {
        return value;
    }
}