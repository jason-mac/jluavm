#include "Common.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

int main(int argc, char **argv) {
  if (argc == 1) {
    // pass
  } else if (argc == 2) {
    // pass
  } else {
    // pass
  }
  std::string file_path = "./lua/test_one.lua";
  std::ifstream lua_file(file_path, std::ios::binary | std::ios::ate);
  std::streamsize size = lua_file.tellg();
  lua_file.seekg(0, std::ios::beg);
  if (!lua_file) {
    return EXIT_FAILURE;
  }

  std::vector<Byte> memory(4096);
  std::cout << (memory.size()) << std::endl;
  std::vector<Byte> buffer(size);
  lua_file.read(reinterpret_cast<char *>(buffer.data()), size);
  for (Byte byte : buffer) {
    std::cout << byte;
  }
  return 0;
}
