#include <utility>

#include <map>
#include "tests.hpp"

bool do_test(const std::string &name, const std::function<bool()> &test) {
	bool eval = test();

	printf("[Tests] %s%-30s :: %s%s",
			(eval?COLOR_GREEN:""),
			name.c_str(),
			(eval?"PASSED":"FAILED"),
			COLOR_CLEAR);

	return eval;
}

std::map<std::string, std::function<bool()>> TestRunner::Tests;

bool TestRunner::Register(const std::string &name, std::function<bool()> func) {
	auto it = Tests.find(name);
	if (it == Tests.end()) {
		Tests[name] = std::move(func);
		return true;
	}
	return false;
}

bool TestRunner::RunTests() {
	bool eval = true;
	for (const auto &method : Tests) {
		eval = do_test(method.first, method.second) && eval;
	}

	return eval;
}
