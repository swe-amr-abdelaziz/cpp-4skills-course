#include <iostream>
using namespace std;

void problem_1() {
  // Is even?
  int num;
  cin >> num;

  // Is even using %2
  bool is_even1 = num % 2 == 0;

  // Is even using /2
  bool is_even2 = num - ((num / 2) * 2) == 0;

  // Is even using %10
  int reminder = num % 10;
  bool is_even3 = reminder == 0 || reminder == 2 || reminder == 4 ||
                  reminder == 6 || reminder == 8;

  cout << "is_even1: " << is_even1 << endl;
  cout << "is_even2: " << is_even2 << endl;
  cout << "is_even3: " << is_even3 << endl;
}

void problem_2() {
  // Last 3 digits sum
  int num, sum{0};
  cin >> num;

  // 1st iteration
  sum += num % 10;
  num /= 10;

  // 2nd iteration
  sum += num % 10;
  num /= 10;

  // 3rd iteration
  sum += num % 10;
  num /= 10;

  cout << sum << endl;
}

void problem_3() {
  // 4th digits from the end
  int num;
  cin >> num;

  int result = (num / 1000) % 10;
  cout << result;
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
