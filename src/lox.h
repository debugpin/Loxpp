#pragma once

#include <string>

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
                   const std::string& message);
static void error(int line, const std::string& message);
static void runtimeError(const RuntimeError& error);
};  // namespace Lox
