#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "token.h"

// Forward declaration or include the header for RuntimeError
class RuntimeError;

namespace Lox {
static bool hadError = false;
static bool hadRuntimeError = false;

static int runFile(const std::string& path);
static void runPrompt();
static void run(const std::string& source);

static void report(int line, const std::string& where,
                   const std::string& message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  hadError = true;
}

static void error(int line, const std::string& message) {
  report(line, "", message);
}

static void runtimeError(const RuntimeError& error) {
  // std::cerr << error.what() << "\n[line " << error.token.line << "]"
  //           << std::endl;
  hadRuntimeError = true;
}
};  // namespace Lox
