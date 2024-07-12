#include <iostream>
using namespace std;

void problem_1_way_1()
{
    // Is even? way 1
    int num;
    cin >> num;

    bool is_even = num % 2 == 0;
    cout << is_even;
}

void problem_1_way_2()
{
    // Is even? way 2
    double num;
    cin >> num;

    double result = num / 2;
    bool is_even  = (result == (int) result);
    cout << is_even;
}

void problem_1_way_3()
{
    // Is even? way 3
    int num;
    cin >> num;

    int rem      = num % 10;
    bool is_even = rem == 0 || rem == 2 || rem == 4 || rem == 6 || rem == 8;
    cout << is_even;
}

void problem_2()
{
    // Last 3 digits sum
    int num;
    int sum{0};
    cin >> num;

    sum += num % 10, num /= 10;
    sum += num % 10, num /= 10;
    sum += num % 10, num /= 10;
    cout << sum;
}

