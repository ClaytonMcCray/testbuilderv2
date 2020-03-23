#include "testbuilder.hpp"
#include <iostream>
#include <cassert>

int main(int argc, char **argv) {
	assert(argc > 1);

	std::string path = argv[1];
	auto tb = TestBuilder{path};
	std::cout << tb.generate_tests() << std::endl;
	return 0;
}
