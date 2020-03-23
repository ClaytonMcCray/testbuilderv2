#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <string>
#include <map>

class TestCase {
	public:
	TestCase(std::string annotation);
	std::string get();

	private:
	const std::string on_type_s = "on_type";
	const std::string func_ident_s = "func_ident";
	const std::string arg_s = "arg";

	std::map<std::string, std::string> keywords;
	std::map<std::string, std::string> args;
};

#endif
