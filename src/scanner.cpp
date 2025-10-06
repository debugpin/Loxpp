#include "scanner.h"

#include <variant>

#include "lox.h"
#include "token.h"

using Lox::error;

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }
  tokens.emplace_back(TokenType::EOF_TYPE, "", std::monostate(), line);
  return tokens;
}

char Scanner::advance() { return source[current++]; }

char Scanner::peek() const {
  if (isAtEnd()) return '\0';
  return source[current];
}
char Scanner::peekNext() const {
  if (current + 1 >= source.length()) return '\0';
  return source[current + 1];
}

bool Scanner::isAtEnd() const { return current >= source.length(); }

bool Scanner::match(char expected) {
  if (isAtEnd()) return false;
  if (source[current] != expected) return false;
  current++;
  return true;
}

void Scanner::skipWhitespace() {
  for (;;) {
    char c = peek();
    switch (c) {
      case ' ':
      case '\r':
      case '\t':
        advance();
        break;
      case '\n':
        line++;
        advance();
        break;
      case '/':
        if (peekNext() == '/') {
          while (peek() != '\n' && !isAtEnd()) advance();
        } else {
          return;
        }
        break;
      default:
        return;
    }
  }
}

void Scanner::scanToken() {
  skipWhitespace();
  if (isAtEnd()) return;

  char c = advance();
  switch (c) {
    case '(':
      tokens.emplace_back(TokenType::LEFT_PAREN, "(", std::monostate(), line);
      break;
    case ')':
      tokens.emplace_back(TokenType::RIGHT_PAREN, ")", std::monostate(), line);
      break;
    case '{':
      tokens.emplace_back(TokenType::LEFT_BRACE, "{", std::monostate(), line);
      break;
    case '}':
      tokens.emplace_back(TokenType::RIGHT_BRACE, "}", std::monostate(), line);
      break;
    case ',':
      tokens.emplace_back(TokenType::COMMA, ",", std::monostate(), line);
      break;
    case '.':
      tokens.emplace_back(TokenType::DOT, ".", std::monostate(), line);
      break;
    case '-':
      tokens.emplace_back(TokenType::MINUS, "-", std::monostate(), line);
      break;
    case '+':
      tokens.emplace_back(TokenType::PLUS, "+", std::monostate(), line);
      break;
    case ';':
      tokens.emplace_back(TokenType::SEMICOLON, ";", std::monostate(), line);
      break;
    case '*':
      tokens.emplace_back(TokenType::STAR, "*", std::monostate(), line);
      break;
    case '!':
      tokens.emplace_back(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG,
                          match('=') ? "!=" : "!", std::monostate(), line);
      break;
    case '=':
      tokens.emplace_back(
          match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL,
          match('=') ? "==" : "=", std::monostate(), line);
      break;
    case '<':
      tokens.emplace_back(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS,
                          match('=') ? "<=" : "<", std::monostate(), line);
      break;
    case '>':
      tokens.emplace_back(
          match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER,
          match('=') ? ">=" : ">", std::monostate(), line);
      break;
    case '/':
      if (match('/')) {
        while (peek() != '\n' && !isAtEnd()) advance();
      } else {
        tokens.emplace_back(TokenType::SLASH, "/", std::monostate(), line);
      }
      break;
    case '"': {
      std::string value;
      while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        value += advance();
      }
      if (isAtEnd()) {
        // Handle unterminated string error
        return;
      }
      advance();  // closing "
      tokens.emplace_back(TokenType::STRING, value, value, line);
      break;
    }
    default:
      if (isdigit(c)) {
        std::string number(1, c);
        while (isdigit(peek())) number += advance();
        if (peek() == '.' && isdigit(peekNext())) {
          number += advance();  // consume '.'
          while (isdigit(peek())) number += advance();
        }
        tokens.emplace_back(TokenType::NUMBER, number, std::stod(number), line);
      } else if (isalpha(c) || c == '_') {
        std::string identifier(1, c);
        while (isalnum(peek()) || peek() == '_') identifier += advance();
        // For simplicity, treat all identifiers as IDENTIFIER tokens.
        tokens.emplace_back(TokenType::IDENTIFIER, identifier, std::monostate(),
                            line);
      } else {
        Lox::error(line, "Unexpected character.");
      }
      break;
  }
}
