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

TEST(Problem2Test, given_number_prints_special_multiples_1_test_case_1)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_2, "30", ' ');
    vector<int> expected = {0, 8, 12, 16, 24};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem2Test, given_number_prints_special_multiples_1_test_case_2)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_2, "100", ' ');
    vector<int> expected = {0, 8, 12, 16, 24, 32, 36, 40, 48, 56, 60, 64, 72, 80, 84, 88, 96};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem2Test, given_number_prints_special_multiples_1_test_case_3)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_2, "0", ' ');
    vector<int> expected = {0};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem3Test, given_number_prints_special_multiples_2_test_case_1)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_3, "0", ' ');
    vector<int> expected = {};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem3Test, given_number_prints_special_multiples_2_test_case_2)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_3, "1", ' ');
    vector<int> expected = {3};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem3Test, given_number_prints_special_multiples_2_test_case_3)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_3, "4", ' ');
    vector<int> expected = {3, 6, 9, 15};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem3Test, given_number_prints_special_multiples_2_test_case_4)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_3, "11", ' ');
    vector<int> expected = {3, 6, 9, 15, 18, 21, 27, 30, 33, 39, 42};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem4Test, given_numbers_prints_minimum_values_test_case_1)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_4,
                                                              "2 6 10 50 20 70 "
                                                              "30 4 3 10 5 30");
    vector<int> expected  = {4, 5};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem4Test, given_numbers_prints_minimum_values_test_case_2)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_4,
                                                              "3 6 10 50 20 70 "
                                                              "30 4 3 10 5 30 "
                                                              "1 20");
    vector<int> expected  = {4, 5, 20};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
