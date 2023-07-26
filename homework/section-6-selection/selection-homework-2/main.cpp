#include <iostream>
using namespace std;

void problem_1() {
  // Find Maximum of 10
  int num, result;

  cin >> result;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;
  cin >> num; if (num > result) result = num;

  cout << result << '\n';
}

void problem_1_for_loop() {
  // Find Maximum of 10
  int num, result;

  cin >> result;
  for (int i = 0; i < 10-1; i++) {
    cin >> num;
    if (num > result)
      result = num;
  }

  cout << result << '\n';
}

void problem_2() {
  // Find Maximum up to 10
  int num, result, counter;

  cin >> counter;
  cin >> result; counter--;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;
  if (counter-- > 0) cin >> num; if (num > result) result = num;

  cout << result << '\n';
}

void problem_2_while_loop() {
  // Find Maximum up to 10
  int num, result, counter;

  cin >> counter;
  cin >> result; counter--;
  while(counter--) {
    cin >> num;
    if (num > result)
      result = num;
  }

  cout << result << '\n';
}

int main() {
  problem_1();
  problem_1_for_loop();
  problem_2();
  problem_2_while_loop();

  return 0;
}
