#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include "tokens/Token.hpp"
#include <memory>

class LocalStmt : public Stmt {
public:
  Token name;
  std::unique_ptr<Expr> initializer;

  LocalStmt(Token n, std::unique_ptr<Expr> init) : name(std::move(n)) {
    initializer = std::move(init);
  }
};
