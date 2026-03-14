#pragma once
#include "Visitor.hpp"

class Stmt
{
public:
  virtual ~Stmt() = default;
  virtual void accept(Visitor* v) = 0;
};
