#include <iostream>
using namespace std;

void problem1()
{
    // Intervals
    int x, start, end;
    int intersections{0};
    cin >> x;

    cin >> start >> end;
    if (start <= x && x <= end)
        intersections++;
    cin >> start >> end;
    if (start <= x && x <= end)
        intersections++;
    cin >> start >> end;
    if (start <= x && x <= end)
        intersections++;

    cout << intersections;
}

