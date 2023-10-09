#include "Parser.h"
#include "ASTNode.h"
#include "Lexer.h"
#include <iostream>

namespace typhp {
typhp::ASTNode * Parser::parse() {

    typhp::ASTNode * global_scope = new typhp::ASTNode();

    for ( int i = 0 ; i < tokens_.size(); i++ ) {

        const auto token = tokens_.at(i);
        
        if (token.type == TokenType_FUNCTION
            && i + 1 < tokens_.size()
            && tokens_.at(i + 1).type == TokenType_ID
            ) {
            
            const auto function_scope = new typhp::ASTNode();

            global_scope->add(function_scope);
        }

    }

    return global_scope;
}
} // namespace typhp;