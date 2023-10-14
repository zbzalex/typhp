#ifndef TYPHP_PARSER_H
#define TYPHP_PARSER_H

#include "Lexer.h"
#include <vector>
#include "ASTNode.h"

namespace typhp
{

    class Parser
    {
    private:
        std::vector<Token *> tokens_;
        int cursor_ = 0;

    public:
        Parser(std::vector<Token *> tokens) : tokens_(tokens) {}
        ASTNode *parse();
        void skip_spaces();

        inline bool has_next() const { return cursor_ + 1 < tokens_.size(); }

        Token *next();
        Token *look_ahead(int n);
        Token *current();

        void parse_var_decl(
            ASTNode *scope
        );

        void parse_function_decl(
            ASTNode *scope
        );

        void parse_class_decl(
            ASTNode *scope
        );
    };

} // namespace typhp

#endif // TYPHP_PARSER_H