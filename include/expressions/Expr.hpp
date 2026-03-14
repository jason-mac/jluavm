#pragma once
#include "Visitor.hpp"

class Expr
{
public:
  virtual ~Expr() = default;
  virtual Register accept(Visitor* v) = 0;
};
