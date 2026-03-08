#include "virtual_machine/Compiler.hpp"
#include "expressions/BinaryExpr.hpp"
#include "expressions/LiteralExpr.hpp"
#include "expressions/NameExpr.hpp"
#include "statements/AssignStmt.hpp"
#include "statements/LocalStmt.hpp"
#include <stdexcept>

static Value literalToValue(const Literal& lit)
{
  if (std::holds_alternative<double>(lit)) return std::get<double>(lit);
  if (std::holds_alternative<std::string>(lit)) return std::get<std::string>(lit);
  if (std::holds_alternative<bool>(lit)) return std::get<bool>(lit);
  return NilValue{};
}

Chunk Compiler::compile(const std::vector<std::unique_ptr<Stmt>>& stmts)
{
  locals.reserve(256);
  for (const auto& stmt : stmts)
  {
    compileStmt(stmt.get());
  }
  return chunk;
}

void Compiler::compileStmt(const Stmt* stmt)
{
  if (auto* s = dynamic_cast<const LocalStmt*>(stmt))
  {
    compileLocalStmt(s);
    return;
  }

  if (auto* s = dynamic_cast<const AssignStmt*>(stmt))
  {
    compileAssignStmt(s);
    return;
  }
  throw std::runtime_error("Unknown statement type");
}

void compileAssignStmt(const AssignStmt* stmt)
{
  // TODO: IMPLEMENT
  return;
}

void Compiler::compileLocalStmt(const LocalStmt* stmt)
{
  // TODO: IMPLEMENT
  return;
}
