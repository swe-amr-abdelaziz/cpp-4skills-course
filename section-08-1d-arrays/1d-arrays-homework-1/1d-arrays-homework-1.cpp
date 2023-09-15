#include <iostream>
using namespace std;

void problem_1() {
  // Is increasing array?
  int arr[200];
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  bool is_increasing = true;
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      is_increasing = false;
      break;
    }
  }

  is_increasing ? cout << "YES\n" : cout << "NO\n";
}

void problem_2() {
  // Replace MinMax
  int arr[200];
  int n, min, max;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (i == 0) {
      min = max = arr[i];
    } else {
      if (min > arr[i]) min = arr[i];
      if (max < arr[i]) max = arr[i];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i] == max)
      arr[i] = min;
    else if (arr[i] == min)
      arr[i] = max;
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

void problem_3() {
  // Unique Numbers of ordered list
  int n;
  cin >> n;

  int num = 0, prev;
  for (int i = 0; i < n; ++i) {
    prev = num;
    cin >> num;
    if (i) {
      if (num != prev) cout << num << ' ';
    } else {
      cout << num << ' ';
    }
  }
  cout << '\n';
}

void problem_4() {
  // Is Palindrome?
  int n;
  cin >> n;

  int arr[1000];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  bool is_palindrome = true;
  for (int i = 0; i < n / 2 && is_palindrome; ++i) {
    if (arr[i] != arr[n - i - 1]) {
      is_palindrome = false;
    }
  }

  is_palindrome ? cout << "YES\n" : cout << "NO\n";
}

void problem_5() {
  // Smallest pair
  int n;
  int arr[200];
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> arr[i];

  int result;
  bool is_first = true;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int value = arr[i] + arr[j] + j - i;
      if (is_first || result > value) {
        result = value;
        is_first = false;
      }
    }
  }
  cout << result << endl;
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();
  problem_5();

  return 0;
}
