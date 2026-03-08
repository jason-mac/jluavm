#pragma once
#include "Chunk.hpp"
#include "Value.hpp"

class VM {
public:
  void execute(const Chunk &chunk);
};
