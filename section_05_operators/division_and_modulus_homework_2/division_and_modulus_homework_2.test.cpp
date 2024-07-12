#include "division_and_modulus_homework_2.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>
using namespace std;

string getFunctionOutput(void (*func)(), string input)
{
    istringstream inputBuffer(input);
    streambuf* cinBuffer = cin.rdbuf(inputBuffer.rdbuf());
    testing::internal::CaptureStdout();
    func();
    cin.rdbuf(cinBuffer);
    return testing::internal::GetCapturedStdout();
}

TEST(Problem1Test, is_even_way_1_given_even_numbers_then_true)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_1, "0"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_1, "2"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_1, "4"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_1, "6"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_1, "8"));
    EXPECT_EQ(actual, 1);
}

TEST(Problem1Test, is_even_way_1_given_odd_numbers_then_false)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_1, "1"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_1, "3"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_1, "5"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_1, "7"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_1, "9"));
    EXPECT_EQ(actual, 0);
}

TEST(Problem1Test, is_even_way_2_given_even_numbers_then_true)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_2, "0"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_2, "2"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_2, "4"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_2, "6"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_2, "8"));
    EXPECT_EQ(actual, 1);
}

TEST(Problem1Test, is_even_way_2_given_odd_numbers_then_false)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_2, "1"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_2, "3"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_2, "5"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_2, "7"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_2, "9"));
    EXPECT_EQ(actual, 0);
}

TEST(Problem1Test, is_even_way_3_given_even_numbers_then_true)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_3, "0"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_3, "2"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_3, "4"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_3, "6"));
    EXPECT_EQ(actual, 1);
    actual = stoi(getFunctionOutput(problem_1_way_3, "8"));
    EXPECT_EQ(actual, 1);
}

TEST(Problem1Test, is_even_way_3_given_odd_numbers_then_false)
{
    int actual;
    actual = stoi(getFunctionOutput(problem_1_way_3, "1"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_3, "3"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_3, "5"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_3, "7"));
    EXPECT_EQ(actual, 0);
    actual = stoi(getFunctionOutput(problem_1_way_3, "9"));
    EXPECT_EQ(actual, 0);
}

