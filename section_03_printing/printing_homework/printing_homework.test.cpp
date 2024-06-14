#include "./printing_homework.h"
#include <gtest/gtest.h>
using namespace std;

TEST(Homework2Test, outputs_right_triangle_stars)
{
    testing::internal::CaptureStdout();
    homework_2();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result, "*\n* *\n* * *\n* * * *\n* * * * *\n");
}

TEST(Homework3Test, outputs_acute_triangle_stars)
{
    testing::internal::CaptureStdout();
    homework_3();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "        *        \n      * * *      \n    * * * * *    \n "
              " * * * * * * *  \n* * * * * * * * *\n");
}

TEST(Homework4Test, outputs_diamond_stars)
{
    testing::internal::CaptureStdout();
    homework_4();
    string result = testing::internal::GetCapturedStdout();
    EXPECT_EQ(result,
              "        *        \n      * * *      \n    * * * * *    \n "
              " * * * * * * *  \n* * * * * * * * *\n  * * * * * * *  \n    * * "
              "* * *    "
              "\n      * * *      \n        *        \n");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
