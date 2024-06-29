#include <iostream>
using namespace std;

void problem_1()
{
    // Guess Program Output
    int a = 0, b = 1;

    cout << a++ << "\n"; // a = 1, b = 1
    cout << ++a << "\n"; // a = 2, b = 1
    a += 2 * b + 1;      // a = 5, b = 1
    b = ++a * 2;         // a = 6, b = 12
    cout << a << " " << b << "\n";

    b = a;                      // a = 6, b = 6
    a = 12 + a / 3 / 2 - 2 * 2; // a = 9, b = 6
    cout << a << "\n";

    a = b;                          // a = 6, b = 6
    a = ((12 + a) / 3 / 2 - 2) * 2; // a = 2, b = 6
    cout << a << "\n";
}

void problem_2()
{
    // Guess Program Output
    int a = 1, b = 1, c;

    cout << (c = a + b,
             a = b,
             b = c, // c = 2, a = 1, b = 2
             c = a + b,
             a = b,
             b = c, // c = 3, a = 2, b = 3
             c = a + b,
             a = b,
             b = c, // c = 5, a = 3, b = 5
             c = a + b,
             a = b,
             b = c) // c = 8, a = 5, b = 8
         << endl;
}

void problem_3()
{
    // Guess Program Output
    int a = 210;

    a /= 2; // a = 105
    cout << a << "\n";

    cout << (a /= 3) << "\n"; // a = 35
    cout << (a /= 5) << "\n"; // a = 7
    cout << (a /= 7) << "\n"; // a = 1

    cout << (2 + 3) * (5 - (-3)) / 5 / 8 << "\n";

    a = 10;
    cout << a++ + 10 << "\n"; // a = 11
    cout << ++a + 10 << "\n"; // a = 12
    cout << a-- + 10 << "\n"; // a = 11
    cout << --a + 10 << "\n"; // a = 10

    int b = 20;
    cout << a++ + ++b << "\n"; // Don't code this way
                               // a = 11, b = 21

    cout << a << "\n";
    ++a += 10; // Don't code this way
               // a = 22
    cout << a << "\n";
}
