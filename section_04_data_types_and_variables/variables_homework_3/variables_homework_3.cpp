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

