#include "division_and_modulus_homework_1.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>
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

void runProblem1Tests(string input, vector<double> expected)
{
    string output = getFunctionOutput(problem_1, input);
    istringstream buffer(output);
    string str;
    vector<double> actual = {};
    while (getline(buffer, str, '\n'))
    {
        actual.push_back(stod(str.c_str()));
    }
    EXPECT_DOUBLE_EQ(actual[0], expected[0]);
    EXPECT_DOUBLE_EQ(actual[1], expected[1]);
    EXPECT_DOUBLE_EQ(actual[2], expected[2]);
}

TEST(Problem1Test, averages_test_case_1)
{
    runProblem1Tests("1 2 3 4 5", {3, 0.666667, 0.444444});
}

TEST(Problem1Test, averages_test_case_2)
{
    runProblem1Tests("5 4 3 2 1", {3, 4, 2.66667});
}

TEST(Problem1Test, averages_test_case_3)
{
    runProblem1Tests("6 20 4 8 2", {8, 3, 2});
}

TEST(Problem1Test, averages_test_case_4)
{
    runProblem1Tests("0 20 4 8 2", {6.8, 2.4, 1.6});
}

