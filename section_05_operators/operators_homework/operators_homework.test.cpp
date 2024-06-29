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

TEST(Problem2Test, guess_program_output)
{
    testing::internal::CaptureStdout();
    problem_2();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, "8\n");
}

TEST(Problem3Test, guess_program_output)
{
    testing::internal::CaptureStdout();
    problem_3();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "105\n"
              "35\n"
              "7\n"
              "1\n"
              "1\n"
              "20\n"
              "22\n"
              "22\n"
              "20\n"
              "31\n"
              "11\n"
              "22\n");
}
