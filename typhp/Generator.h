#ifndef TYPHP_GENERATOR_H
#define TYPHP_GENERATOR_H

#include "ASTNode.h"
#include <string>

namespace typhp {
class Generator {
    private:
        typhp::ASTNode *root_;
    public:
        Generator(typhp::ASTNode *root): root_(root) {}
        std::string generate();
};
}

#endif