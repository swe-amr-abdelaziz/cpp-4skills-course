#include <iostream>
using namespace std;

void problem_1()
{
    // Averages
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    double avg = (a + b + c + d + e) / 5.0;
    cout << avg << "\n";

    double sum1 = a + b + c;
    double sum2 = d + e;
    cout << sum1 / sum2 << "\n";

    double avg1 = (a + b + c) / 3.0;
    double avg2 = (d + e) / 2.0;
    cout << avg1 / avg2 << "\n";
}

void problem_2()
{
    // Fractional Part
    double a, b;
    cin >> a >> b;

    double c = a / b;
    cout << c - (int) c;
}

void problem_3()
{
    // Our Reminder
    int a, b;
    cin >> a >> b;

    cout << a - (a / b) * b;
}