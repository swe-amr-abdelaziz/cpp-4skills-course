#include <iostream>
using namespace std;

void problem_1() {
  // Swapping 3 numbers
  int num1, num2, num3, temp = -1;

  cin >> num1 >> num2 >> num3;

  temp = num1;
  num1 = num2;
  num2 = num3;
  num3 = temp;

  cout << num1 << ' ' << num2 << ' ' << num3 << '\n';
}

void problem_2() {
  // Print Me
  int a, b;
  cin >> a >> b;

  double coeff = 0.5 * (b + 1);
  double result = (a * a) * coeff + (2 * a + 1) * (1 - coeff);
  cout << result << endl;
}

void problem_3() {
  // Sum numbers from 1 to N
  int num;
  cin >> num;

  cout << (num * (num + 1)) * 0.5 << endl;
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
