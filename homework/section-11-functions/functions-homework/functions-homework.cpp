#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace Problem1 {
int max(int a, int b, int c) {
  int result = a;
  if (b > result) result = b;
  if (c > result) result = c;
  return result;
}

int max(int a, int b, int c, int d) {
  int result = a;
  if (b > result) result = b;
  if (c > result) result = c;
  if (d > result) result = d;
  return result;
}

int max(int a, int b, int c, int d, int e) {
  int result = a;
  if (b > result) result = b;
  if (c > result) result = c;
  if (d > result) result = d;
  if (e > result) result = e;
  return result;
}

int max(int a, int b, int c, int d, int e, int f) {
  int result = a;
  if (b > result) result = b;
  if (c > result) result = c;
  if (d > result) result = d;
  if (e > result) result = e;
  if (f > result) result = f;
  return result;
}

int maxGeneric(int a, int b, int c, int d = INT32_MIN, int e = INT32_MIN,
               int f = INT32_MIN) {
  int result = a;
  if (b > result) result = b;
  if (c > result) result = c;
  if (d > result) result = d;
  if (e > result) result = e;
  if (f > result) result = f;
  return result;
}
}  // namespace Problem1

namespace Problem2 {
string reverseString(const string &str) {
  string reverseStr{""};
  for (size_t i = 0; i < str.size(); i += 1) {
    reverseStr += str[str.size() - i - 1];
  }
  return reverseStr;
}
}  // namespace Problem2

namespace Problem3 {
void printMenu() {
  cout << "1) Add 2 numbers\n"
          "2) Subtract 2 numbers\n"
          "3) Multiply 2 numbers\n"
          "4) Divide 2 numbers\n"
          "5) End the program\n";
}

int getInput(string inputName = "choice", string typeName = "integer") {
  int input{};
  string inputString{};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  bool isValidInput{false};
  do {
    cin >> inputString;
    try {
      input = stoi(inputString);
      typeName = "integer";
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    isValidInput = true;
  } while (!isValidInput);
  return input;
}

void readDouble(double &d, string inputName) {
  string typeName{"double"};
  string inputString{};
  bool isValidInput{false};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  do {
    cin >> inputString;
    try {
      d = stod(inputString);
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    isValidInput = true;
  } while (!isValidInput);
}

void readCalculatorInput(double &d1, double &d2) {
  readDouble(d1, "first number");
  readDouble(d2, "second number");
}

void add() {
  double num1{};
  double num2{};
  readCalculatorInput(num1, num2);
  cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
}

void subtract() {
  double num1{};
  double num2{};
  readCalculatorInput(num1, num2);
  cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
}

void multiply() {
  double num1{};
  double num2{};
  readCalculatorInput(num1, num2);
  cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
}

void divide() {
  double num1{};
  double num2{};

  do {
    readCalculatorInput(num1, num2);
    if (num2 == 0) {
      cout << "Invalid second number, cannot divide over zero, try again\n";
    }
  } while (num2 == 0);

  cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';
}

void runCalculator() {
  cout << "<<< Calculator Program >>>\n\n";
  bool isProgramRunning{true};
  int operationsCount{0};

  while (isProgramRunning) {
    printMenu();
    int choice{getInput()};

    switch (choice) {
      case 1:
        add();
        operationsCount++;
        break;
      case 2:
        subtract();
        operationsCount++;
        break;
      case 3:
        multiply();
        operationsCount++;
        break;
      case 4:
        divide();
        operationsCount++;
        break;
      case 5:
        isProgramRunning = false;
        break;
      default:
        cout << "Invalid input, please enter a number from the list\n";
    }
    cout << '\n';
  }
  cout << "Number of operations done: " << operationsCount << '\n';
}
}  // namespace Problem3

namespace Problem4 {
bool isPalindromeArray(int arr[], size_t len) {
  for (size_t i = 0; i < len / 2; i++) {
    if (arr[i] != arr[len - i - 1]) {
      return false;
    }
  }
  return true;
}
}  // namespace Problem4

namespace Problem5 {
void setPowers(int arr[], int len = 5, int m = 2) {
  int value{1};
  for (int i = 0; i < len; i++) {
    arr[i] = value;
    value *= m;
  }
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}
}  // namespace Problem5

namespace Problem6 {
bool isPrime(int num) {
  if (num < 2) {
    return false;
  } else if (num == 2) {
    return true;
  }
  for (int i = 2; i < sqrt(num) + 1; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int nthPrime(int n) {
  if (n <= 0) {
    return -1;
  }
  int i{0};
  int current{0};
  int value{0};
  while (current < n) {
    if (isPrime(i)) {
      current++;
      value = i;
    }
    i++;
  }
  return value;
}
}  // namespace Problem6

namespace Problem7 {
bool startsWith(string input, string pattern, size_t pos) {
  if (pos + pattern.size() > input.size()) {
    return false;
  }
  for (size_t i = pos; i < pos + pattern.size(); i++) {
    if (input[i] != pattern[i - pos]) {
      return false;
    }
  }
  return true;
}

string replaceString(string input, string pattern, string to) {
  string str{""};
  size_t index{0};
  while (input[index]) {
    if (startsWith(input, pattern, index)) {
      str += to;
      index += pattern.size();
    } else {
      str += input[index];
      index++;
    }
  }
  return str;
}
}  // namespace Problem7

int main() {
  cout << Problem1::max(45, 23, 13) << '\n';
  cout << Problem1::max(45, 23, 13, 79) << '\n';
  cout << Problem1::max(45, 23, 13, 79, 51) << '\n';
  cout << Problem1::max(45, 23, 13, 79, 51, 96) << '\n';
  cout << Problem1::maxGeneric(45, 23, 13) << '\n';
  cout << Problem1::maxGeneric(45, 23, 13, 79) << '\n';
  cout << Problem1::maxGeneric(45, 23, 13, 79, 51) << '\n';
  cout << Problem1::maxGeneric(45, 23, 13, 79, 51, 96) << '\n';
  cout << Problem2::reverseString("Hello World!") << '\n';
  cout << Problem2::reverseString("abcdefg") << '\n';
  cout << Problem2::reverseString("TUVWXYZ") << '\n';
  Problem3::runCalculator();
  int array1[] = {1, 2, 3, 4, 5};
  int array2[] = {1, 2, 3, 2, 1};
  int array3[] = {30, 20, 10, 20, 30};
  int array4[] = {0};
  cout << Problem4::isPalindromeArray(array1, 5) << '\n';
  cout << Problem4::isPalindromeArray(array2, 5) << '\n';
  cout << Problem4::isPalindromeArray(array3, 5) << '\n';
  cout << Problem4::isPalindromeArray(array4, 1) << '\n';
  int arr1[6];
  Problem5::setPowers(arr1, 6);
  Problem5::printArray(arr1, 6);
  int arr2[4];
  Problem5::setPowers(arr2, 4, 3);
  Problem5::printArray(arr2, 4);
  cout << Problem6::nthPrime(6) << '\n';
  cout << Problem7::replaceString("aabcabaaad", "aa", "x") << '\n';
  cout << Problem7::replaceString("aabcabaaad", "aa", "aaaa") << '\n';
  cout << Problem7::replaceString("aabcabaaad", "aa", "") << '\n';
}
