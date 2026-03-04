#pragma once
#include "expressions/Expr.hpp"
#include "statements/Stmt.hpp"
#include "tokens/Token.hpp"
#include <memory>
#include <vector>

class ParseError : public std::runtime_error {
public:
  int line;

  ParseError(const std::string &message, int line)
      : std::runtime_error(message), line(line) {}
};

class Parser {
public:
  Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}
  std::vector<std::unique_ptr<Stmt>> parse();

private:
  std::vector<Token> tokens;
  int current = 0;

private:
  bool done();
  Token peek();
  bool check(TokenType type);
  Token advance();
  Token previous() const;
  Token consume(TokenType type, std::string message);
  bool match(std::initializer_list<TokenType> types);
  bool match(TokenType type);

  std::unique_ptr<Stmt> declaration();
  std::unique_ptr<Stmt> statement();
  std::unique_ptr<Stmt> localDeclaration();

  std::unique_ptr<Expr> expression();
  std::unique_ptr<Expr> assignment();

  std::unique_ptr<Expr> primary();
  std::unique_ptr<Expr> term();       
  std::unique_ptr<Expr> factor();     
  std::unique_ptr<Expr> unary();      

  void sync();
};
