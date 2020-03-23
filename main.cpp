#include "testbuilder.hpp"
#include <iostream>
#include <cassert>
#include <filesystem>

int main(int argc, char **argv) {
	assert(argc > 1);

	std::string path_given = argv[1];
	std::filesystem::path path;
	if (path_given == ".") {
		path = std::filesystem::absolute(argv[1]).parent_path();
	} else {
		path = std::filesystem::path{path_given};
	}

	auto tb = TestBuilder{path};
	std::cout << tb.generate_tests() << std::endl;
	return 0;
}
