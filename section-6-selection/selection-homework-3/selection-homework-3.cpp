#include <iostream>
using namespace std;

void problem_1() {
  // Intervals
  int x, start_interval, end_interval, counter = 0;

  cin >> x;
  cin >> start_interval >> end_interval;
  if (start_interval <= x && x <= end_interval) counter++;

  cin >> start_interval >> end_interval;
  if (start_interval <= x && x <= end_interval) counter++;

  cin >> start_interval >> end_interval;
  if (start_interval <= x && x <= end_interval) counter++;

  cout << counter << '\n';
}

void problem_2() {
  // Two Intervals Intersection
  int s1, e1, s2, e2;
  cin >> s1 >> e1 >> s2 >> e2;

  if (s1 < s2) s1 = s2;
  if (e1 > e2) e1 = e2;

  if ((e1 - s1) < 0)  // Negative means that two intervals don't intersect
    cout << -1 << '\n';
  else
    cout << s1 << ' ' << e1 << '\n';
}

int main() {
  problem_1();
  problem_2();

  return 0;
}
