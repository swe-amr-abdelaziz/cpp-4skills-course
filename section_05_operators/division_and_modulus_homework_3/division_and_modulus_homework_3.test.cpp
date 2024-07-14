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

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_1)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "0", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 0);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_2)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "1", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 1);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_3)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "10", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 10);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_4)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "29", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 29);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_5)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "30", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 1);
    EXPECT_EQ(stoi(actual[2]), 0);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_6)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "31", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 1);
    EXPECT_EQ(stoi(actual[2]), 1);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_7)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "61", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 2);
    EXPECT_EQ(stoi(actual[2]), 1);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_8)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "200", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 6);
    EXPECT_EQ(stoi(actual[2]), 20);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_9)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "359", ' ');
    EXPECT_EQ(stoi(actual[0]), 0);
    EXPECT_EQ(stoi(actual[1]), 11);
    EXPECT_EQ(stoi(actual[2]), 29);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_10)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "360", ' ');
    EXPECT_EQ(stoi(actual[0]), 1);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 0);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_11)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "361", ' ');
    EXPECT_EQ(stoi(actual[0]), 1);
    EXPECT_EQ(stoi(actual[1]), 0);
    EXPECT_EQ(stoi(actual[2]), 1);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_12)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "391", ' ');
    EXPECT_EQ(stoi(actual[0]), 1);
    EXPECT_EQ(stoi(actual[1]), 1);
    EXPECT_EQ(stoi(actual[2]), 1);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_13)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "1000", ' ');
    EXPECT_EQ(stoi(actual[0]), 2);
    EXPECT_EQ(stoi(actual[1]), 9);
    EXPECT_EQ(stoi(actual[2]), 10);
}

TEST(Problem2Test, given_no_of_days_then_print_no_of_corresponding_years_months_days_test_case_14)
{
    vector<string> actual = getFunctionOutputSplitted<string>(problem_2, "5000", ' ');
    EXPECT_EQ(stoi(actual[0]), 13);
    EXPECT_EQ(stoi(actual[1]), 10);
    EXPECT_EQ(stoi(actual[2]), 20);
}