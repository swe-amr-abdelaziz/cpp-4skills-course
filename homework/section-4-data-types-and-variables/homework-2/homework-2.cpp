#include <iostream>
using namespace std;

void problem_1() {
  // Guess Program Output
  int num1, num2, num3;

  num1 = 0, num2 = 1, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 0, num2 = 1
  // num3 = 1
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 1, num2 = 1
  // num3 = 2
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 1, num2 = 2
  // num3 = 3
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 2, num2 = 3
  // num3 = 5
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 3, num2 = 5
  // num3 = 8
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 5, num2 = 8
  // num3 = 13
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 8, num2 = 13
  // num3 = 21
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 13, num2 = 21
  // num3 = 34
  num1 = num2, num2 = num3, num3 = num1 + num2,
  cout << num3 << "\n";  // num1 = 21, num2 = 34
  // num3 = 55
}

void problem_2() {
  // Swapping 2 numbers
  int num1, num2, num3;
  cin >> num1 >> num2;

  num3 = num1;
  num1 = num2;
  num2 = num3;

  cout << num1 << ' ' << num2 << endl;
}

int main() {
  problem_1();
  problem_2();

  return 0;
}
