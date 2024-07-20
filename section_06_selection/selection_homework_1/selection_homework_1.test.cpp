#include "selection_homework_1.h"
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

TEST(Problem1Test, given_1st_number_odd_2nd_number_odd_then_print_their_multiplication)
{
    double output = stod(getFunctionOutput(problem1, "5 7"));
    EXPECT_EQ(output, 35);
}

TEST(Problem1Test, given_1st_number_even_2nd_number_even_then_print_their_division)
{
    double output = stod(getFunctionOutput(problem1, "12 2"));
    EXPECT_EQ(output, 6);
}

TEST(Problem1Test, given_1st_number_odd_2nd_number_even_then_print_their_summation)
{
    double output = stod(getFunctionOutput(problem1, "5 6"));
    EXPECT_EQ(output, 11);
}

TEST(Problem1Test, given_1st_number_even_2nd_number_odd_then_print_their_subtraction)
{
    double output = stod(getFunctionOutput(problem1, "12 3"));
    EXPECT_EQ(output, 9);
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_1)
{
    string output = getFunctionOutput(problem2, "1 2 3");
    EXPECT_EQ(output, "1 2 3");
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_2)
{
    string output = getFunctionOutput(problem2, "1 3 2");
    EXPECT_EQ(output, "1 2 3");
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_3)
{
    string output = getFunctionOutput(problem2, "2 1 3");
    EXPECT_EQ(output, "1 2 3");
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_4)
{
    string output = getFunctionOutput(problem2, "2 3 1");
    EXPECT_EQ(output, "1 2 3");
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_5)
{
    string output = getFunctionOutput(problem2, "3 1 2");
    EXPECT_EQ(output, "1 2 3");
}

TEST(Problem2Test, given_3_integers_then_print_them_ordered_ascending_test_case_6)
{
    string output = getFunctionOutput(problem2, "3 2 1");
    EXPECT_EQ(output, "1 2 3");
}

