#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <string>
#include <map>

class TestCase {
	public:
	TestCase(std::string annotation);
	std::string get();

	private:
	enum class specifiers { func_ident, on_type };
	std::map<std::string, std::string> keywords;
};
#endif
