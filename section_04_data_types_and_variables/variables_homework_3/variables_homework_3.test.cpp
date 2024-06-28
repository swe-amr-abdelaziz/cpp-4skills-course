#include "variables_homework_3.h"
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

TEST(Problem1Test, input_3_numbers_then_swap_them_1)
{
    string output = getFunctionOutput(problem_1, "115 20 301");
    EXPECT_EQ(output, "20 301 115\n");
}

TEST(Problem1Test, input_3_numbers_then_swap_them_2)
{
    string output = getFunctionOutput(problem_1, "123 456 789");
    EXPECT_EQ(output, "456 789 123\n");
}

TEST(Problem1Test, input_3_numbers_then_swap_them_3)
{
    string output = getFunctionOutput(problem_1, "123 123 456");
    EXPECT_EQ(output, "123 456 123\n");
}

TEST(Problem1Test, input_3_numbers_then_swap_them_4)
{
    string output = getFunctionOutput(problem_1, "123 123 123");
    EXPECT_EQ(output, "123 123 123\n");
}

