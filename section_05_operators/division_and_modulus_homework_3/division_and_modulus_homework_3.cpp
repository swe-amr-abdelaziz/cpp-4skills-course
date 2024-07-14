#include <iostream>
using namespace std;

void problem_1()
{
    // 100 or 7?
    int num;
    cin >> num;

    int isEven = num % 2 == 0;
    int isOdd  = (1 - isEven);
    int result = isEven * 100 + isOdd * 7;
    cout << result;
}

void problem_2()
{
    // Years!
    const int DAYS_PER_MONTH  = 30;
    const int MONTHS_PER_YEAR = 12;
    int days;
    cin >> days;

    int years = days / (DAYS_PER_MONTH * MONTHS_PER_YEAR);
    days %= (DAYS_PER_MONTH * MONTHS_PER_YEAR);
    int months = days / DAYS_PER_MONTH;
    days %= DAYS_PER_MONTH;

    cout << years << ' ' << months << ' ' << days;
}