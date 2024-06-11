#include <iostream>
#include <memory>

#include "lexer.hpp"
#include "parser.hpp"

#ifndef EZCC
  #error "cannot find definition. please check ezcc_global"
#endif

//#define ACTION_DUMP_TOKEN

int main() {
    int cur_tok;
    // print a tip.
    std::cout << ">";

    auto LHS = std::make_unique<VariableExprAST>("x");
    auto RHS = std::make_unique<VariableExprAST>("y");
    // std::move is necessary.
    auto result = std::make_unique<BinaryExprAST>('+', std::move(LHS), std::move(RHS));
    result->ast_dump();

#if 0
    while ((cur_tok = Lex::getNextToken()) != EOF) {
#ifdef ACTION_DUMP_TOKEN
        dumpToken(cur_tok);
#else
#endif
    }
#endif
}
