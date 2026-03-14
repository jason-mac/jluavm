#include "virtual_machine/Compiler.hpp"
#include "expressions/BinaryExpr.hpp"
#include "expressions/LiteralExpr.hpp"
#include "expressions/NameExpr.hpp"
#include "statements/AssignStmt.hpp"
#include "statements/LocalStmt.hpp"
#include <stdexcept>

Chunk Compiler::compile(const std::vector<std::unique_ptr<Stmt>>& stmts)
{
  for (const auto& stmt : stmts)
  {
    stmt->accept(this);
  }
  return chunk;
}

void Compiler::visitLocalStmt(const LocalStmt* stmt) {}
void Compiler::visitAssignStmt(const AssignStmt* stmt) {}
void Compiler::visitIfStmt(const IfStmt* stmt) {}
void Compiler::visitWhileStmt(const WhileStmt* stmt) {}
void Compiler::visitRepeatStmt(const RepeatStmt* stmt) {}
void Compiler::visitDoStmt(const DoStmt* stmt) {}
void Compiler::visitForRangeStmt(const ForRangeStmt* stmt) {}
void Compiler::visitForEachStmt(const ForEachStmt* stmt) {}
void Compiler::visitFunctionStmt(const FunctionStmt* stmt) {}
void Compiler::visitReturnStmt(const ReturnStmt* stmt) {}
void Compiler::visitBreakStmt(const BreakStmt* stmt) {}
void Compiler::visitBlockStmt(const BlockStmt* stmt) {}
void Compiler::visitExpressionStmt(const ExpressionStmt* stmt) {}

Register Compiler::visitLiteralExpr(const LiteralExpr* expr)
{
  return 0;
}
Register Compiler::visitBinaryExpr(const BinaryExpr* expr)
{
  return 0;
}
Register Compiler::visitUnaryExpr(const UnaryExpr* expr)
{
  return 0;
}
Register Compiler::visitNameExpr(const NameExpr* expr)
{
  return 0;
}
Register Compiler::visitCallExpr(const CallExpr* expr)
{
  return 0;
}
Register Compiler::visitFunctionExpr(const FunctionExpr* expr)
{
  return 0;
}
Register Compiler::visitFieldExpr(const FieldExpr* expr)
{
  return 0;
}
Register Compiler::visitIndexExpr(const IndexExpr* expr)
{
  return 0;
}
