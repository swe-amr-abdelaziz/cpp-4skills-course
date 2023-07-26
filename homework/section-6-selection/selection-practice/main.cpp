#include <iostream>
using namespace std;

void simpleCalculator() {
  double num1, num2;
  char op;
  cin >> num1 >> op >> num2;

  if (op == '+')
    cout << num1 + num2 << '\n';
  else if (op == '-')
    cout << num1 - num2 << '\n';
  else if (op == '*')
    cout << num1 * num2 << '\n';
  else if (op == '/')
    cout << num1 / num2 << '\n';
}

void minimumOf2Numbers() {
  int num1, num2;
  cin >> num1 >> num2;

  if (num1 < num2)
    cout << num1 << '\n';
  else
    cout << num2 << '\n';
}

void minimumOf3Numbers() {
  int num1, num2, num3;
  cin >> num1 >> num2 >> num3;

  int minimum = num1;

  if (minimum > num2) minimum = num2;

  if (minimum > num3) minimum = num3;

  cout << minimum << '\n';
}

void isEvenPrintDigits() {
  int num;
  cin >> num;

  if (num % 2 == 0)
    cout << num % 10 << '\n';
  else {
    if (num < 1000)
      cout << num % 100 << '\n';
    else if (num < 1'000'000)
      cout << num % 10'000 << '\n';
    else
      cout << -num << '\n';
  }
}

void last3Digits() {
  int num;
  cin >> num;

  if (num < 10000)
    cout << "This is a small number\n";
  else {
    // Sum the last 3 digits of the number
    int firstDigit, secondDigit, thirdDigit;

    // 1st iteration
    firstDigit = num % 10;
    num /= 10;

    // 2nd iteration
    secondDigit = num % 10;
    num /= 10;

    // 3rd iteration
    thirdDigit = num % 10;
    num /= 10;

    // Sum of last 3 digits
    int sum = firstDigit + secondDigit + thirdDigit;

    if (sum % 2 != 0)
      cout << "This is a great number\n";
    else {
      if (firstDigit % 2 != 0 || secondDigit % 2 != 0 || thirdDigit % 2 != 0)
        cout << "This is a good number\n";
      else
        cout << "This is a bad number\n";
    }
  }
}

int main() {
  simpleCalculator();
  minimumOf2Numbers();
  minimumOf3Numbers();
  isEvenPrintDigits();
  last3Digits();

  return 0;
}
