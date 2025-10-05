#include "lox.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

int Lox::runFile(const std::string& path) {
  std::ifstream file(path);

  if (!file) {
    std::cerr << "Could not open file: " << path << std::endl;
    return EXIT_FAILURE;
  }

  std::string source((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
  run(source);
  if (hadError || hadRuntimeError) return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

void Lox::runPrompt() {
  std::string line;

  for (;;) {
    std::cout << "> ";
    if (!std::getline(std::cin, line) || line.empty()) break;
    run(line);
    hadError = false;
  }
}

void Lox::run(const std::string& source) {
  Scanner scanner = new Scanner(source);
  std::vector<Token> tokens = scanner.scanTokens();

  // For now, just print the tokens
  for (const Token& token : tokens) {
    std::cout << token.toString() << std::endl;
  }
}

void Lox::report(int line, const std::string& where,
                 const std::string& message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  hadError = true;
}

void error(int line, const std::string& message) { report(line, "", message); }

void Lox::runtimeError(const RuntimeError& error) {
  std::cerr << error.what() << "\n[line " << error.token.line << "]"
            << std::endl;
  hadRuntimeError = true;
}

int main(int argc, const char* argv[]) {
  if (argc > 2) {
    std::cout << "Usage: lox [script]" << std::endl;
    return EXIT_FAILURE;
  } else if (argc == 2) {
    Lox::runFile(argv[1]);
  } else {
    Lox::runPrompt();
  }

  return EXIT_SUCCESS;
}
