#pragma once

enum class Token {
    identifier,
    constant,
    def
};

struct Lex {
    int getNextToken();
};
