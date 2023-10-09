#ifndef TYPHP_GENERATOR_H
#define TYPHP_GENERATOR_H

#include "ast/Node.h"

namespace typhp {
class Generator {
    private:
        typhp::ast::Node *root_;
    public:
        Generator(typhp::ast::Node *root): root_(root) {}
        void generate();
};
}

#endif