#include "token.h"

#include "token_type.h"

std::string Token::toString() const {
  std::string literalStr;
  if (literal.has_value()) {
    if (literal.type() == typeid(std::string)) {
      literalStr = std::any_cast<std::string>(literal);
    } else if (literal.type() == typeid(double)) {
      literalStr = std::to_string(std::any_cast<double>(literal));
    } else if (literal.type() == typeid(bool)) {
      literalStr = std::any_cast<bool>(literal) ? "true" : "false";
    } else {
      literalStr = "unknown";
    }
  } else {
    literalStr = "nil";
  }
  return tokenTypeToString(type) + " " + lexeme + " " + literalStr;
}
