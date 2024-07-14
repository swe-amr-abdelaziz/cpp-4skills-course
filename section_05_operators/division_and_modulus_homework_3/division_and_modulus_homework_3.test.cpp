#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>
#include "division_and_modulus_homework_3.h"
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

template<typename T>
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

TEST(Problem1Test, _100_or_7_given_even_number_then_print_100)
{
    int actual = stoi(getFunctionOutput(problem_1, "8"));
    EXPECT_EQ(actual, 100);
}

TEST(Problem1Test, _100_or_7_given_odd_number_then_print_7)
{
    int actual = stoi(getFunctionOutput(problem_1, "133"));
    EXPECT_EQ(actual, 7);
}

