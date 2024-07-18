#include <iostream>
using namespace std;

void problem_1()
{
    // Simple Calculator
    double num1, num2;
    char op;

    cin >> num1 >> op >> num2;

    if (op == '+')
        cout << num1 + num2;
    else if (op == '-')
        cout << num1 - num2;
    else if (op == '*')
        cout << num1 * num2;
    else if (op == '/')
        cout << num1 / num2;
    else
        cout << "Invalid operation";
}

void problem_2()
{
    // Minimum of 2 numbers
    int num1, num2, result;

    cin >> num1 >> num2;

    result = num1;
    if (num2 < result)
        result = num2;

    cout << result;
}

void problem_3()
{
    // Minimum of 3 numbers
    int num1, num2, num3, result;

    cin >> num1 >> num2 >> num3;

    result = num1;
    if (num2 < result)
        result = num2;
    if (num3 < result)
        result = num3;

    cout << result;
}

