#pragma once
#include "Stmt.hpp"
#include "tokens/Token.hpp"

class BreakStmt : public Stmt
{
public:
  Token keyword;
  BreakStmt(Token keyword) : keyword(std::move(keyword)) {}
};
