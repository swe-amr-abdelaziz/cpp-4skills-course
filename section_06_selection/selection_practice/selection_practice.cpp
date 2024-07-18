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

void problem_4()
{
    // Is even? Print digits
    int num;
    cin >> num;

    if (num % 2 == 0)
        cout << num % 10;
    else
    {
        if (num < 1000)
            cout << num % 100;
        else if (num < 1000000)
            cout << num % 10000;
        else
            cout << -num;
    }
}

void problem_5()
{
    // Last 3 digits!
    int num;
    cin >> num;

    if (num < 10000)
        cout << "this is a small number";
    else
    {
        int digit1 = num % 10;
        num /= 10;
        int digit2 = num % 10;
        num /= 10;
        int digit3 = num % 10;

        bool isSumOdd = (digit1 + digit2 + digit3) % 2 != 0;
        if (isSumOdd)
            cout << "this is a great number";
        else
        {
            // Better approach using while loop
            if (digit1 % 2 != 0 || digit2 % 2 != 0 || digit3 % 2 != 0)
                cout << "this is a good number";
            else
                cout << "this is a bad number";
        }
    }
}