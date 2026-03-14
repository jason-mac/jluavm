#pragma once
#include "Stmt.hpp"
#include <memory>

class DoStmt : public Stmt
{
public:
  std::unique_ptr<Stmt> body;

  DoStmt(std::unique_ptr<Stmt> body) : body(std::move(body)) {}
};
