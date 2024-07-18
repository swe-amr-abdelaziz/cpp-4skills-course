#include "selection_practice.h"
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

TEST(Problem1Test, given_two_numbers_and_addition_sign_inbetween_test_case_1)
{
    double output = stod(getFunctionOutput(problem_1, "7 + 55"));
    EXPECT_EQ(output, 62);
}

TEST(Problem1Test, given_two_numbers_and_addition_sign_inbetween_test_case_2)
{
    double output = stod(getFunctionOutput(problem_1, "0 + 55"));
    EXPECT_EQ(output, 55);
}

TEST(Problem1Test, given_two_numbers_and_addition_sign_inbetween_test_case_3)
{
    double output = stod(getFunctionOutput(problem_1, "-20 + 30"));
    EXPECT_EQ(output, 10);
}

TEST(Problem1Test, given_two_numbers_and_subtraction_sign_inbetween_test_case_1)
{
    double output = stod(getFunctionOutput(problem_1, "7 - 55"));
    EXPECT_EQ(output, -48);
}

TEST(Problem1Test, given_two_numbers_and_subtraction_sign_inbetween_test_case_2)
{
    double output = stod(getFunctionOutput(problem_1, "0 - 55"));
    EXPECT_EQ(output, -55);
}

TEST(Problem1Test, given_two_numbers_and_subtraction_sign_inbetween_test_case_3)
{
    double output = stod(getFunctionOutput(problem_1, "40 - 10"));
    EXPECT_EQ(output, 30);
}

TEST(Problem1Test, given_two_numbers_and_multiplication_sign_inbetween_test_case_1)
{
    double output = stod(getFunctionOutput(problem_1, "7 * 10"));
    EXPECT_EQ(output, 70);
}

TEST(Problem1Test, given_two_numbers_and_multiplication_sign_inbetween_test_case_2)
{
    double output = stod(getFunctionOutput(problem_1, "0 * 20"));
    EXPECT_EQ(output, 0);
}

TEST(Problem1Test, given_two_numbers_and_multiplication_sign_inbetween_test_case_3)
{
    double output = stod(getFunctionOutput(problem_1, "1 * 20"));
    EXPECT_EQ(output, 20);
}

TEST(Problem1Test, given_two_numbers_and_division_sign_inbetween_test_case_1)
{
    double output = stod(getFunctionOutput(problem_1, "70 / 10"));
    EXPECT_EQ(output, 7);
}

TEST(Problem1Test, given_two_numbers_and_division_sign_inbetween_test_case_2)
{
    double output = stod(getFunctionOutput(problem_1, "0 / 10"));
    EXPECT_EQ(output, 0);
}

TEST(Problem1Test, given_two_numbers_and_division_sign_inbetween_test_case_3)
{
    double output = stod(getFunctionOutput(problem_1, "10 / 20"));
    EXPECT_EQ(output, 0.5);
}

TEST(Problem1Test, given_two_numbers_and_invalid_sign_inbetween)
{
    string output = getFunctionOutput(problem_1, "70 % 1");
    EXPECT_EQ(output, "Invalid operation");
}

TEST(Problem2Test, given_two_numbers_then_print_minimum_test_case_1)
{
    int output = stoi(getFunctionOutput(problem_2, "10 20"));
    EXPECT_EQ(output, 10);
}

TEST(Problem2Test, given_two_numbers_then_print_minimum_test_case_2)
{
    int output = stoi(getFunctionOutput(problem_2, "70 5"));
    EXPECT_EQ(output, 5);
}

TEST(Problem2Test, given_two_numbers_then_print_minimum_test_case_3)
{
    int output = stoi(getFunctionOutput(problem_2, "20 20"));
    EXPECT_EQ(output, 20);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_1)
{
    int output = stoi(getFunctionOutput(problem_3, "10 20 30"));
    EXPECT_EQ(output, 10);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_2)
{
    int output = stoi(getFunctionOutput(problem_3, "70 5 15"));
    EXPECT_EQ(output, 5);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_3)
{
    int output = stoi(getFunctionOutput(problem_3, "30 20 15"));
    EXPECT_EQ(output, 15);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_4)
{
    int output = stoi(getFunctionOutput(problem_3, "30 10 10"));
    EXPECT_EQ(output, 10);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_5)
{
    int output = stoi(getFunctionOutput(problem_3, "10 30 30"));
    EXPECT_EQ(output, 10);
}

