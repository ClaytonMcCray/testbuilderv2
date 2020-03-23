#include "testcase.hpp"
#include <string>
#include <sstream>
#include <vector>

TestCase::TestCase(std::string annotation) {
	auto string_splitter = std::stringstream{annotation};
	std::string tmp;
	auto split = std::vector<std::string>{};

	constexpr auto space = ' ';

	while (std::getline(string_splitter, tmp, space)) {
		split.push_back(tmp);
	}


	this->keywords[this->func_ident_s] = split.at(1);
	auto arg_start = 0;
	if (split.at(2) == this->on_type_s) {
		this->keywords[this->on_type_s] = split.at(3);
		arg_start = 5;
	} else {
		arg_start = 3;
	}

	for (std::size_t idx = arg_start; idx < split.size(); idx++) {
		this->args[this->arg_s + std::to_string(idx)] = split.at(idx);
	}
}


static std::string wrap_parentheses(const std::string &ident, const std::string &type) {
	auto ss = std::stringstream{};
	if (type.at(0) == '*') {
		ss << "(" << ident << ")";
	} else {
		ss << "(&" << ident << ")";
	}

	return ss.str();
}


static std::string declare_variable(const std::string &type, const std::string &ident) {
	auto ss = std::stringstream{};
	if (type.at(0) == '*') {
		ss << "\t" << ident << " := new(" << type.substr(1, type.size() - 1) << ")" << std::endl;
	} else if (type.at(0) == '[') {
		ss << "\t" << ident << " := make(" << type << ",100, 100)" << std::endl;
	} else {
		ss << "\tvar " << ident << " " << type << std::endl;
	}

	return ss.str();
}


std::string TestCase::get() {
	auto tc = std::stringstream{};

	tc << "func TestFuzz" << this->keywords[this->func_ident_s] << "(t *testing.T) {" << std::endl;
	tc << "\tf := fuzz.New()" << std::endl;

	// declare and fuzz identifiers
	for (const auto& [ident, type] : this->args) {
		tc << declare_variable(type, ident);
		tc << "\tf.Fuzz" << wrap_parentheses(ident, type) << std::endl;
	}

	// if a method, declare and fuzz object
	if (this->keywords.find(on_type_s) != std::end(this->keywords)) {
		tc << declare_variable(this->keywords[on_type_s], on_type_s);
		tc << "\tf.Fuzz" <<  wrap_parentheses(on_type_s, this->keywords[on_type_s]) << std::endl;
		tc << "\t" << on_type_s << ".";
	} else {
		tc << "\t";
	}

	tc << this->keywords[func_ident_s] << "(";

	for (const auto& [ident, type] : this->args) {
		tc << ident << ",";
	}

	tc << ")" << std::endl;
	tc << "}";

	return tc.str();
}

