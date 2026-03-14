#pragma once
#include "Expr.hpp"
#include "tokens/Token.hpp"
#include <memory>

class UnaryExpr : public Expr
{
public:
  Token operator_;
  std::unique_ptr<Expr> rightOperand;
  UnaryExpr(Token o, std::unique_ptr<Expr> r) : operator_(std::move(o)), rightOperand(std::move(r))
  {
  }

  Register accept(Visitor* v) override
  {
    return v->visitUnaryExpr(this);
  }
};
