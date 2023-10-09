#include "Lexer.h"
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

namespace typhp
{

    bool is_blank(char c)
    {
        int len = strlen(blanks);
        int i = 0;
        do
        {
            if (c == *(blanks + i))
                return true;
        } while (i++ < len - 1);

        return false;
    }

    bool is_delim(char c)
    {
        int len = strlen(delims);
        int i = 0;
        do
        {
            if (c == *(delims + i))
                return true;
        } while (i++ < len - 1);

        return false;
    }

    bool is_id(char *chars, int len)
    {
        if (isdigit(chars[0]))
            return false;

        int i = 0;
        do
        {
            int j = 0;
            for (; j < strlen(id) - 1; j++)
            {
                if (chars[i] == id[j])
                    return true;
            }
        } while (i++ < len - 1);

        return false;
    }

    std::vector<Token> Lexer::tokenize()
    {

        int len = 0;
        int cursor = 0;
        int start = 0;
        bool inside_string = false;
        int quote_token_type = 0;
        char c = 0;
        int line = 1;
        bool inside_php_tag = false;

        while (1)
        {
            len = cursor - start;

            if (cursor == input_len_)
            {
                c = '\0';
            }
            else
            {
                c = *(input_ + cursor);
            }

            if (c == '\n')
                line++;

            if (c == '\0')
            {
                if (len > 0)
                {
                    if (inside_php_tag)
                        push_token(start, len, line);
                    else
                        push_html_text(start, len);
                }

                break;
            }

            // detect php start tag
            if (!inside_php_tag
                && *(input_ + cursor) == '<'
                && *(input_ + cursor + 1) == '?')
            {
                if (len > 0)
                {
                    push_html_text(start, len);
                }

                start = cursor;

                inside_php_tag = true;

                push_token(start, 2, line);

                cursor += 2;

                // skip php tag
                if (   *(input_ + cursor    ) == 'p'
                    && *(input_ + cursor + 1) == 'h'
                    && *(input_ + cursor + 2) == 'p')
                {
                    cursor += 3;
                }

                start = cursor;

                continue;
            }

            if (inside_php_tag)
            {
                // detect php close tag
                if (   *(input_ + cursor    ) == '?'
                    && *(input_ + cursor + 1) == '>')
                {
                    inside_php_tag = false;

                    push_token(start, 2, line);

                    cursor += 2;
                    start = cursor;

                    continue;
                }

                if ((is_blank(c) || is_delim(c)) && !inside_string)
                {
                    if (len > 0)
                    {
                        push_token(start, len, line);
                    }

                    push_token(cursor, 1, line);

                    start = cursor + 1;
                }
                else if (c == '"')
                {
                    inside_string = !inside_string;
                }
            }

            cursor++;
        }

        if (inside_string)
        {
            len = cursor - start;

            push_token(start, len, line);
        }

        return tokens_;
    }

