#pragma once
#include "OpCode.hpp"
#include <cstdint>

struct Instruction
{
  OpCode op;
  uint8_t a;
  uint8_t b;
  uint8_t c;
};
