#include <iostream>
using namespace std;

void problem_1()
{
    // Guess Program Output
    int num1, num2, num3;

    num1 = 0, num2 = 1, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";

    // https://en.wikipedia.org/wiki/Fibonacci_number
}

void problem_2()
{
    // Swapping 2 numbers!
    int num1, num2, num3 = -1;

    cin >> num1 >> num2;

    num3 = num1;
    num1 = num2;
    num2 = num3;

    cout << num1 << " " << num2 << endl;
}
