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

