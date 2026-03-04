#include "Parser.hpp"
#include "expressions/BinaryExpr.hpp"
#include "expressions/LiteralExpr.hpp"
#include "expressions/NameExpr.hpp"
#include "expressions/UnaryExpr.hpp"
#include "statements/LocalStmt.hpp"
#include <memory>
#include <variant>

std::vector<std::unique_ptr<Stmt>> Parser::parse() {
  std::vector<std::unique_ptr<Stmt>> statements;
  while (!done()) {
    statements.push_back(declaration());
  }
  return statements;
}

std::unique_ptr<Stmt> Parser::declaration() {
  try {
    if (match(TokenType::LOCAL)) {
      return localDeclaration();
    }
    return statement();
  } catch (ParseError &error) {
    sync();
  }
  return nullptr;
}

Token Parser::previous() const { return this->tokens[current - 1]; }

Token Parser::advance() {
  if (!done()) {
    current++;
  }
  return previous();
}

bool Parser::check(TokenType type) {
  return done() ? false : peek().type == type;
}

std::unique_ptr<Stmt> Parser::statement() {
  // TODO
  return NULL;
}
std::unique_ptr<Stmt> Parser::localDeclaration() {
  Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");
  std::unique_ptr<Expr> initializer = nullptr;
  if (match(TokenType::EQUAL)) {
    initializer = expression();
  }
  return std::make_unique<LocalStmt>(name, std::move(initializer));
}
std::unique_ptr<Expr> Parser::expression() { return term(); }

Token Parser::consume(TokenType type, std::string message) {
  if (check(type)) {
    return advance();
  } else {
    throw ParseError(message, peek().line);
  }
}

bool Parser::match(std::initializer_list<TokenType> types) {
  for (TokenType type : types) {
    if (check(type)) {
      advance();
      return true;
    }
  }
  return false;
}

bool Parser::match(TokenType type) { return match({type}); }

Token Parser::peek() { return tokens[current]; }
bool Parser::done() { return peek().type == TokenType::EOF_LUA; }

std::unique_ptr<Expr> Parser::unary() {
  if (match({TokenType::NOT, TokenType::MINUS, TokenType::HASH})) {
    Token oper = previous();
    std::unique_ptr<Expr> right = unary();
    return std::make_unique<UnaryExpr>(oper, std::move(right));
  }
  return primary();
}

std::unique_ptr<Expr> Parser::primary() {
  if (match(TokenType::NUMBER)) {
    return std::make_unique<LiteralExpr>(previous().literal);
  }
  if (match(TokenType::STRING)) {
    return std::make_unique<LiteralExpr>(previous().literal);
  }
  if (match(TokenType::TRUE)) {
    return std::make_unique<LiteralExpr>(true);
  }
  if (match(TokenType::FALSE)) {
    return std::make_unique<LiteralExpr>(false);
  }
  if (match(TokenType::NIL)) {
    return std::make_unique<LiteralExpr>(std::monostate{});
  }
  if (match(TokenType::IDENTIFIER)) {
    return std::make_unique<NameExpr>(previous());
  }
  throw ParseError("Expected expression.", peek().line);
}

std::unique_ptr<Expr> Parser::factor() {
  std::unique_ptr<Expr> expr = unary();

  while (match({TokenType::SLASH, TokenType::STAR, TokenType::PERCENT})) {
    Token oper = previous();
    std::unique_ptr<Expr> right = unary();
    expr = std::make_unique<BinaryExpr>(std::move(expr), std::move(oper),
                                        std::move(right));
  }
  return expr;
}

std::unique_ptr<Expr> Parser::term() {
  std::unique_ptr<Expr> expr = factor();

  while (match({TokenType::MINUS, TokenType::PLUS})) {
    Token oper = previous();
    std::unique_ptr<Expr> right = factor();
    expr = std::make_unique<BinaryExpr>(std::move(expr), std::move(oper),
                                        std::move(right));
  }
  return expr;
}

void Parser::sync() {
  advance();

  while (!done()) {

    switch (peek().type) {
    case TokenType::LOCAL:
    case TokenType::FUNCTION:
    case TokenType::IF:
    case TokenType::WHILE:
    case TokenType::FOR:
    case TokenType::REPEAT:
    case TokenType::DO:
    case TokenType::RETURN:
    case TokenType::BREAK:
    case TokenType::END:
    case TokenType::ELSE:
    case TokenType::ELSEIF:
    case TokenType::UNTIL:
      return;
    default:
      break;
    }
    advance();
  }
}
