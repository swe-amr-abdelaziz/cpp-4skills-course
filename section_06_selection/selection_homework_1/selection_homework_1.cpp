#include <iostream>
using namespace std;

void problem1()
{
    // Arithmetic
    int a, b;
    cin >> a >> b;

    bool aIsEven = a % 2 == 0;
    bool bIsEven = b % 2 == 0;
    bool aIsOdd  = 1 - aIsEven;
    bool bIsOdd  = 1 - bIsEven;

    if (aIsOdd && bIsOdd)
        cout << a * b;
    else if (aIsEven && bIsEven)
        cout << a / b;
    else if (aIsOdd && bIsEven)
        cout << a + b;
    else if (aIsEven && bIsOdd)
        cout << a - b;
}

