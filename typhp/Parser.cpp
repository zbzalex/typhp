#include "Parser.h"
#include "ast/Node.h"
#include "Lexer.h"
#include <iostream>

namespace typhp {
typhp::ast::Node * Parser::parse() {

    typhp::ast::Node * global_scope = new typhp::ast::Node();

    for ( int i = 0 ; i < tokens_.size(); i++ ) {

        const auto token = tokens_.at(i);
        
        if (token.type == TokenType_FUNCTION
            && i + 1 < tokens_.size()
            && tokens_.at(i + 1).type == TokenType_ID
            ) {
            
            const auto function_scope = new typhp::ast::Node();

            global_scope->add(function_scope);
        }

    }

    return global_scope;
}
} // namespace typhp;