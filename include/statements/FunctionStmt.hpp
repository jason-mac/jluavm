#pragma once
#include "Stmt.hpp"
#include "expressions/FunctionExpr.hpp"
#include "tokens/Token.hpp"
#include <memory>

class FunctionStmt : public Stmt
{
public:
  Token name;
  std::unique_ptr<FunctionExpr> function;

  FunctionStmt(Token name, std::unique_ptr<FunctionExpr> function)
      : name(std::move(name)), function(std::move(function))
  {
  }
};
