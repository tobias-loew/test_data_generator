// test_data_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

#define TEST_DATA_GENERATE_CODE

#include <fstream>
#include <test_data_generator.hpp>



#ifdef TEST_DATA_GENERATE_CODE

using function_test_set_t = std::unordered_set<std::string>;
using test_set_t = std::unordered_map<std::string, function_test_set_t>;

static test_set_t test_set;

void test_data_add_case(const char* name, std::string const& test) {
    test_set[name].insert(test);
}

#endif



#include "funcs.hpp"



int main()
{
    auto s = std::to_string(1.234936586382987654);
    double c = 1.234936586382987654;
    double d = 4.8;
    quux(c, d, "jhhgjh");
    bar(c, d, std::string{ "aaa" });
    foo(c, d, std::string{ "aaa" });
    bar(-5, d);
    quuux();


#ifdef TEST_DATA_GENERATE_CODE
    auto f = std::ofstream("../example/tests.inl");

    for (auto const& [name, func_test_set] : test_set) {
        size_t index = 0;
        for (auto const& test : func_test_set) {
            f << "BOOST_AUTO_TEST_CASE(Test_" << index << "_for__" << name << ")\n" << test;
            ++index;
        }
    }
#endif
}

