BOOST_AUTO_TEST_CASE(Test_0_for__quux)
{
    using type_arg_0 = double;
    type_arg_0 arg_0{1.2349365863829878};
    using type_arg_1 = double;
    type_arg_1 arg_1{4.8};
    using type_arg_2 = char const [7];
    type_arg_2 arg_2{"jhhgjh"};
    using type_expected_result = int;
    type_expected_result expected_result{18};
    auto result = quux(arg_0, arg_1, arg_2);
    check_equal(result, expected_result);
    type_arg_1 expected_arg_1{14.399999999999999};
    check_equal(arg_1, expected_arg_1); 
}

BOOST_AUTO_TEST_CASE(Test_0_for__bar)
{
    using type_arg_0 = double;
    type_arg_0 arg_0{1.2349365863829878};
    using type_arg_1 = double;
    type_arg_1 arg_1{14.399999999999999};
    using type_arg_2 = std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >;
    type_arg_2 arg_2{"aaa"};
    using type_expected_result = int;
    type_expected_result expected_result{54};
    auto result = bar(arg_0, arg_1, arg_2);
    check_equal(result, expected_result);
    type_arg_1 expected_arg_1{43.199999999999996};
    check_equal(arg_1, expected_arg_1); 
}

BOOST_AUTO_TEST_CASE(Test_1_for__bar)
{
    using type_arg_0 = int;
    type_arg_0 arg_0{-5};
    using type_arg_1 = double;
    type_arg_1 arg_1{129.6};
    using type_expected_result = int;
    type_expected_result expected_result{-1943};
    auto result = bar(arg_0, arg_1);
    check_equal(result, expected_result);
}

BOOST_AUTO_TEST_CASE(Test_0_for__quuux)
{
    using type_arg_0 = double;
    type_arg_0 arg_0{1.2349365863829878};
    using type_arg_1 = double;
    type_arg_1 arg_1{129.6};
    using type_arg_2 = std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >;
    type_arg_2 arg_2{"ccc"};
    using type_expected_result = int;
    type_expected_result expected_result{-1152};
    auto result = quuux(arg_0, arg_1, arg_2);
    check_equal(result, expected_result);
    type_arg_1 expected_arg_1{-933.12};
    check_equal(arg_1, expected_arg_1); 
}

BOOST_AUTO_TEST_CASE(Test_0_for__foo)
{
    using type_arg_0 = double;
    type_arg_0 arg_0{1.2349365863829878};
    using type_arg_1 = double;
    type_arg_1 arg_1{43.199999999999996};
    using type_arg_2 = std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >;
    type_arg_2 arg_2{"bbb"};
    using type_expected_result = int;
    type_expected_result expected_result{161};
    auto result = foo(arg_0, arg_1, arg_2);
    check_equal(result, expected_result);
    type_arg_1 expected_arg_1{129.6};
    check_equal(arg_1, expected_arg_1); 
}

