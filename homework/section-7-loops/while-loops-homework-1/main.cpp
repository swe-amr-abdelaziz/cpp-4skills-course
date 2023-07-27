#include <iostream>
using namespace std;

void problem_1() {
  // Print Range
  int start, end;

  cin >> start >> end;

  // Swap start and end values if start is greater than end
  if (start > end) {
    start = start + end;
    end = start - end;
    start = start - end;
  }

  while (start <= end) cout << start++ << '\n';
}

void problem_2() {
  // Line Of Characters
  int count;
  char letter;

  cin >> count >> letter;

  while (count--) cout << letter;

  cout << '\n';
}

void problem_3() {
  // Print left angled triangle
  int col, row = 1;

  cin >> col;

  while (row <= col) {
    int count = row;
    while (count--) cout << "*";

    cout << '\n';
    row++;
  }
}

void problem_4() {
  // Print face down left angled triangle
  int col, row;

  cin >> col;
  row = col;

  while (row) {
    int count = row;
    while (count--) cout << "*";

    cout << '\n';
    row--;
  }
}

void problem_5() {
  // Special Average
  int n, odd_count = 0, even_count = 0;
  double m, odd_sum = 0, even_sum = 0;

  cin >> n;

  int start = 1;
  while (start <= n) {
    cin >> m;
    if (start % 2 == 0) {
      even_sum += m;
      even_count++;
    } else {
      odd_sum += m;
      odd_count++;
    }
    start++;
  }

  cout << odd_sum / odd_count << ' ' << even_sum / even_count << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();
  problem_5();

  return 0;
}