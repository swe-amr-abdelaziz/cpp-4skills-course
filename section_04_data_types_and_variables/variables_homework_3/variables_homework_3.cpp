#include <iostream>
using namespace std;

void problem_1()
{
    // Swapping 3 numbers!
    int num1, num2, num3, temp = -1;

    cin >> num1 >> num2 >> num3;
    // 4 lines
    temp = num1;
    num1 = num2;
    num2 = num3;
    num3 = temp;
    cout << num1 << " " << num2 << " " << num3 << "\n";
}

void problem_2()
{
    // Print Me
    int a, b;

    cin >> a >> b;

    int b_equals_1 = (b + 1) / 2;
    // If B = 1
    int formula1 = (a * a) * b_equals_1;
    // If B = -1
    int formula2 = (2 * a + 1) * (1 - b_equals_1);

    cout << formula1 + formula2;
}

