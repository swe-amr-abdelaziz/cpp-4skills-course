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

TEST(Problem2Test, given_two_numbers_get_power_function_result_test_case_1)
{
    int output = stoi(getFunctionOutput(problem_2, "2 5"));
    EXPECT_EQ(output, 32);
}

TEST(Problem2Test, given_two_numbers_get_power_function_result_test_case_2)
{
    int output = stoi(getFunctionOutput(problem_2, "5 3"));
    EXPECT_EQ(output, 125);
}

TEST(Problem2Test, given_two_numbers_get_power_function_result_test_case_3)
{
    int output = stoi(getFunctionOutput(problem_2, "100 1"));
    EXPECT_EQ(output, 100);
}

TEST(Problem2Test, given_two_numbers_get_power_function_result_test_case_4)
{
    int output = stoi(getFunctionOutput(problem_2, "100 0"));
    EXPECT_EQ(output, 1);
}

TEST(Problem3Test, given_number_get_its_number_of_digits_test_case_1)
{
    int output = stoi(getFunctionOutput(problem_3, "123"));
    EXPECT_EQ(output, 3);
}

TEST(Problem3Test, given_number_get_its_number_of_digits_test_case_2)
{
    int output = stoi(getFunctionOutput(problem_3, "0"));
    EXPECT_EQ(output, 1);
}

TEST(Problem3Test, given_number_get_its_number_of_digits_test_case_3)
{
    int output = stoi(getFunctionOutput(problem_3, "-12345"));
    EXPECT_EQ(output, 5);
}

TEST(Problem3Test, given_number_get_its_number_of_digits_test_case_4)
{
    int output = stoi(getFunctionOutput(problem_3, to_string(INT_MIN)));
    EXPECT_EQ(output, 10);
}

TEST(Problem4Test, given_t_test_cases_and_number_for_each_test_case_1)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_4, "3 3 4 5");
    vector<string> expected = {
        "Sum from 1 to 3 = 6",
        "Sum from 1 to 4 = 10",
        "Sum from 1 to 5 = 15",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem4Test, given_t_test_cases_and_number_for_each_test_case_2)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_4, "4 1 10 100 1000");
    vector<string> expected = {
        "Sum from 1 to 1 = 1",
        "Sum from 1 to 10 = 55",
        "Sum from 1 to 100 = 5050",
        "Sum from 1 to 1000 = 500500",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
