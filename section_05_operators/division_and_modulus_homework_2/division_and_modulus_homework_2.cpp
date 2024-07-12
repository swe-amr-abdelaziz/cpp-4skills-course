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

