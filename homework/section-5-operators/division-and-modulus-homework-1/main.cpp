#include <iostream>
using namespace std;

void problem_1() {
  // Averages
  double a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  double result_1 = (a + b + c + d + e) / 5;
  cout << result_1 << '\n';

  double result_2 = (a + b + c) / (d + e);
  cout << result_2 << '\n';

  double first_avg = (a + b + c) / 3;
  double last_avg = (d + e) / 2;
  double result_3 = first_avg / last_avg;
  cout << result_3 << '\n';
}

void problem_2() {
  // Fractional Part
  int a, b;
  cin >> a >> b;

  double result = double(a % b) / b;
  cout << result << endl;
}

void problem_3() {
  // Our remainder
  int a, b;
  cin >> a >> b;

  int result = a - ((a / b) * b);
  cout << result << endl;
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
