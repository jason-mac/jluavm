#pragma once
#include "expressions/BinaryExpr.hpp"
#include "expressions/Expr.hpp"
#include "expressions/LiteralExpr.hpp"
#include "expressions/NameExpr.hpp"
#include "statements/AssignStmt.hpp"
#include "statements/LocalStmt.hpp"
#include "statements/Stmt.hpp"
#include "virtual_machine/Chunk.hpp"
#include <memory>
#include <unordered_map>
#include <vector>

class Compiler
{
public:
  Chunk compile(const std::vector<std::unique_ptr<Stmt>>& stmts);

private:
  std::unordered_map<std::string, uint8_t> locals;

private:
  Chunk chunk;
  uint8_t nextRegister = 0;

private:
  uint8_t allocRegister();
  void compileStmt(const Stmt* stmt);
  void compileExpr(const Expr* expr, uint8_t reg);
  void compileLiteralExpr(const LiteralExpr* expr, uint8_t reg);
  void compileBinaryExpr(const BinaryExpr* expr, uint8_t reg);
  void compileLocalStmt(const LocalStmt* stmt);
  void compileNameExpr(const NameExpr* expr, uint8_t reg);
  void compileAssignStmt(const AssignStmt* stmt);
  uint8_t addConstant(Value value);
  void emit(OpCode op, uint8_t a, uint8_t b, uint8_t c);
};
