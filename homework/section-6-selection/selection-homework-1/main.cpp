#include <iostream>
using namespace std;

void problem_1() {
  // Arithmetic
  int a, b;
  cin >> a >> b;

  bool is_a_even = a % 2 == 0;
  bool is_a_odd = 1 - is_a_even;
  bool is_b_even = b % 2 == 0;
  bool is_b_odd = 1 - is_b_even;

  if (is_a_odd && is_b_odd)
    cout << a * b << '\n';
  else if (is_a_even && is_b_even)
    cout << a / b << '\n';
  else if (is_a_odd && is_b_even)
    cout << a + b << '\n';
  else
    cout << a - b << '\n';
}

void problem_2() {
  // Sort 3 numbers
  int num1, num2, num3, tmp;
  cin >> num1 >> num2 >> num3;

  if (num2 > num3) {
    tmp = num2;
    num2 = num3;
    num3 = tmp;
  }
  if (num1 > num2) {
    tmp = num1;
    num1 = num2;
    num2 = tmp;
  }
  if (num2 > num3) {
    tmp = num2;
    num2 = num3;
    num3 = tmp;
  }

  cout << num1 << ' ' << num2 << ' ' << num3 << '\n';
}

void problem_3() {
  // Maximum but constrained
  int num1, num2, num3, result;
  cin >> num1 >> num2 >> num3;

  if (num1 < 100)
    result = num1;
  else if (num2 < 100)
    result = num2;
  else if (num3 < 100)
    result = num3;
  else
    result = -1;

  if (num1 < 100 && num1 > result) result = num1;
  if (num2 < 100 && num2 > result) result = num2;
  if (num3 < 100 && num3 > result) result = num3;

  cout << result << '\n';
}

void problem_4() {
  // Conditional Count
  int x, num1, num2, num3, num4, num5;
  cin >> x >> num1 >> num2 >> num3 >> num4 >> num5;

  int sum_greater_than_x = 0;

  if (num1 > x) sum_greater_than_x++;
  if (num2 > x) sum_greater_than_x++;
  if (num3 > x) sum_greater_than_x++;
  if (num4 > x) sum_greater_than_x++;
  if (num5 > x) sum_greater_than_x++;

  int sum_less_than_x = 5 - sum_greater_than_x;
  cout << sum_less_than_x << ' ' << sum_greater_than_x << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();

  return 0;
}
