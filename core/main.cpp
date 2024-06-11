#include <iostream>

#include "lexer.hpp"

#ifndef EZCC
  #error "cannot find definition. please check ezcc_global"
#endif

int main() {
    int cur_tok;
    // print a tip.
    std::cout << ">";

    while ((cur_tok = Lex::getNextToken()) != EOF) {
        dumpToken(cur_tok);
    }
}
