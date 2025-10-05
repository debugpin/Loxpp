#pragma once
#include "token.h"

#include <vector>
#include <string>

class Scanner {
public:
  Scanner(const std::string& source)
      : source(source), start(0), current(0), line(1) {}

  std::vector<Token> scanTokens();

private:
  char advance();
  char peek() const;
  char peekNext() const;
  bool isAtEnd() const;
  bool match(char expected);
  void skipWhitespace();
  void scanToken();

  const std::string& source;
  size_t start;
  size_t current;
  int line;
  std::vector<Token> tokens;
};
