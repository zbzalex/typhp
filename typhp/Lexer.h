#ifndef TYPHP_LEXER_H
#define TYPHP_LEXER_H

#include <vector>
#include <string>

namespace typhp
{

    enum TokenType
    {
        TokenType_ID,
        TokenType_DIGIT,
        TokenType_REQUIRE,
        TokenType_REQUIRE_ONCE,
        TokenType_INCLUDE,
        TokenType_INCLUDE_ONCE,
        TokenType_FUNCTION,
        TokenType_CONST_STRING,
        TokenType_INT,
        TokenType_STRING,
        TokenType_LPAREN,
        TokenType_RPAREN,
        TokenType_LBRACK,
        TokenType_RBRACK,
        TokenType_LBRACE,
        TokenType_RBRACE,
        TokenType_IF,
        TokenType_ELSE,
        TokenType_ELSEIF,
        TokenType_RETURN,
        TokenType_SEMI,
        TokenType_CLASS,
        TokenType_INTERFACE,
        TokenType_PUBLIC,
        TokenType_PROTECTED,
        TokenType_PRIVATE,
        TokenType_FINAL,
        TokenType_ABSTRACT,
        TokenType_EXTENDS,
        TokenType_IMPLEMENTS,
        TokenType_STATIC,
        TokenType_ARRAY,
        TokenType_MIXED,
        TokenType_BOOL,
        TokenType_FLOAT,
        TokenType_DOUBLE,
        TokenType_LT,
        TokenType_GT,
        TokenType_EQ,
        TokenType_MINUS,
        TokenType_PLUS,
        TokenType_TIMES,
        TokenType_PERIOD,
        TokenType_SLASH,
        TokenType_BACKSLASH,
        TokenType_SINGLE_QUOTE,
        TokenType_DOUBLE_QUOTE,
        TokenType_NOT,   
        TokenType_NONNULL,
        TokenType_COLON,
        TokenType_PHP_START_TAG,
        TokenType_PHP_CLOSE_TAG,
        TokenType_HTML_TEXT,
        TokenType_SPACE,
        TokenType_NEWLINE,
        TokenType_DOLLAR,
        TokenType_USE,
        TokenType_ENUM,
        TokenType_NAMESPACE,
        TokenType_UNKN,
        TokenType_EOF,
    };

    struct SourceLocation
    {
        int start;
        int end;
        int line;
    };

    struct Token
    {
        TokenType type;
        char *value;
        int len;
        SourceLocation location;
    };

    constexpr char *delims = "@()=,[]{};:<>\\.-!?/$";
    constexpr char *blanks = "\x20\n\r\t";
    constexpr char *alnums = "abcdefghiklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ01234567890";
    constexpr char *alphas = "abcdefghiklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ";
    constexpr char *id     = "abcdefghiklmnopqrstuvwxyzABCDEFGHIKLMNOPQRSTUVWXYZ01234567890_";
    
    bool is_blank(char c);
    bool is_delim(char c);
    bool is_id(char *chars, int len);

    class Lexer
    {
    private:
        char *input_;
        int input_len_;

        std::vector<Token *> tokens_;
        
    public:
        Lexer(char *input, int len) : input_(input), input_len_(len) {}

        std::vector<Token *> tokenize();

    private:
        void push_token(int start, int len, int line);
        void push_html_text(int start, int len);
        void trim_spaces();
    };

} // namespace typhp

#endif // TYPHP_LEXER_H
