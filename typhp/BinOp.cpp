#include "BinOp.h"
#include <sstream>
#include <iostream>

namespace typhp
{
    const std::string BinOp::generate() const
    {
        std::stringstream ss;

        ss << children[0]->generate()
           << value
           << children[1]->generate()
           ;

        return ss.str();
    }
}