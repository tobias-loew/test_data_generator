#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <test_data_generator.hpp>
#include "funcs.hpp"

void check_equal(auto const& l, auto const& r) {
    BOOST_TEST(l == r);
}

#include "tests.inl"
