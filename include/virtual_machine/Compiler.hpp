#pragma once
#include "expressions/BinaryExpr.hpp"
#include "expressions/CallExpr.hpp"
#include "expressions/Expr.hpp"
#include "expressions/FieldExpr.hpp"
#include "expressions/FunctionExpr.hpp"
#include "expressions/IndexExpr.hpp"
#include "expressions/LiteralExpr.hpp"
#include "expressions/NameExpr.hpp"
#include "expressions/UnaryExpr.hpp"
#include "statements/AssignStmt.hpp"
#include "statements/BlockStmt.hpp"
#include "statements/BreakStmt.hpp"
#include "statements/DoStmt.hpp"
#include "statements/ExpressionStmt.hpp"
#include "statements/ForEachStmt.hpp"
#include "statements/ForRangeStmt.hpp"
#include "statements/FunctionStmt.hpp"
#include "statements/IfStmt.hpp"
#include "statements/LocalStmt.hpp"
#include "statements/RepeatStmt.hpp"
#include "statements/ReturnStmt.hpp"
#include "statements/Stmt.hpp"
#include "statements/WhileStmt.hpp"
#include "virtual_machine/Chunk.hpp"

#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class CompileError : public std::runtime_error
{
public:
  CompileError(const std::string& message) : std::runtime_error(message) {}
};

class Compiler : public Visitor
{
public:
  Chunk compile(const std::vector<std::unique_ptr<Stmt>>& stmts);

private:
  Chunk chunk;
  uint8_t nextRegister = 0;
  std::unordered_map<std::string, uint8_t> locals;

private:
  // statements
  void visitLocalStmt(const LocalStmt* stmt) override;
  void visitAssignStmt(const AssignStmt* stmt) override;
  void visitIfStmt(const IfStmt* stmt) override;
  void visitWhileStmt(const WhileStmt* stmt) override;
  void visitRepeatStmt(const RepeatStmt* stmt) override;
  void visitDoStmt(const DoStmt* stmt) override;
  void visitForRangeStmt(const ForRangeStmt* stmt) override;
  void visitForEachStmt(const ForEachStmt* stmt) override;
  void visitFunctionStmt(const FunctionStmt* stmt) override;
  void visitReturnStmt(const ReturnStmt* stmt) override;
  void visitBreakStmt(const BreakStmt* stmt) override;
  void visitBlockStmt(const BlockStmt* stmt) override;
  void visitExpressionStmt(const ExpressionStmt* stmt) override;

  // expressions
  Register visitLiteralExpr(const LiteralExpr* expr) override;
  Register visitBinaryExpr(const BinaryExpr* expr) override;
  Register visitUnaryExpr(const UnaryExpr* expr) override;
  Register visitNameExpr(const NameExpr* expr) override;
  Register visitCallExpr(const CallExpr* expr) override;
  Register visitFunctionExpr(const FunctionExpr* expr) override;
  Register visitFieldExpr(const FieldExpr* expr) override;
  Register visitIndexExpr(const IndexExpr* expr) override;

  // helpers
  Register allocRegister();
  uint8_t addConstant(Value value);
  void emit(OpCode op, Register a, Register b, Register c);
};
