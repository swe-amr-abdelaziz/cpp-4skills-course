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

