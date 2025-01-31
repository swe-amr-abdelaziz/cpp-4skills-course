#include <iostream>
using namespace std;

void problem_1()
{
    // Print Range
    int x;
    int y;
    cin >> x >> y;
    int step = x < y ? 1 : -1;

    while (x != y)
    {
        cout << x << '\n';
        x += step;
    }
    cout << y << '\n';
}

void problem_2()
{
    // Line Of Characters
    int num;
    char ch;
    cin >> num >> ch;

    while (num--)
        cout << ch;
}

void problem_3()
{
    // Print left angled triangle
    int row;
    cin >> row;
    int col{0};

    while (col < row)
    {
        int cursor = col + 1;

        while (cursor--)
            cout << '*';

        cout << '\n';
        col++;
    }
}

