#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    TOKEN_KEYWORD,    // "int", "while"
    TOKEN_IDENTIFIER, // "x", "cond"
    TOKEN_OPERATOR,   // "=", "+", "-", "*", "/"
    TOKEN_NUMBER,     // "125", "5"
    TOKEN_SEMI,       // ";"
    TOKEN_EOF,        // End of Input
    TOKEN_UNKNOWN     // Brackets '{', '}', '(', ')'
};

struct Token {
    TokenType type;
    std::string value;
};

#endif