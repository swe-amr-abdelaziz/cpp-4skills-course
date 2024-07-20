#include <iostream>
using namespace std;

void problem1()
{
    // Find Maximum of 10
    int max, current;
    cin >> max;

    // Using for loop is a better approach
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;
    cin >> current;
    if (max < current)
        max = current;

    cout << max;
}

void problem2()
{
    // Find Maximum up to 10
    int n, max, current;
    cin >> n >> max;
    n--;

    // Using while loop is a better approach
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }
    if (n--)
    {
        cin >> current;
        if (max < current)
            max = current;
    }

    cout << max;
}