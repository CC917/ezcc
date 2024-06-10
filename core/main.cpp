#include <iostream>

#include "lexer.hpp"

#ifndef EZCC
  #error "cannot find definition. please check ezcc_global"
#endif

int main() {
    Lex lexer;
    std::cout << lexer.getNextToken() << std::endl;
}
