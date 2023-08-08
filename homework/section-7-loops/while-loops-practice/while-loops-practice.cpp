#include <iostream>
#include <regex>
#include <string>
using namespace std;

void problem_1() {
  // Numbers divisible by 3
  int num = 1, x;
  cin >> x;

  while (num <= x) {
    if (num % 3 == 0) {
      cout << num << ' ';
    }
    num++;
  }
  cout << '\n';
}

void problem_2() {
  // Power function
  int x, y, result = 1;
  cin >> x >> y;

  while (y--) {
    result *= x;
  }
  cout << result << '\n';
}

void problem_3() {
  // Number of digits
  int num, count = 0;
  cin >> num;

  if (num == 0) {
    cout << 1 << '\n';
    return;
  }
  while (num) {
    num /= 10;
    count++;
  }

  cout << count << '\n';
}

void problem_3_with_regex() {
  // Number of digits using regex
  string num;
  cin >> num;
  string temp_num = num;

  regex integer_expr("(\\+|-)?[[:digit:]]+");
  if (regex_match(num, integer_expr)) {
    size_t count = num.size();
    if (num[0] == '+' || num[0] == '-') count--;
    cout << "Number: " << temp_num << " has " << count << " digits\n";
  } else {
    cout << "Invalid input: Not an integer\n";
  }
}

void problem_4() {
  int t, num, temp_num;
  cin >> t;

  while (t--) {
    cin >> num;
    temp_num = num;
    int sum = 0;
    while (num) {
      sum += num--;
    }
    cout << "Sum from 1 to " << temp_num << " = " << sum << '\n';
  }
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_3_with_regex();
  problem_4();

  return 0;
}
