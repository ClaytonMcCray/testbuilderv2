#include "gtest/gtest.h"
#include "testcase.hpp"
#include <string>

TEST(TestCaseTester, GenerateAnnotations) {
	const std::string anno1 = "//testbuilder: TestFunc args: bool";
	auto generated_test = TestCase(anno1).get();
	const std::string expected = "func TestFuzzTestFunc(t *testing.T) {\n"
		"\tf := fuzz.New()\n"
		"\tvar arg3 bool\n"
		"\tf.Fuzz(&arg3)\n"
		"\tTestFunc(arg3,)\n"
		"}";

	ASSERT_EQ(generated_test, expected);
}

