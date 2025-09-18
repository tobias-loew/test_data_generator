#pragma once


TEST_DATA_FUNC_BEGIN(foo)
int foo(double f, double& g, std::string) {
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
TEST_DATA_FUNC_END_NAMESPACE(bar)


TEST_DATA_FUNC_BEGIN(bar)
int bar(int f, double g) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END(bar)

TEST_DATA_FUNC_BEGIN(quux)
int quux(double f, double& g, std::string) {
    g *= 3;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END(quux)


TEST_DATA_FUNC_BEGIN(quuux)
int quuux() {
    return 42;
}
TEST_DATA_FUNC_END(quuux)

