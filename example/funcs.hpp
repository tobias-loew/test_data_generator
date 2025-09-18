#pragma once


TEST_DATA_FUNC_BEGIN(foo)
inline int foo(double f, double& g, std::string) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END(foo)


TEST_DATA_FUNC_BEGIN(bar)
template<typename T>
int bar(T f, double& g, std::string) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END_NAMESPACE(bar)   // definition of bar-proxy must be after all bar-function declarations !!!


TEST_DATA_FUNC_BEGIN(bar)
inline int bar(int f, double g) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END(bar)



TEST_DATA_FUNC_BEGIN(quux)
inline int quux(double f, double& g, std::string) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END(quux)



TEST_DATA_FUNC_BEGIN(quuux)
int quuux(double f, double& g, std::string);
TEST_DATA_FUNC_END(quuux)

