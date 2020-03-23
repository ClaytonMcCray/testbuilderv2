#include "testcase.hpp"
#include <iostream>

int main() {
	std::string annotation1 = "//testbuilder: methodOne on_type *myStruct args: int int *myStruct";
	auto tc = TestCase{annotation1};
	std::cout << annotation1 << std::endl;
	std::cout << tc.get();
	std::cout << std::endl << std::endl;

	std::string annotation2 = "//testbuilder: methodTwo args: string string []int bool";
	auto tc2 = TestCase{annotation2};
	std::cout << annotation2 << std::endl;
	std::cout << tc2.get();
	std::cout << std::endl;

	return 0;
}
