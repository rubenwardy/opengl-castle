#include <utility>

#include <map>
#include <cassert>
#include <sstream>
#include <iostream>
#include "tests.hpp"

bool do_test(const std::string &name, const std::function<void()> &test) {
	try {
		test();

		printf("[Tests] %s%-30s :: PASSED%s\n",
				COLOR_GREEN,
				name.c_str(),
				COLOR_CLEAR);

		return true;
	} catch (TestException &e) {
		printf("%s\n", e.what());
		printf("[Tests] %s%-30s :: FAILED%s\n",
				COLOR_RED,
				name.c_str(),
				COLOR_CLEAR);
		return false;
	} catch (std::exception &e) {
		printf("%s\n", e.what());
		printf("[Tests] %s%-30s :: ERRORED%s\n",
				COLOR_RED,
				name.c_str(),
				COLOR_CLEAR);

		return false;
	}
}

std::map<std::string, std::function<void()>> TestRunner::Tests;

bool TestRunner::Register(const std::string &name, std::function<void()> func) {
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

TestException::TestException(const char *msg, const char *file, int line, const char *func) {
	std::ostringstream os;
	os << file << ":" << line << ": Failed assertion in " << func << ": " << msg;
	message = os.str();
}
