#include "gtest/gtest.h"

int add(int a, int b) { return a + b; }

class TestAdd : public ::testing::Test
{
    void SetUp() override
    {
        // Runs before each test
    }

    void TearDown() override
    {
        // Runs after each test
    }
};

// Don't worry about the syntax here, the TEST_F macro is very complicated.
// Just know that this is how you create a test case.
TEST_F(TestAdd, AddTest)
{
    // This should pass, 2 + 4 = 6
    EXPECT_EQ(add(2, 4), 6);
}

TEST_F(TestAdd, AddNegativeNumbers)
{
    // Create a test case here. Maybe fail this to see what happens?
    EXPECT_EQ(add(-2, -3), -5 );
}

TEST_F(TestAdd, AddWithZero)
{
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
}

TEST_F(TestAdd, FailingTest)
{
    EXPECT_EQ(add(2, 2), 4);
}

TEST_F(TestAdd, DifferentAssertations)
{
    ASSERT_EQ(add(3, 4), 7);     // Hard assertion - stops the test if it fails
    EXPECT_GT(add(5, 5), 9);     // Expects result to be greater than 9
    EXPECT_LT(add(1, 1), 3);     // Expects result to be less than 3
}

int main(int argc, char **argv)
{
    // Standard Google Test main function
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}