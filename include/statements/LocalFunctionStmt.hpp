#pragma once

#include "Stmt.hpp"
#include "Visitor.hpp"
#include "expressions/FunctionExpr.hpp"
#include "tokens/Token.hpp"

#include <memory>

class LocalFunctionStmt : public Stmt
{
public:
  Token name;
  std::unique_ptr<FunctionExpr> function;

  LocalFunctionStmt(Token name, std::unique_ptr<FunctionExpr> function)
      : name(std::move(name)), function(std::move(function))
  {
  }

  void accept(Visitor* v) override
  {
    v->visitLocalFunctionStmt(this);
  }
};
