#ifndef TYPHP_PARSER_H
#define TYPHP_PARSER_H

#include "Lexer.h"
#include <vector>
#include "ast/Node.h"

namespace typhp {

class Parser {
    private:
        std::vector<Token> tokens_;
    public:
        Parser(std::vector<Token> tokens): tokens_(tokens) {}
        typhp::ast::Node* parse();
};

} // namespace typhp

#endif // TYPHP_PARSER_H