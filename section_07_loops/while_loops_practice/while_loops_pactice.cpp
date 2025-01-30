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

void problem_2()
{
    // Power Function
    int num;
    int pow;
    cin >> num >> pow;
    int result = 1;

    while (pow--)
        result *= num;

    cout << result;
}

