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

TEST(Problem3Test, given_3_integers_all_less_than_100_then_print_max_among_all)
{
    int output = stoi(getFunctionOutput(problem3, "10 30 20"));
    EXPECT_EQ(output, 30);
}

TEST(Problem3Test, given_3_integers_2_of_them_less_than_100_then_print_max_among_2_integers)
{
    int output = stoi(getFunctionOutput(problem3, "22 90 115"));
    EXPECT_EQ(output, 90);
}

TEST(Problem3Test, given_3_integers_1_of_them_less_than_100_then_print_that_integer)
{
    int output = stoi(getFunctionOutput(problem3, "50 100 150"));
    EXPECT_EQ(output, 50);
}

TEST(Problem3Test, given_3_integers_no_one_is_less_than_100_then_print_minus_1)
{
    int output = stoi(getFunctionOutput(problem3, "200 300 400"));
    EXPECT_EQ(output, -1);
}

TEST(Problem3Test, given_3_negative_integers_than_print_max_among_all)
{
    int output = stoi(getFunctionOutput(problem3, "-10 -30 -20"));
    EXPECT_EQ(output, -10);
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_1)
{
    string output = getFunctionOutput(problem4, "10 1 2 3 4 5");
    EXPECT_EQ(output, "5 0");
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_2)
{
    string output = getFunctionOutput(problem4, "10 300 2 3 4 5");
    EXPECT_EQ(output, "4 1");
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_3)
{
    string output = getFunctionOutput(problem4, "10 300 2 3 4 200");
    EXPECT_EQ(output, "3 2");
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_4)
{
    string output = getFunctionOutput(problem4, "10 300 1 5 100 200");
    EXPECT_EQ(output, "2 3");
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_5)
{
    string output = getFunctionOutput(problem4, "10 300 10 50 100 200");
    EXPECT_EQ(output, "1 4");
}

TEST(Problem4Test, given_x_and_5_numbers_then_print_2_values_test_case_6)
{
    string output = getFunctionOutput(problem4, "10 300 100 50 100 200");
    EXPECT_EQ(output, "0 5");
}