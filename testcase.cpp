#include "testcase.hpp"
#include <string>
#include <sstream>
#include <vector>


TestCase::TestCase(std::string annotation) {
	auto string_splitter = std::stringstream{annotation};
	std::string tmp;

	constexpr auto space = ' ';

	while (std::getline(string_splitter, tmp, space)) {
		this->split.push_back(tmp);
	}
}


std::string TestCase::get() {
}

