#pragma once
#include "expressions/Expr.hpp"
#include "statements/IfStmt.hpp"
#include "statements/Stmt.hpp"
#include "tokens/Token.hpp"
#include <memory>
#include <vector>

class ParseError : public std::runtime_error
{
public:
  int line;
  ParseError(const std::string& message, int line) : std::runtime_error(message), line(line) {}
};

class Parser
{
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
  bool match(TokenType type);
  bool match(std::initializer_list<TokenType> types);
  std::unique_ptr<Stmt> declaration();
  std::unique_ptr<Stmt> statement();
  std::unique_ptr<Stmt> localDeclaration();
  std::unique_ptr<Expr> or_();
  std::unique_ptr<Expr> and_();
  std::unique_ptr<Expr> expression();
  std::unique_ptr<Expr> equality();
  std::unique_ptr<Expr> comparison();
  std::unique_ptr<Expr> primary();
  std::unique_ptr<Expr> term();
  std::unique_ptr<Expr> factor();
  std::unique_ptr<Expr> unary();
  std::unique_ptr<Expr> call();
  std::unique_ptr<Expr> finishCall(std::unique_ptr<Expr> callee);
  std::unique_ptr<Stmt> forStatement();
  std::unique_ptr<Stmt> ifStatement();
  std::unique_ptr<IfStmt> nextIfStmt();
  std::unique_ptr<Stmt> whileStatement();
  std::unique_ptr<Stmt> expressionStatement();
  std::unique_ptr<Stmt> returnStatement();
  std::vector<std::unique_ptr<Stmt>> block();
  void sync();

  template <typename... TokenTypes> bool match(TokenTypes... tokenTypes)
  {
    return match({tokenTypes...});
  }
};
