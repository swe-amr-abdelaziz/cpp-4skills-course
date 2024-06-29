#include "./operators_homework.h"
#include <gtest/gtest.h>
using namespace std;

TEST(Problem1Test, guess_program_output)
{
    testing::internal::CaptureStdout();
    problem_1();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "0\n"
              "2\n"
              "6 12\n"
              "9\n"
              "2\n");
}

