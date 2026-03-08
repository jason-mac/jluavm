#pragma once
#include "Instruction.hpp"
#include "Value.hpp"
#include <vector>

struct Chunk
{
  std::vector<Instruction> code;
  std::vector<Value> constants;
};
