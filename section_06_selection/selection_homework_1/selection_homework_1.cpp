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

void problem2()
{
    // Sort 3 numbers
    int a, b, c, tmp;
    cin >> a >> b >> c;

    if (b > c)
    {
        tmp = b;
        b   = c;
        c   = tmp;
    }
    if (a > b)
    {
        tmp = a;
        a   = b;
        b   = tmp;
    }
    if (b > c)
    {
        tmp = b;
        b   = c;
        c   = tmp;
    }

    cout << a << " " << b << " " << c;
}

