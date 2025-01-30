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

void problem_3()
{
    // Number of digits
    int num;
    int result{0};
    cin >> num;

    if (num == 0)
        result++;

    while (num)
    {
        result++;
        num /= 10;
    }

    cout << result;
}

void problem_4()
{
    // Nested loop
    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;
        int result{0};
        int originalNum{num};

        while (num)
        {
            result += num;
            num--;
        }

        cout << "Sum from " << 1 << " to " << originalNum << " = " << result << '\n';
    }
}