    void Lexer::push_token(int start, int len, int line)
    {
        char *value = (char *)malloc(len + 1);
        value[len] = '\0';
        memcpy(value, input_ + start, len);

        Token token;
        token.value = value;

        token.len = len;
        token.location = SourceLocation{
            .start = start,
            .end = start + len,
            .line = line,
        };

        if (strcmp(value, "<?") == 0) {
            token.type = TokenType_PHP_START_TAG;
        } else if (strcmp(value, "?>") == 0) {
            token.type = TokenType_PHP_CLOSE_TAG;
        } else if (strcmp(value, "require") == 0)
        {
            token.type = TokenType_REQUIRE;
        }
        else if (strcmp(value, "require_once") == 0)
        {
            token.type = TokenType_REQUIRE_ONCE;
        }
        else if (strcmp(value, "include") == 0)
        {
            token.type = TokenType_INCLUDE;
        }
        else if (strcmp(value, "include_once") == 0)
        {
            token.type = TokenType_INCLUDE_ONCE;
        }
        else if (strcmp(value, "function") == 0)
        {
            token.type = TokenType_FUNCTION;
        }
        else if (*value == '(')
        {
            token.type = TokenType_LPAREN;
        }
        else if (*value == ')')
        {
            token.type = TokenType_RPAREN;
        }
        else if (*value == '[')
        {
            token.type = TokenType_LBRACK;
        }
        else if (*value == ']')
        {
            token.type = TokenType_RBRACK;
        }
        else if (*value == '{')
        {
            token.type = TokenType_LBRACE;
        }
        else if (*value == '}')
        {
            token.type = TokenType_RBRACE;
        }
        else if (*value == '"')
        {
            token.type = TokenType_CONST_STRING;
        }
        else if (strcmp(value, "int") == 0)
        {
            token.type = TokenType_INT;
        }
        else if (strcmp(value, "string") == 0)
        {
            token.type = TokenType_STRING;
        }
        else if (strcmp(value, "if") == 0)
        {
            token.type = TokenType_IF;
        }
        else if (strcmp(value, "else") == 0)
        {
            token.type = TokenType_ELSE;
        }
        else if (strcmp(value, "elseif") == 0)
        {
            token.type = TokenType_ELSEIF;
        }
        else if (strcmp(value, "return") == 0)
        {
            token.type = TokenType_RETURN;
        }
        else if (strcmp(value, "class") == 0)
        {
            token.type = TokenType_CLASS;
        }
        else if (strcmp(value, "public") == 0)
        {
            token.type = TokenType_PUBLIC;
        }
        else if (strcmp(value, "protected") == 0)
        {
            token.type = TokenType_PROTECTED;
        }
        else if (strcmp(value, "private") == 0)
        {
            token.type = TokenType_PRIVATE;
        }
        else if (strcmp(value, "final") == 0)
        {
            token.type = TokenType_FINAL;
        }
        else if (strcmp(value, "abstract") == 0)
        {
            token.type = TokenType_ABSTRACT;
        }
        else if (strcmp(value, "extends") == 0)
        {
            token.type = TokenType_EXTENDS;
        }
        else if (strcmp(value, "implements") == 0)
        {
            token.type = TokenType_IMPLEMENTS;
        }
        else if (strcmp(value, "static") == 0)
        {
            token.type = TokenType_STATIC;
        }
        else if (strcmp(value, "array") == 0)
        {
            token.type = TokenType_ARRAY;
        }
        else if (strcmp(value, "mixed") == 0)
        {
            token.type = TokenType_MIXED;
        }
        else if (*value == '+')
        {
            token.type = TokenType_PLUS;
        }
        else if (*value == '-')
        {
            token.type = TokenType_MINUS;
        }
        else if (*value == '*')
        {
            token.type = TokenType_TIMES;
        }
        else if (*value == '/')
        {
            token.type = TokenType_SLASH;
        }
        else if (*value == '\\')
        {
            token.type = TokenType_BACKSLASH;
        }
        else if (*value == '!')
        {
            token.type = TokenType_NOT;
        }
        else if (strcmp(value, "if") == 0)
        {
            token.type = TokenType_IF;
        }
        else if (strcmp(value, "else") == 0)
        {
            token.type = TokenType_ELSE;
        }
        else if (*value == '$' && is_id(value, len))
        {
            token.type = TokenType_VAR;
        }
        else if (*value != '$' && is_id(value, len))
        {
            token.type = TokenType_ID;
        }
        else if (isdigit(*value))
        {
            token.type = TokenType_DIGIT;
        }
        else if (*value == ';')
        {
            token.type = TokenType_SEMI;
        }
        else if (*value == '\0')
        {
            token.type = TokenType_EOF;
        }
        else
        {
            token.type = TokenType_UNKN;
        }

        tokens_.push_back(token);
    }

    void Lexer::push_html_text(int start, int len)
    {
        char *value = (char *)malloc(len + 1);
        value[len] = '\0';
        memcpy(value, input_ + start, len);

        Token token;
        token.value = value;
        token.len = len;
        token.location = SourceLocation{
            .start = start,
            .end = start + len,
        };
        token.type = TokenType_HTML_TEXT;

        tokens_.push_back(token);
    }

} // namespace typhp