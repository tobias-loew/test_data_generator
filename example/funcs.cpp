
#include <test_data_generator.hpp>
#include "funcs.hpp"


TEST_DATA_FUNC_BEGIN(quuux)
int quuux(double f, double& g, std::string) {
    g *= -7.2;
    return (int)std::ceil(f * g);
}
TEST_DATA_FUNC_END_NAMESPACE(quuux)
