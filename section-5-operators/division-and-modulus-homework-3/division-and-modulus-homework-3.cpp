#include <iostream>
using namespace std;

void problem_1() {
  // 100 or 7?
  int num;
  cin >> num;

  int is_odd = num % 2;
  int is_even = 1 - is_odd;
  int result = is_even * 100 + is_odd * 7;
  cout << result << '\n';
}

void problem_2() {
  // Years!
  int age, years, months, days;
  cin >> age;

  years = age / 360;
  age %= 360;

  months = age / 30;
  age %= 30;
  days = age;

  cout << years << ' ' << months << ' ' << days << '\n';
}

int main() {
  problem_1();
  problem_2();

  return 0;
}
