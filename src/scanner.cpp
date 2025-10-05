#include "scanner.h"
#include "token.h"

#include <variant>

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }
  tokens.emplace_back(TokenType::EOF_TYPE, "", std::monostate(), line);
  return tokens;
}
