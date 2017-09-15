#include <gtest/gtest.h>
#include "../src/functionaudi.h"
//#include "../src/Expression_tree.h"


TEST(BasicFunctionTest, BasicScalar) {
    defineid(x);
    ASSERT_EQ((x*2+1).value(1), 3);
    ASSERT_EQ((((x-2)/4).value(1)), -0.25);
    ASSERT_EQ((x*2+1).der(1), 2);
    ASSERT_EQ((((x-2)/4).der(1)), 0.25);
}
TEST(BasicFunctionTest, BasicComputation) {
    defineid(x);
    ASSERT_EQ((x*2+x*3).value(2), 10);
    ASSERT_EQ(((x/2 -x/4).value(4)), 1);
    ASSERT_EQ(((x/2) *(x*2)).value(4), 16);
    ASSERT_EQ((x^x).value(1), 1);
    ASSERT_EQ((x*2+x*3).der(2), 5);
    ASSERT_EQ(((x/2 -x/4).der(4)), 0.25);
    ASSERT_EQ(((x/2) *(x*2)).der(4), 8);
    //ASSERT_EQ((x^x).der(1), std::exp(1));
}
TEST(BasicFunctionTest, BasicFunction) {
    defineid(x);
    ASSERT_EQ((x*2+1).value(1), 3);
    ASSERT_EQ((((x-2)/4).value(1)), -0.25);
    ASSERT_EQ((x*2+1).der(1), 2);
    ASSERT_EQ((((x-2)/4).der(1)), 0.25);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
