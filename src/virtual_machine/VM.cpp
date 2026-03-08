#include "virtual_machine/VM.hpp"
#include "virtual_machine/Chunk.hpp"
#include <iostream>
#include <variant>

void VM::execute(const Chunk& chunk)
{
  Value registers[256] = {};
  for (const auto& instr : chunk.code)
  {
    switch (instr.op)
    {
      case OpCode::LOAD_CONST: registers[instr.a] = chunk.constants[instr.b]; break;
      case OpCode::ADD:
      {
        registers[instr.a] =
            std::get<double>(registers[instr.b]) + std::get<double>(registers[instr.c]);
        break;
      }
      case OpCode::MOVE: registers[instr.a] = registers[instr.b]; break;
      case OpCode::RETURN: return;
      default: break;
    }
  }

  for (int i = 0; i < (int)chunk.code.size(); i++)
  {
    std::visit(
        [&](auto&& val)
        {
          using T = std::decay_t<decltype(val)>;
          if constexpr (std::is_same_v<T, double>) std::cout << "r" << i << " = " << val << "\n";
          else if constexpr (std::is_same_v<T, std::string>)
            std::cout << "r" << i << " = \"" << val << "\"\n";
          else if constexpr (std::is_same_v<T, bool>)
            std::cout << "r" << i << " = " << (val ? "true" : "false") << "\n";
          else std::cout << "r" << i << " = nil\n";
        },
        registers[i]);
  }
}
