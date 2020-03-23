#ifndef TEST_BUILDER_HPP
#define TEST_BUILDER_HPP

#include "testcase.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <array>

class TestBuilder {
	private:
	std::vector<TestCase> test_cases;
	std::stringstream whole_file;
	std::vector<std::string> imports = {"import \"testing\"", "import \"github.com/google/gofuzz\""};
	bool validate(const std::string &annotation);
	void parse_file(const std::filesystem::path &file);
	const std::array<std::string, 2> required_fields = {"//testbuilder:", "args:"};

	public:
	TestBuilder(const std::filesystem::path &package_directory);
	std::string generate_tests();
};
#endif
