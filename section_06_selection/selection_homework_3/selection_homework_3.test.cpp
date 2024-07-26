#include "selection_homework_3.h"
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

TEST(Problem1Test, given_three_intervals_with_no_intersection)
{
    int output = stoi(getFunctionOutput(problem1, "10 100 200 100 101 120 170"));
    EXPECT_EQ(output, 0);
}

TEST(Problem1Test, given_three_intervals_with_one_interval_intersection_in_middle)
{
    int output = stoi(getFunctionOutput(problem1, "10 5 15 100 101 120 170"));
    EXPECT_EQ(output, 1);
}

TEST(Problem1Test, given_three_intervals_with_one_interval_intersection_in_edge)
{
    int output = stoi(getFunctionOutput(problem1, "10 10 15 100 101 120 170"));
    EXPECT_EQ(output, 1);
}

TEST(Problem1Test, given_three_intervals_with_two_interval_intersection_in_middle)
{
    int output = stoi(getFunctionOutput(problem1, "7 1 10 5 6 4 40"));
    EXPECT_EQ(output, 2);
}

TEST(Problem1Test, given_three_intervals_with_two_interval_intersection_in_edge)
{
    int output = stoi(getFunctionOutput(problem1, "7 1 7 5 6 7 40"));
    EXPECT_EQ(output, 2);
}

TEST(Problem1Test, given_three_intervals_with_three_interval_intersection_in_middle)
{
    int output = stoi(getFunctionOutput(problem1, "10 5 15 6 100 3 30"));
    EXPECT_EQ(output, 3);
}

TEST(Problem1Test, given_three_intervals_with_three_interval_intersection_in_edge)
{
    int output = stoi(getFunctionOutput(problem1, "10 10 15 6 10 10 30"));
    EXPECT_EQ(output, 3);
}

TEST(Problem1Test, given_three_intervals_with_three_interval_intersection_as_points)
{
    int output = stoi(getFunctionOutput(problem1, "1 1 1 1 1 1 1"));
    EXPECT_EQ(output, 3);
}

TEST(Problem2Test, two_intervals_no_intersection)
{
    int output = stoi(getFunctionOutput(problem2, "1 15 20 30"));
    EXPECT_EQ(output, -1);
}

TEST(Problem2Test, two_intervals_no_intersection_reversed)
{
    int output = stoi(getFunctionOutput(problem2, "20 30 1 15"));
    EXPECT_EQ(output, -1);
}

TEST(Problem2Test, two_intervals_full_intersection_test_case_1)
{
    string output = getFunctionOutput(problem2, "1 6 1 6");
    EXPECT_EQ(output, "1 6");
}

TEST(Problem2Test, two_intervals_full_intersection_test_case_2)
{
    string output = getFunctionOutput(problem2, "1 6 1 3");
    EXPECT_EQ(output, "1 3");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_1)
{
    string output = getFunctionOutput(problem2, "1 6 3 8");
    EXPECT_EQ(output, "3 6");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_2)
{
    string output = getFunctionOutput(problem2, "1 6 6 8");
    EXPECT_EQ(output, "6 6");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_3)
{
    string output = getFunctionOutput(problem2, "3 8 1 6");
    EXPECT_EQ(output, "3 6");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_4)
{
    string output = getFunctionOutput(problem2, "1 6 2 3");
    EXPECT_EQ(output, "2 3");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_5)
{
    string output = getFunctionOutput(problem2, "-20 -10 -15 0");
    EXPECT_EQ(output, "-15 -10");
}

TEST(Problem2Test, two_intervals_with_intersection_test_case_6)
{
    string output = getFunctionOutput(problem2, "1 1 1 1");
    EXPECT_EQ(output, "1 1");
}