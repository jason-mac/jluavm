#pragma once

#include "Common.hpp"
#include "Expr.hpp"

class LiteralExpr : public Expr
{
public:
  Literal value;
  LiteralExpr(Literal value) : value(value) {}

  Register accept(Visitor* v) override
  {
    return v->visitLiteralExpr(this);
  }
};
