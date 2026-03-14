#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include <memory>

class ExpressionStmt : public Stmt
{
public:
  void accept(Visitor* v) override
  {
    v->visitExpressionStmt(this);
  }

public:
  std::unique_ptr<Expr> expression;

  ExpressionStmt(std::unique_ptr<Expr> expression) : expression(std::move(expression)) {}
};
