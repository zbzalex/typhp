#include "PhpStartTag.h"
#include <string>

namespace typhp {
    const std::string PhpStartTag::generate() const {
        return "<?php";
    }
}