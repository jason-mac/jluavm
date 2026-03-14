#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include "tokens/Token.hpp"
#include <memory>

class LocalStmt : public Stmt
{
public:
  void accept(Visitor* v) override
  {
    v->visitLocalStmt(this);
  }

public:
  Token name;
  std::unique_ptr<Expr> value;

  LocalStmt(Token name, std::unique_ptr<Expr> value)
      : name(std::move(name)), value(std::move(value))
  {
  }
};
