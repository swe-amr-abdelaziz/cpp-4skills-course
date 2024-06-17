#include "variables_homework_1.h"
#include <gtest/gtest.h>
#include <sstream>
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

TEST(Problem1Test, input_even_odd_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "12 3");
    EXPECT_EQ(output,
              "12 + 3 = 15\n"
              "12 - 3 = 9\n"
              "12 / 3 = 4\n"
              "12 * 3 = 36\n");
}

TEST(Problem1Test, input_even_even_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "12 6");
    EXPECT_EQ(output,
              "12 + 6 = 18\n"
              "12 - 6 = 6\n"
              "12 / 6 = 2\n"
              "12 * 6 = 72\n");
}

TEST(Problem1Test, input_odd_odd_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "7 3");
    EXPECT_EQ(output,
              "7 + 3 = 10\n"
              "7 - 3 = 4\n"
              "7 / 3 = 2\n"
              "7 * 3 = 21\n");
}

TEST(Problem1Test, input_negative_positive_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "-12 3");
    EXPECT_EQ(output,
              "-12 + 3 = -9\n"
              "-12 - 3 = -15\n"
              "-12 / 3 = -4\n"
              "-12 * 3 = -36\n");
}

TEST(Problem1Test, input_negative_negative_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "-12 -3");
    EXPECT_EQ(output,
              "-12 + -3 = -15\n"
              "-12 - -3 = -9\n"
              "-12 / -3 = 4\n"
              "-12 * -3 = 36\n");
}

