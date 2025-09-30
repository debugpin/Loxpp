#include "lox.h"

#include <iostream>

void Lox::runFile(const std::string& path) {
  // Implementation for running a file
}

void Lox::runPrompt() {
  // Implementation for running the prompt
}
void Lox::run(const std::string& source) {
  // Implementation for running source code
}

int main(int argc, const char* argv[]) {
  if (argc > 2) {
    std::cout << "Usage: lox [script]" << std::endl;
    return 64;
  } else if (argc == 2) {
    Lox::runFile(argv[1]);
  } else {
    Lox::runPrompt();
  }

  return 0;
}