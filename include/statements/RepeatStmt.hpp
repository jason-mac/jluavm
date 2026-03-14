#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include <memory>

class RepeatStmt : public Stmt
{

public:
  void accept(Visitor* v) override
  {
    v->visitRepeatStmt(this);
  }

public:
  std::unique_ptr<Stmt> body;
  std::unique_ptr<Expr> condition;

  RepeatStmt(std::unique_ptr<Stmt> body, std::unique_ptr<Expr> condition)
      : body(std::move(body)), condition(std::move(condition))
  {
  }
};
