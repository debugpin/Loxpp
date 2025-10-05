#include "token.h"

#include <string>

// Forward declaration or include the header for RuntimeError
class RuntimeError;

class Lox {
 public:
  Lox() = default;
  ~Lox() = default;

  int runFile(const std::string& path);
  void runPrompt();
  void run(const std::string& source);

 private:
  bool hadError = false;
  bool hadRuntimeError = false;

  void report(int line, const std::string& where,
               const std::string& message);
  void error(int line, const std::string& message);
  void runtimeError(const RuntimeError& error);
};
