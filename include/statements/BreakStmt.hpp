#pragma once
#include "Stmt.hpp"
#include "tokens/Token.hpp"

class BreakStmt : public Stmt
{
public:
  void accept(Visitor* v) override
  {
    v->visitBreakStmt(this);
  }

public:
  Token keyword;
  BreakStmt(Token keyword) : keyword(std::move(keyword)) {}
};
