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
        int cursor_ = -1;

    public:
        Parser(std::vector<Token *> tokens) : tokens_(tokens) {}
        ASTNode *parse();
        void skip_spaces();

        inline bool has_next() const { return cursor_ + 1 < (int) tokens_.size(); }

        Token *next();
        Token *look_ahead(int n);
        Token *curr();
        bool expect(TokenType token_type);
        Token *back();

        ASTNode *parse_comment();
        ASTNode *parse_include_decl();
        ASTNode *parse_var_decl(
            Token *type
        );
        ASTNode *parse_function_decl();
        ASTNode *parse_class_decl();
        ASTNode *parse_enum_decl();
        ASTNode *parse_namespace_decl();
        ASTNode *parse_use_decl();        
    };

} // namespace typhp

#endif // TYPHP_PARSER_H