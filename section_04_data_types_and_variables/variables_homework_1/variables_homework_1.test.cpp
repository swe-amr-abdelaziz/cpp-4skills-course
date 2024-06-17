#include "variables_homework_1.h"
#include <gtest/gtest.h>
#include <sstream>
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

TEST(Problem1Test, input_even_odd_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "12 3");
    EXPECT_EQ(output,
              "12 + 3 = 15\n"
              "12 - 3 = 9\n"
              "12 / 3 = 4\n"
              "12 * 3 = 36\n");
}

TEST(Problem1Test, input_even_even_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "12 6");
    EXPECT_EQ(output,
              "12 + 6 = 18\n"
              "12 - 6 = 6\n"
              "12 / 6 = 2\n"
              "12 * 6 = 72\n");
}

TEST(Problem1Test, input_odd_odd_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "7 3");
    EXPECT_EQ(output,
              "7 + 3 = 10\n"
              "7 - 3 = 4\n"
              "7 / 3 = 2\n"
              "7 * 3 = 21\n");
}

TEST(Problem1Test, input_negative_positive_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "-12 3");
    EXPECT_EQ(output,
              "-12 + 3 = -9\n"
              "-12 - 3 = -15\n"
              "-12 / 3 = -4\n"
              "-12 * 3 = -36\n");
}

TEST(Problem1Test, input_negative_negative_numbers_output_basic_math_operations)
{
    string output = getFunctionOutput(problem_1, "-12 -3");
    EXPECT_EQ(output,
              "-12 + -3 = -15\n"
              "-12 - -3 = -9\n"
              "-12 / -3 = 4\n"
              "-12 * -3 = 36\n");
}

TEST(Problem2Test, print_students_data_with_average_grades_1)
{
    string output = getFunctionOutput(problem_2, "mostafa 111 20 ALI 555 30");
    EXPECT_EQ(output,
              "What is student 1 name: "
              "His id: "
              "His math exam grade: "
              "What is student 2 name: "
              "His id: "
              "His math exam grade: "
              "Students grades in math\n"
              "mostafa (with id 111) got grade: 20\n"
              "ALI (with id 555) got grade: 30\n"
              "Average grade is 25\n");
}

TEST(Problem2Test, print_students_data_with_average_grades_2)
{
    string output = getFunctionOutput(problem_2, "Amr 2 21 Mohamed 3 24");
    EXPECT_EQ(output,
              "What is student 1 name: "
              "His id: "
              "His math exam grade: "
              "What is student 2 name: "
              "His id: "
              "His math exam grade: "
              "Students grades in math\n"
              "Amr (with id 2) got grade: 21\n"
              "Mohamed (with id 3) got grade: 24\n"
              "Average grade is 22.5\n");
}

