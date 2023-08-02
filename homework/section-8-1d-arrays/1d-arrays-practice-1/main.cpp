#include <iostream>
using namespace std;

void problem_1() {
  // Find first and 2nd Maximum values
  int n;
  int arr[200]{};
  int max;
  int second_max;

  cin >> n;
  if (n < 1)
    cout << "N must be greater than 0\n";
  else if (n == 1) {
    cin >> arr[0];
    max = second_max = arr[0];
  } else {
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    if (arr[0] > arr[1]) {
      max = arr[0];
      second_max = arr[1];
    } else {
      max = arr[1];
      second_max = arr[0];
    }

    for (int i = 2; i < n; ++i) {
      if (max <= arr[i]) {
        second_max = max;
        max = arr[i];
      } else if (second_max <= arr[i]) {
        second_max = arr[i];
      }
    }
  }

  if (n) {
    cout << max << ' ' << second_max << '\n';
  }
}

void problem_2() {
  // Find pair values of maximum sum
  int n;
  int arr[200]{};
  int max_idx;
  int second_max_idx;

  cin >> n;
  if (n < 1)
    cout << "N must be greater than 0\n";
  else if (n == 1) {
    cin >> arr[0];
    max_idx = second_max_idx = 0;
  } else {
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    if (arr[0] > arr[1]) {
      max_idx = 0;
      second_max_idx = 1;
    } else {
      max_idx = 1;
      second_max_idx = 0;
    }

    for (int i = 2; i < n; ++i) {
      if (arr[max_idx] <= arr[i]) {
        second_max_idx = max_idx;
        max_idx = i;
      } else if (arr[second_max_idx] <= arr[i]) {
        second_max_idx = i;
      }
    }
  }

  if (n) {
    cout << arr[max_idx] << ' ' << arr[second_max_idx] << '\n';
  }
}

int main() {
  problem_1();
  problem_2();

  return 0;
}
