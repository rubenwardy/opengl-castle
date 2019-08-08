#pragma once

#include <string>
#include <functional>
#include <map>
#include <exception>

#define Test(name) \
	void test_##name(); \
	static bool test_##name##_registered = TestRunner::Register(#name, &test_##name); \
	void test_##name()

class TestException : public std::exception {
	std::string message;

public:
	TestException(const char* msg, const char* file, int line, const char *func);

	const char *what() const noexcept override { return message.c_str(); }
};

#define TAssert(cond)  if (!(cond)) { throw TestException(#cond, __FILE__, __LINE__, __func__); }

#define COLOR_CLEAR "\033[0m"
#define COLOR_RED "\033[;31m"
#define COLOR_GREEN "\033[;32m"
#define COLOR_GREEN_BG "\033[30;42m"
#define COLOR_BLUE_BG "\033[44m"
#define COLOR_RED_BOLD "\033[1;31m"


class TestRunner {
public:
	static bool Register(const std::string &name, std::function<void()> func);
	static bool RunTests();

private:
	static std::map<std::string, std::function<void()>> Tests;
};
