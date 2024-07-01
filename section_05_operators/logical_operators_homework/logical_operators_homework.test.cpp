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

