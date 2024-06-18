#include "./printing_homework.h"
#include <gtest/gtest.h>
using namespace std;

TEST(Homework1Test, guess_the_runtime_output)
{
    testing::internal::CaptureStdout();
    homework_1();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "\n\n"
              "Guess the output\n"
              "---\n"
              "25\n"
              "14/2\n"
              "7\n"
              "endl\n"
              "Practice makes perfect");
}

TEST(Homework2Test, outputs_right_triangle_stars)
{
    testing::internal::CaptureStdout();
    homework_2();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "*\n"
              "* *\n"
              "* * *\n"
              "* * * *\n"
              "* * * * *\n");
}

TEST(Homework3Test, outputs_acute_triangle_stars)
{
    testing::internal::CaptureStdout();
    homework_3();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "        *        \n"
              "      * * *      \n"
              "    * * * * *    \n"
              "  * * * * * * *  \n"
              "* * * * * * * * *\n");
}

TEST(Homework4Test, outputs_diamond_stars)
{
    testing::internal::CaptureStdout();
    homework_4();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "        *        \n"
              "      * * *      \n"
              "    * * * * *    \n"
              "  * * * * * * *  \n"
              "* * * * * * * * *\n"
              "  * * * * * * *  \n"
              "    * * * * *    \n"
              "      * * *      \n"
              "        *        \n");
}

TEST(Homework5Test, find_all_errors_and_fix_them)
{
    testing::internal::CaptureStdout();
    homework_5();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "work smart not hard\n"
              "Children must be taught how to think, not what to think\n"
              "We worry about what a child will become \" tomorrow \", yet we "
              "forget that he is someone today\n"
              "Children are not things to be molded"
              ", but are people to be unfolded\n"
              "Each day of our lives we make deposits in the memory "
              "banks of our "
              "children.\n"
              "\" It is easier to build strong children than to repair "
              "broken "
              "men \""
              "\n"
              "Children need models rather than critics\n"
              "Children have never been very good at listening to their "
              "elders, "
              "but they have never failed to imitate them"
              "Children are our most valuable resource\n");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
