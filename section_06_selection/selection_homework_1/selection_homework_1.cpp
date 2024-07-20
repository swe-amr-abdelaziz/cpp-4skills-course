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

void problem3()
{
    // Maximum but constrained
    int a, b, c;
    int result{-1};
    bool foundNumLT100{false};
    cin >> a >> b >> c;

    if (a < 100 && (!foundNumLT100 || a > result))
    {
        result        = a;
        foundNumLT100 = true;
    }
    if (b < 100 && (!foundNumLT100 || b > result))
    {
        result        = b;
        foundNumLT100 = true;
    }
    if (c < 100 && (!foundNumLT100 || c > result))
    {
        result        = c;
        foundNumLT100 = true;
    }
    if (!foundNumLT100)
        result = -1;

    cout << result;
}

