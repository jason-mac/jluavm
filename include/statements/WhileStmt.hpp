#pragma once
#include "Stmt.hpp"
#include "expressions/Expr.hpp"
#include <memory>

class WhileStmt : public Stmt
{

public:
  void accept(Visitor* v) override
  {
    v->visitWhileStmt(this);
  }

public:
  std::unique_ptr<Expr> condition;
  std::unique_ptr<Stmt> body;
  WhileStmt(std::unique_ptr<Expr> cond, std::unique_ptr<Stmt> body)
      : condition(std::move(cond)), body(std::move(body))
  {
  }
};
