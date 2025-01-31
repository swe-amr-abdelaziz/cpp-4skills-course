#include "while_loops_homework_2.h"
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
        vec.push_back(str.c_str());
    return vec;
}

TEST(Problem1Test, given_number_prints_diamond_test_case_1)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_1, "5");
    vector<string> expected = {
        "    *",
        "   ***",
        "  *****",
        " *******",
        "*********",
        "*********",
        " *******",
        "  *****",
        "   ***",
        "    *",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem1Test, given_number_prints_diamond_test_case_2)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_1, "3");
    vector<string> expected = {
        "  *",
        " ***",
        "*****",
        "*****",
        " ***",
        "  *",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem1Test, given_number_prints_diamond_test_case_3)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_1, "0");
    vector<string> expected = {};
    EXPECT_EQ(output.size(), expected.size());
}

