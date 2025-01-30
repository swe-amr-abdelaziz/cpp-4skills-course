#include "while_loops_pactice.h"
#include "climits"
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

template <typename T>
vector<T> getFunctionOutputSplitted(void (*func)(), string input, char delimiter = '\n')
{
    string output = getFunctionOutput(func, input);
    istringstream buffer(output);
    string str;
    vector<T> vec = {};
    while (getline(buffer, str, delimiter))
    {
        vec.push_back(str.c_str());
    }
    return vec;
}

TEST(Problem1Test, given_positive_number_get_numbers_divisible_by_3_test_case_1)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "12");
    vector<int> expected  = {3, 6, 9, 12};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_positive_number_get_numbers_divisible_by_3_test_case_2)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "22");
    vector<int> expected  = {3, 6, 9, 12, 15, 18, 21};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_zero_get_nothing)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "0");
    vector<int> expected  = {};
    EXPECT_EQ(output.size(), expected.size());
}

TEST(Problem1Test, given_negative_number_get_nothing)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "-20");
    vector<int> expected  = {};
    EXPECT_EQ(output.size(), expected.size());
}

