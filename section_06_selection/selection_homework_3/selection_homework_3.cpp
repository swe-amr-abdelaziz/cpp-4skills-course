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

void problem2()
{
    // Two Intervals Intersection
    int s1, e1, s2, e2;
    cin >> s1 >> e1 >> s2 >> e2;

    bool noIntersection{e1 < s2 || e2 < s1};
    if (noIntersection)
        cout << -1;
    else
    {
        int start = s1 > s2 ? s1 : s2;
        int end   = e1 < e2 ? e1 : e2;
        cout << start << " " << end;
    }
}