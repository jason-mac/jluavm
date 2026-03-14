#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include "tokens/Token.hpp"
#include <memory>

class ReturnStmt : public Stmt
{

public:
  void accept(Visitor* v) override
  {
    v->visitReturnStmt(this);
  }

public:
  Token keyword;
  std::unique_ptr<Expr> value;
  ReturnStmt(Token keyword, std::unique_ptr<Expr> value)
      : keyword(std::move(keyword)), value(std::move(value))
  {
  }
};
