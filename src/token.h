#pragma once

#include "token_type.h"

#include <any>
#include <string>

class Token {
public:
  Token(TokenType type, std::string lexeme, std::any literal, int line)
      : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}

  TokenType getType() const { return type; }
  const std::string &getLexeme() const { return lexeme; }
  const std::any &getLiteral() const { return literal; }
  int getLine() const { return line; }

	std::string toString() const;

private:
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;
};
