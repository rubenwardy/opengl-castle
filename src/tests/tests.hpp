#pragma once

#include <string>
#include <functional>
#include <map>

#define Test(name) \
	void test_##name(); \
	static void test_##name##_registered = TestRunner::Register(#name, &test_##name); \
	void test_##name()

#define COLOR_CLEAR "\033[0m"
#define COLOR_RED "\033[;31m"
#define COLOR_GREEN "\033[;32m"
#define COLOR_GREEN_BG "\033[30;42m"
#define COLOR_BLUE_BG "\033[44m"
#define COLOR_RED_BOLD "\033[1;31m"


class TestRunner {
public:
	static bool Register(const std::string &name, std::function<bool()> func);
	static bool RunTests();

private:
	static std::map<std::string, std::function<bool()>> Tests;
};
