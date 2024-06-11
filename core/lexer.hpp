#pragma once

#include <string>

enum Token {
    tok_eof = -1,

    // commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

struct Lex {
    static int getNextToken();
    static std::string IdentifierStr;
    static double NumVal;
};

// helper function.
static inline void dumpToken(int tok) {
#define STR(x) #x
// wrapper -- macro style.
#define DUMP_TOKEN_START() switch (tok) {
#define DUMP_TOKEN_END() }
#define DUMP_TOKEN(type, value) case type : {                       \
                     std::cout << "Type:" << STR(type) << "  "      \
                     << "Value:" << Lex::##value << '\n'; break; }
#define DUMP_TOKEN_RAW(type, customInfo) case type : {           \
                     std::cout << "Type:" << STR(type) << "  "      \
                     << "Value:" << customInfo << '\n'; break; }
#define DUMP_TOKEN_DEFAULT() default : { std::printf("%c\n", tok); }
    DUMP_TOKEN_START()
    DUMP_TOKEN(tok_number, NumVal)
    DUMP_TOKEN(tok_identifier, IdentifierStr)
    DUMP_TOKEN_RAW(tok_def, "def")
    DUMP_TOKEN_RAW(tok_extern, "extern")
    DUMP_TOKEN_RAW(tok_eof, "eof")
    DUMP_TOKEN_DEFAULT()
    DUMP_TOKEN_END()
}
