#include "selection_homework_2.h"
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

TEST(Problem1Test, given_10_numbers_then_print_max_number_test_case_1)
{
    int output =
        stoi(getFunctionOutput(problem1, "1 67 -9 88 -45 129 90 65 77 34"));
    EXPECT_EQ(output, 129);
}

TEST(Problem1Test, given_10_numbers_then_print_max_number_test_case_2)
{
    int output = stoi(getFunctionOutput(problem1, "1 2 3 4 5 6 7 8 9 10"));
    EXPECT_EQ(output, 10);
}

