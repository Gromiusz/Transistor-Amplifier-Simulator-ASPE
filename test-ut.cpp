#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "header_lib/electronics_elements.hpp"

TEST(Basic, Basic1) {
    EXPECT_EQ(1, 1);
}

TEST(Resistor, Resistor1)
{
    MatrixXd left(3,3);
    MatrixXd right(3,1);
    MatrixXd variable(3,1);

    Resistor res(10);
    res.insert(left, variable, right, 1, 2);

    EXPECT_EQ(left(1,1), 0.1);
    EXPECT_EQ(left(1,2), -0.1);
    EXPECT_EQ(left(2,1), -0.1);
    EXPECT_EQ(left(2,2), 0.1);
}

TEST(CurrentSource, CurrentSource1)
{
    MatrixXd left(3,3);
    MatrixXd right(3,1);
    MatrixXd variable(3,1);

    CurrentSource cs(1);
    cs.insert(left, variable, right, 1, 2);

    EXPECT_EQ(right(1,1), -1);
    EXPECT_EQ(right(1,2), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}