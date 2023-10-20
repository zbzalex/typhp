#include "PhpCloseTag.h"
#include <string>

namespace typhp
{
    const std::string PhpCloseTag::generate() const
    {
        return "?>";
    }
}