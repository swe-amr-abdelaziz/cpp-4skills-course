#include "logical_operators_homework.h"
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

TEST(Homework1Test, guess_program_output)
{
    testing::internal::CaptureStdout();
    homework_1();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "1\n"
              "0\n"
              "1\n"
              "0\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n"
              "0\n"
              "1\n"
              "0\n");
}

TEST(Homework2Test, create_logic_test_case_1)
{
    string output = getFunctionOutput(homework_2, "25 30 2");
    EXPECT_EQ(output,
              "0\n"
              "1\n"
              "0\n"
              "1\n"
              "1\n"
              "0\n"
              "0\n"
              "0\n");
}

TEST(Homework2Test, create_logic_test_case_2)
{
    string output = getFunctionOutput(homework_2, "45 35 4");
    EXPECT_EQ(output,
              "1\n"
              "0\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n"
              "0\n"
              "1\n");
}

TEST(Homework2Test, create_logic_test_case_3)
{
    string output = getFunctionOutput(homework_2, "30 45 6");
    EXPECT_EQ(output,
              "1\n"
              "0\n"
              "1\n"
              "1\n"
              "1\n"
              "0\n"
              "1\n"
              "1\n");
}

TEST(Homework3Test, simplify_expressions)
{
    testing::internal::CaptureStdout();
    homework_3();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "0\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n"
              "1\n");
}
