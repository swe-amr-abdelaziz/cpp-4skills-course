#include <iostream>
using namespace std;

void homework_1()
{
    // Guess the output
    int a = 10, b = 20, c = 30, d = 40;

    cout << (a + b == c) << "\n";
    cout << (a + b + c >= 2 * d) << "\n";

    cout << (a > 5 || d < 30) << "\n";
    cout << (a > 5 && d < 30) << "\n";
    cout << (a <= b && b <= c) << "\n";

    cout << ((a > 5 && d < 30) || c - b == 10) << "\n";
    cout << (a <= b && b <= c && c <= d) << "\n";

    cout << ((a > 5 && d < 30) || c > d || d % 2 == 0) << "\n";
    cout << ((a > 5 && d < 30) || (c > d && d % 2 == 0)) << "\n";

    cout << (a == 10 || (b != 20 && c != 30) || d != 40) << "\n";
    cout << (((a == 10 || b != 20) && c != 30) || d != 40) << "\n";
}

void homework_2()
{
    // Create logic!
    int nb, ng, nt;
    cin >> nb >> ng >> nt;

    // nb greater than 25
    cout << (nb > 25) << "\n";

    // ng less than or equal to 30
    cout << (ng <= 30) << "\n";

    // nb > 20 and nt > 2 or ng > 30 and nt > 4
    cout << ((nb > 20 && nt > 2) || (ng > 30 && nt > 4)) << "\n";

    // Either nb < 60 or ng < 70
    cout << (nb < 60 || ng < 70) << "\n";

    // Neither nb >= 60 nor ng >= 70
    cout << (!(nb >= 60) && !(ng >= 70)) << "\n";

    // nb is 10 more students than ng
    cout << (nb == ng + 10) << "\n";

    // Difference between nb and ng is more than 10 or nt > 5
    cout << (nb - ng > 10 || nt > 5) << "\n";

    // Either nb is 10 more students than ng or ng is 15 more students than nb
    cout << (nb == ng + 10 || ng == nb + 15) << "\n";
}

void homework_3()
{
    // Simplify expressions
    bool T = true;
    bool F = false;

    /*
     * T && T && F && T
     * F
     */
    cout << (T && T && F && T) << "\n";

    /*
     * T && T && F && T || T && T
     * {...} || T
     * T
     */
    cout << ((T && T && F && T) || (T && T)) << "\n";

    /*
     * T && T && T && T || T && (T || F)
     * T || {...}
     * T
     */
    cout << ((T && T && T && T) || (T && (T || F))) << "\n";

    /*
     * T && T && T || T && (F || (T && (T && T)))
     * T || {...}
     * T
     */
    cout << ((T && T && T) || (T && (F || (T && (T && T))))) << "\n";

    /*
     * T && T || T && F && T || T && T && F || (T && (T || F))
     * T || {...}
     * T
     */
    cout << ((T && T) || (T && F && T) || (T && T && F) || (T && (T || F))) << "\n";

    /*
     * T && T || T && F && T || (T && T && F || (T && (T || F)))
     * T || {...}
     * T
     */
    cout << ((T && T) || (T && F && T) || ((T && T && F) || (T && (T || F)))) << "\n";

    /*
     * (T && T || T && F && T || T) && T && F || (T && (T || F))
     * (T || {...}) && T && F || (T && (T || F))
     * T && T && F || (T && (T || F))
     * F || (T && (T || F))
     * F || (T && T)
     * F || T
     * T
     */
    cout << ((((T && T) || (T && F && T) || T) && T && F) || (T && (T || F))) << "\n";

    /*
     * T && T || T && (F && T || T && T) && F || (T && (T || F))
     * T || {...}
     * T
     */
    cout << ((T && T) || (T && ((F && T) || (T && T)) && F) || (T && (T || F))) << "\n";
}
