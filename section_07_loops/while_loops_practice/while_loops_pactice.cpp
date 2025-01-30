#include "iostream"
using namespace std;

void problem_1()
{
    // Numbers divisible by 3
    int x;
    int tmp = 3;
    cin >> x;

    while (tmp <= x)
    {
        cout << tmp << '\n';
        tmp += 3;
    }
}

