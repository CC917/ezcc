#pragma once

#include <iostream>
#include <string>
#include <memory>

// AST expression base class.
struct ExprAST {
    virtual ~ExprAST() = default;
    virtual void ast_dump() { }
};

// a simple number value.
struct NumberExprAST : public ExprAST {
    double Val;
    NumberExprAST(double Val) : Val(Val) {}
    void ast_dump() override { std::cout << Val;  }
};

// a variablle name.
struct VariableExprAST : public ExprAST {
    std::string Name;
    VariableExprAST(const std::string &Name) : Name(Name) {}
    void ast_dump() override { std::cout << Name; }
};

// Expression class for a binary operator.
struct BinaryExprAST : public ExprAST {
    char Op;
    std::unique_ptr<ExprAST> LHS, RHS; // left/right hand side.

    BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
        std::unique_ptr<ExprAST> RHS)
        : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

    void ast_dump() override {
        LHS->ast_dump();
        std::cout << " " << Op << " ";
        RHS->ast_dump();
        std::cout << std::endl;
    }
};

struct parser {

};
