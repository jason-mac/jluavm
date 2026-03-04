#pragma once

#include "Common.hpp"
#include "tokens/Token.hpp"
#include "tokens/TokenType.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Lexer {
public:
  Lexer(const std::string &source) : source(source) {}

  std::vector<Token> scanTokens();

private:
  const std::string source;
  std::vector<Token> tokens;

  size_t start = 0;
  size_t current = 0;
  int line = 1;

  static const std::unordered_map<std::string, TokenType> keywords;

  bool isAtEnd();
  void scanToken();

  void addIdentifier();
  void addNumber();
  void addString(char quote);

  bool isAlpha(Byte c);
  bool isDigit(Byte c);
  bool isAlphaNumeric(Byte c);

  char peek();
  char peekNext();
  bool match(char expected);
  char advance();

  void addToken(TokenType type);
  void addToken(TokenType type, Literal literal);
};
