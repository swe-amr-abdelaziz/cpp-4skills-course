#include <iostream>
using namespace std;

void problem_1()
{
    // Print diamond
    int n, row;
    cin >> n;

    // Upper part
    row = 0;
    while (row < n)
    {
        int cursor{1};
        while (cursor <= n + row)
        {
            char ch = (cursor >= n - row && cursor <= n + row) ? '*' : ' ';
            cout << ch;
            cursor++;
        }
        cout << '\n';
        row++;
    }

    // Lower part
    row--;
    while (row >= 0)
    {
        int cursor{1};
        while (cursor <= n + row)
        {
            char ch = (cursor >= n - row && cursor <= n + row) ? '*' : ' ';
            cout << ch;
            cursor++;
        }
        cout << '\n';
        row--;
    }
}

void problem_2()
{
    // Special multiples 1
    int n;
    int i{0};
    cin >> n;

    while (i <= n)
    {
        if (i % 8 == 0 || (i % 4 == 0 && i % 3 == 0))
            cout << i << ' ';
        i++;
    }
}

