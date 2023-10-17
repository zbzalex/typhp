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

        ASTNode *parseIncludeDecl();

        ASTNode *parseVarDecl();
        ASTNode *parseFunctionDecl();
        ASTNode *parseClassDecl();
        ASTNode *parseEnumDecl();
        ASTNode *parseNamespaceDecl();
        ASTNode *parseUseDecl();

        
    };

} // namespace typhp

#endif // TYPHP_PARSER_H