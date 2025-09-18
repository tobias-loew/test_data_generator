#pragma once

#include <assert.h>
#include <sstream>
#include <charconv>
#include <type_traits>
#include <utility>
#include <boost/mp11.hpp>
#include <boost/core/demangle.hpp>


#ifdef TEST_DATA_GENERATE_CODE

void test_data_add_case(const char* name, std::string const& test);

#define TEST_DATA_FUNC_BEGIN(name)                                                                                                                \
namespace TEST_DATA_##name##_ns {

#define TEST_DATA_FUNC_END_NAMESPACE(name)                                                                                                        \
}

#define TEST_DATA_FUNC_END(name)                                                                                                                  \
                                                                                                                                                  \
    template<typename... Ts>                                                                                                                      \
    concept is_func_##name##_callable = requires(Ts... ts) {                                                                                      \
        name(ts...);                                                                                                                              \
    };                                                                                                                                            \
                                                                                                                                                  \
    template<typename... Ts>                                                                                                                      \
    inline constexpr bool is_##name##_callable(boost::mp11::mp_list<Ts...>) {                                                                     \
        return is_func_##name##_callable<Ts...>;                                                                                                  \
    }                                                                                                                                             \
                                                                                                                                                  \
    template<typename types, size_t ArgIndex>                                                                                                     \
    inline void handle_nth_arg_writable_ref2(std::stringstream& ss, const char* name, auto const& arg) {                                          \
        using ctypes = boost::mp11::mp_replace_at_c<                                                                                              \
            types,                                                                                                                                \
            ArgIndex,                                                                                                                             \
            std::add_lvalue_reference_t<std::add_const_t<std::remove_cvref_t<boost::mp11::mp_at_c<types, ArgIndex>>>>                             \
        >;                                                                                                                                        \
        if constexpr (!is_##name##_callable(ctypes{})) {                                                                                          \
            ss << "    type_arg_" << ArgIndex << " expected_arg_" << ArgIndex << "{" << store_arg(FORWARD_VAR(arg)) << "};\n";                    \
            ss << "    check_equal(arg_" << ArgIndex << ", expected_arg_" << ArgIndex << "); \n";                                                 \
        }                                                                                                                                         \
    }                                                                                                                                             \
                                                                                                                                                  \
    template<typename types, size_t... ArgIndizes>                                                                                                \
    inline void handle_nth_arg_writable_ref(std::stringstream& ss, const char* name, std::index_sequence<ArgIndizes...>, auto const&... args) {   \
        int dummy[] = { 0, ((void)handle_nth_arg_writable_ref2<types, ArgIndizes>(ss, name, args), 0) ... };                                      \
    }                                                                                                                                             \
}                                                                                                                                                 \
                                                                                                                                                  \
inline auto name(auto&&... args) {                                                                                                                \
                                                                                                                                                  \
    std::stringstream ss;                                                                                                                         \
    ss << "{\n";                                                                                                                                  \
    store_args(ss, __func__, std::make_index_sequence<sizeof...(args)>{}, FORWARD_VAR(args)...);                                                  \
                                                                                                                                                  \
    auto result = TEST_DATA_##name##_ns::name(FORWARD_VAR(args)...);                                                                              \
                                                                                                                                                  \
    store_expected_result(ss, __func__, result);                                                                                                  \
                                                                                                                                                  \
    store_call(ss, __func__, std::make_index_sequence<sizeof...(args)>{});                                                                        \
                                                                                                                                                  \
    using types = boost::mp11::mp_list<decltype(args)...>;                                                                                        \
    TEST_DATA_##name##_ns::handle_nth_arg_writable_ref<types>(ss, __func__, std::make_index_sequence<sizeof...(args)>{}, FORWARD_VAR(args)...);   \
                                                                                                                                                  \
    ss << "}\n\n";                                                                                                                                \
                                                                                                                                                  \
    test_data_add_case(__func__, ss.str());                                                                                                       \
    return result;                                                                                                                                \
}                                                                                                                                                 \

#else

#define TEST_DATA_FUNC_BEGIN(name)
#define TEST_DATA_FUNC_END(name)
#define TEST_DATA_FUNC_END_NAMESPACE(name)

#endif





#define FORWARD_VAR(arg)    std::forward<decltype(arg)>(arg)


inline std::string store_arg(double v) {
    std::stringstream ss;
    char buf[64] = {};
    std::to_chars(buf, buf + 63, v);
    ss << buf;
    return ss.str();
}


inline std::string store_arg(std::string const& v) {
    std::stringstream ss;
    ss << '"' << v << '"';
    return ss.str();
}


inline std::string write_type(auto const& v) {
    std::string name = boost::core::demangle(typeid(v).name());
    if (name.starts_with("struct ") || name.starts_with("class ")) {
        name.erase(0, 6);
    }
    return name;
}


inline void store_arg_gen(std::stringstream& ss, size_t index, auto const& arg) {
    ss << "    using type_arg_" << index << " = " << write_type(FORWARD_VAR(arg)) << ";\n"
        << "    type_arg_" << index
        << " arg_"
        << index
        << "{"
        << store_arg(FORWARD_VAR(arg))
        << "};\n";
}


template<size_t... ArgIndizes>
inline void store_args(std::stringstream& ss, const char* name, std::index_sequence<ArgIndizes...>, auto const&... args) {
    int dummy[] = { 0, ((void)store_arg_gen(ss, ArgIndizes, FORWARD_VAR(args)), 0) ... };
}


inline void store_call_gen(std::stringstream& ss, size_t index) {
    if (index > 0) {
        ss << ", ";
    }
    ss << "arg_" << index;
}


template<size_t... ArgIndizes>
inline void store_call(std::stringstream& ss, const char* name, std::index_sequence<ArgIndizes...>) {
    ss << "    auto result = " << name << "(";

    int dummy[] = { 0, ((void)store_call_gen(ss, ArgIndizes), 0) ... };

    ss << ");\n    check_equal(result, expected_result);\n";
}


inline void store_expected_result(std::stringstream& ss, const char* name, auto const& result) {
    ss << "    using type_expected_result = " << write_type(FORWARD_VAR(result)) << ";\n";
    ss << "    type_expected_result expected_result{" << store_arg(FORWARD_VAR(result)) << "};\n";
}

