#include "token.h"

#include "token_type.h"

std::string tokenTypeToString(TokenType type) {
  switch (type) {
    case TokenType::LEFT_PAREN:
      return "LEFT_PAREN";
    case TokenType::RIGHT_PAREN:
      return "RIGHT_PAREN";
    case TokenType::LEFT_BRACE:
      return "LEFT_BRACE";
    case TokenType::RIGHT_BRACE:
      return "RIGHT_BRACE";
    case TokenType::COMMA:
      return "COMMA";
    case TokenType::DOT:
      return "DOT";
    case TokenType::MINUS:
      return "MINUS";
    case TokenType::PLUS:
      return "PLUS";
    case TokenType::SEMICOLON:
      return "SEMICOLON";
    case TokenType::SLASH:
      return "SLASH";
    case TokenType::STAR:
      return "STAR";
    case TokenType::BANG:
      return "BANG";
    case TokenType::BANG_EQUAL:
      return "BANG_EQUAL";
    case TokenType::EQUAL:
      return "EQUAL";
    case TokenType::EQUAL_EQUAL:
      return "EQUAL_EQUAL";
    case TokenType::GREATER:
      return "GREATER";
    case TokenType::GREATER_EQUAL:
      return "GREATER_EQUAL";
    case TokenType::LESS:
      return "LESS";
    case TokenType::LESS_EQUAL:
      return "LESS_EQUAL";
    case TokenType::IDENTIFIER:
      return "IDENTIFIER";
    case TokenType::STRING:
      return "STRING";
    case TokenType::NUMBER:
      return "NUMBER";
    case TokenType::AND:
      return "AND";
    case TokenType::CLASS:
      return "CLASS";
    case TokenType::ELSE:
      return "ELSE";
    case TokenType::FALSE:
      return "FALSE";
    case TokenType::FUN:
      return "FUN";
    case TokenType::FOR:
      return "FOR";
    case TokenType::IF:
      return "IF";
    case TokenType::NIL:
      return "NIL";
    case TokenType::OR:
      return "OR";
    case TokenType::PRINT:
      return "PRINT";
    case TokenType::RETURN:
      return "RETURN";
    case TokenType::SUPER:
      return "SUPER";
    case TokenType::THIS:
      return "THIS";
    case TokenType::TRUE:
      return "TRUE";
    case TokenType::VAR:
      return "VAR";
    case TokenType::WHILE:
      return "WHILE";
    case TokenType::EOF_TYPE:
      return "EOF_TYPE";
    default:
      return "UNKNOWN";
  }
}

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
