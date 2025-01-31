#include "while_loops_homework_1.h"
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

TEST(Problem1Test, given_two_positive_numbers_sorted_ascending_print_range_in_between)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "3 7");
    vector<int> expected  = {3, 4, 5, 6, 7};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_two_positive_numbers_sorted_descending_print_range_in_between)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "6 1");
    vector<int> expected  = {6, 5, 4, 3, 2, 1};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_two_negative_numbers_sorted_ascending_print_range_in_between)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_1, "-20 -17");
    vector<int> expected = {-20, -19, -18, -17};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_two_negative_numbers_sorted_descending_print_range_in_between)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_1, "-4 -12");
    vector<int> expected = {-4, -5, -6, -7, -8, -9, -10, -11, -12};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_positive_and_negative_sorted_ascending_print_range_in_between)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_1, " -2 3 ");
    vector<int> expected = {-2, -1, 0, 1, 2, 3};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_positive_and_negative_sorted_descending_print_range_in_between)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_1, " 4 -2 ");
    vector<int> expected = {4, 3, 2, 1, 0, -1, -2};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem1Test, given_two_equal_numbers_print_any_of_them)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_1, "5 5");
    vector<int> expected  = {5};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stoi(output[i]), expected[i]);
}

TEST(Problem2Test, given_number_and_character_prints_the_character_n_times_test_case_1)
{
    string output   = getFunctionOutput(problem_2, "5 Y");
    string expected = "YYYYY";
    EXPECT_EQ(output, expected);
}

TEST(Problem2Test, given_number_and_character_prints_the_character_n_times_test_case_2)
{
    string output   = getFunctionOutput(problem_2, "3 #");
    string expected = "###";
    EXPECT_EQ(output, expected);
}

TEST(Problem2Test, given_number_and_character_prints_the_character_n_times_test_case_3)
{
    string output   = getFunctionOutput(problem_2, "7 7");
    string expected = "7777777";
    EXPECT_EQ(output, expected);
}

TEST(Problem2Test, given_number_and_character_prints_the_character_n_times_test_case_4)
{
    string output   = getFunctionOutput(problem_2, "0 #");
    string expected = "";
    EXPECT_EQ(output, expected);
}

TEST(Problem3Test, given_number_prints_left_angled_triangle_test_case_1)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_3, "5");
    vector<string> expected = {
        "*",
        "**",
        "***",
        "****",
        "*****",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem3Test, given_number_prints_left_angled_triangle_test_case_2)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_3, "1");
    vector<string> expected = {"*"};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem3Test, given_number_prints_left_angled_triangle_test_case_3)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_3, "0");
    vector<string> expected = {};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem4Test, given_number_prints_face_down_left_angled_triangle_test_case_1)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_4, "6");
    vector<string> expected = {
        "******",
        "*****",
        "****",
        "***",
        "**",
        "*",
    };
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem4Test, given_number_prints_face_down_left_angled_triangle_test_case_2)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_4, "1");
    vector<string> expected = {"*"};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem4Test, given_number_prints_face_down_left_angled_triangle_test_case_3)
{
    vector<string> output   = getFunctionOutputSplitted<string>(problem_4, "0");
    vector<string> expected = {};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(output[i], expected[i]);
}

TEST(Problem5Test, given_six_followed_by_six_numbers_prints_two_special_averages)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_5, "6 10 100 20 200 30 600", ' ');
    vector<double> expected = {20, 300};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stod(output[i]), expected[i]);
}

TEST(Problem5Test, given_five_followed_by_five_numbers_prints_two_special_averages)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_5, "5 10 100 20 200 30", ' ');
    vector<double> expected = {20, 150};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stod(output[i]), expected[i]);
}

TEST(Problem5Test, given_two_followed_by_two_numbers_prints_two_special_averages)
{
    vector<string> output =
        getFunctionOutputSplitted<string>(problem_5, "2 10 100", ' ');
    vector<double> expected = {10, 100};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stod(output[i]), expected[i]);
}

TEST(Problem5Test, given_zero_followed_by_zero_numbers_prints_two_zeros)
{
    vector<string> output = getFunctionOutputSplitted<string>(problem_5, "0", ' ');
    vector<double> expected = {0, 0};
    ASSERT_EQ(output.size(), expected.size());
    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(stod(output[i]), expected[i]);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