TEST(Problem3Test, given_three_numbers_then_print_minimum_test_case_6)
{
    int output = stoi(getFunctionOutput(problem_3, "1 1 1"));
    EXPECT_EQ(output, 1);
}

TEST(Problem4Test, given_zero_then_print_zero)
{
    int output = stoi(getFunctionOutput(problem_4, "0"));
    EXPECT_EQ(output, 0);
}

TEST(Problem4Test, given_999_then_print_99)
{
    int output = stoi(getFunctionOutput(problem_4, "999"));
    EXPECT_EQ(output, 99);
}

TEST(Problem4Test, given_1000_then_print_0)
{
    int output = stoi(getFunctionOutput(problem_4, "1000"));
    EXPECT_EQ(output, 0);
}

TEST(Problem4Test, given_1001_then_print_1)
{
    int output = stoi(getFunctionOutput(problem_4, "1001"));
    EXPECT_EQ(output, 1001);
}

TEST(Problem4Test, given_999999_then_print_9)
{
    int output = stoi(getFunctionOutput(problem_4, "999999"));
    EXPECT_EQ(output, 9999);
}

TEST(Problem4Test, given_1000000_then_print_0)
{
    int output = stoi(getFunctionOutput(problem_4, "1000000"));
    EXPECT_EQ(output, 0);
}

TEST(Problem4Test, given_1000001_then_print_minus_1000001)
{
    int output = stoi(getFunctionOutput(problem_4, "1000001"));
    EXPECT_EQ(output, -1000001);
}

TEST(Problem4Test, given_234_then_print_4)
{
    int output = stoi(getFunctionOutput(problem_4, "234"));
    EXPECT_EQ(output, 4);
}

TEST(Problem4Test, given_157_then_print_57)
{
    int output = stoi(getFunctionOutput(problem_4, "157"));
    EXPECT_EQ(output, 57);
}

TEST(Problem4Test, given_567169_then_print_7169)
{
    int output = stoi(getFunctionOutput(problem_4, "567169"));
    EXPECT_EQ(output, 7169);
}

TEST(Problem5Test, given_zero_then_print_small_number_msg)
{
    string output = getFunctionOutput(problem_5, "0");
    EXPECT_EQ(output, "this is a small number");
}

TEST(Problem5Test, given_9999_then_print_small_number_msg)
{
    string output = getFunctionOutput(problem_5, "9999");
    EXPECT_EQ(output, "this is a small number");
}

TEST(Problem5Test, given_10001_then_print_great_number_msg)
{
    string output = getFunctionOutput(problem_5, "10001");
    EXPECT_EQ(output, "this is a great number");
}

TEST(Problem5Test, given_10011_then_print_good_number_msg)
{
    string output = getFunctionOutput(problem_5, "10011");
    EXPECT_EQ(output, "this is a good number");
}

TEST(Problem5Test, given_10000_then_print_bad_number_msg)
{
    string output = getFunctionOutput(problem_5, "10000");
    EXPECT_EQ(output, "this is a bad number");
}

TEST(Problem5Test, given_100_then_print_small_number_msg)
{
    string output = getFunctionOutput(problem_5, "100");
    EXPECT_EQ(output, "this is a small number");
}

TEST(Problem5Test, given_10111_then_print_great_number_msg)
{
    string output = getFunctionOutput(problem_5, "10111");
    EXPECT_EQ(output, "this is a great number");
}

TEST(Problem5Test, given_10330_then_print_good_number_msg)
{
    string output = getFunctionOutput(problem_5, "10330");
    EXPECT_EQ(output, "this is a good number");
}

TEST(Problem5Test, given_10303_then_print_good_number_msg)
{
    string output = getFunctionOutput(problem_5, "10303");
    EXPECT_EQ(output, "this is a good number");
}

TEST(Problem5Test, given_10033_then_print_good_number_msg)
{
    string output = getFunctionOutput(problem_5, "10033");
    EXPECT_EQ(output, "this is a good number");
}