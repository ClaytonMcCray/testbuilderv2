cmake_minimum_required(VERSION 3.14)
project(testbuilder)
set(cmake_c_compiler clang)
set(cmake_cxx_compiler clang++)
set(cmake_cxx_standard_required ON)

set(cmake_cxx_flags_debug "-ggdb -O0")
set(cmake_cxx_flags_release "-O3")

add_executable(testbuilder testbuilder.cpp testcase.cpp main.cpp)
set_property(TARGET testbuilder PROPERTY CXX_STANDARD 17)
target_compile_options(testbuilder PRIVATE -Werror -Wall -Wextra)

