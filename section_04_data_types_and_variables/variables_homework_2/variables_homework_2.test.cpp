#include "variables_homework_2.h"
#include <gtest/gtest.h>
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

TEST(Problem1Test, guess_the_output)
{
    testing::internal::CaptureStdout();
    problem_1();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "1\n"
              "2\n"
              "3\n"
              "5\n"
              "8\n"
              "13\n"
              "21\n"
              "34\n"
              "55\n");
}

