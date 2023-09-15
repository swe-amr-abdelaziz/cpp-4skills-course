#include <iostream>
using namespace std;

void problem_1() {
  // Reverse in place
  int arr[200];
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n / 2; ++i) {
    int last = n - i - 1;
    int tmp = arr[i];
    arr[i] = arr[last];
    arr[last] = tmp;
  }
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }

  cout << '\n';
}

void problem_2() {
  // Find most frequent number
  int arr[200];
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  const int SIZE = 151;
  int freq[SIZE]{0};
  for (int i = 0; i < n; ++i) {
    freq[arr[i]]++;
  }

  int result = 0, max_freq = 0;
  for (int i = 1; i < SIZE; ++i) {
    if (max_freq < freq[i]) {
      max_freq = freq[i];
      result = i;
    }
  }

  cout << result << " repeated " << max_freq << " times\n";
}

int main() {
  problem_1();
  problem_2();

  return 0;
}
