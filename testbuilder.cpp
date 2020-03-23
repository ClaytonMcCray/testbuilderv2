#include "testbuilder.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

TestBuilder::TestBuilder(const std::filesystem::path &package_directory) {
	constexpr auto go_src = ".go";
	constexpr auto test_prefix = "_test.go";

	for (const auto &de : std::filesystem::directory_iterator(package_directory)) {
		auto p = std::filesystem::path{de};
		if (p.extension() != go_src || p.string().substr(0, 4) == test_prefix) {
			continue;
		}

		this->parse_file(p);
	}

	this->whole_file << "package " << package_directory.filename().string() << std::endl;
	for (const auto &imp : this->imports) {
		this->whole_file << imp << std::endl;
	}
}


bool TestBuilder::validate(const std::string &annotation) {
	return std::all_of(std::begin(this->required_fields), std::end(this->required_fields),
			[&](auto field) { return annotation.find(field) != std::string::npos; });
}


void TestBuilder::parse_file(const std::filesystem::path &file) {
	auto f = std::ifstream{file};
	std::string line;

	while (std::getline(f, line)) {
		if (line.substr(0, 2) == "//" && this->validate(line)) {
			this->test_cases.emplace_back(line);
		}
	}
}


std::string TestBuilder::generate_tests() {
	for (auto &tc : this->test_cases) {
		this->whole_file << tc.get() << std::endl;
	}

	return this->whole_file.str();
}

