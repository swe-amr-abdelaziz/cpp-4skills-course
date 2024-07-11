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

