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

  return EXIT_SUCCESS;
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
