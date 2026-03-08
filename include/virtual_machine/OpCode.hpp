#pragma once
#include <cstdint>

enum class OpCode : uint8_t
{
  LOAD_CONST,
  MOVE,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  RETURN,
};
