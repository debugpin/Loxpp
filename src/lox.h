#include <string>

// Forward declaration or include the header for RuntimeError
class RuntimeError;

class Lox {
 public:
  static void runFile(const std::string& path);
  static void runPrompt();
	static void run(const std::string& source);

 private:
	static bool hadError;
	static bool hadRuntimeError;

	static void report(int line, const std::string& where,
										 const std::string& message);
	static void error(int line, const std::string& message);
	static void runtimeError(const RuntimeError& error);
};