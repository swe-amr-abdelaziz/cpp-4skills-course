#include <iostream>
using namespace std;

void problem_1() {
  // Find the 3 minimum values
  int arr[200];
  int n;
  cin >> n;
  int minimum[3];

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];

    if (i == 0) {
      minimum[0] = arr[i];
    } else if (i == 1) {
      if (minimum[0] > arr[i]) {
        minimum[1] = minimum[0];
        minimum[0] = arr[i];
      } else {
        minimum[1] = arr[i];
      }
    } else if (i == 2) {
      if (minimum[0] > arr[i]) {
        minimum[2] = minimum[1];
        minimum[1] = minimum[0];
        minimum[0] = arr[i];
      } else if (minimum[1] > arr[i]) {
        minimum[2] = minimum[1];
        minimum[1] = arr[i];
      } else {
        minimum[2] = arr[i];
      }
    } else {
      if (minimum[0] > arr[i]) {
        minimum[2] = minimum[1];
        minimum[1] = minimum[0];
        minimum[0] = arr[i];
      } else if (minimum[1] > arr[i]) {
        minimum[2] = minimum[1];
        minimum[1] = arr[i];
      } else if (minimum[2] > arr[i]) {
        minimum[2] = arr[i];
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    cout << minimum[i] << " ";
  }
  cout << "\n";
}

void problem_2_nested_loops() {
  // Search for a number using nested loops
  int arr[200];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int q, num;
  cin >> q;
  while (q--) {
    cin >> num;
    int position = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (arr[i] == num) {
        position = i;
        break;
      }
    }
    cout << position << endl;
  }
}

void problem_2_single_loop() {
  // Search for a number using single loop
  int arr[200];
  int occurance[501]{0};
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    occurance[arr[i]] = i;
  }

  int q, num;
  cin >> q;
  while (q--) {
    cin >> num;
    int position = occurance[num];
    if (position == 0 && arr[0] != num) {
      position = -1;
    }
    cout << position << endl;
  }
}

void problem_3() {
  // Find most frequent number
  int arr[200];
  int freq[771]{0};
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    freq[arr[i] + 500] += 1;
  }

  int position = -1;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      position = arr[i] + 500;
    } else {
      int idx = arr[i] + 500;
      if (freq[position] < freq[idx]) {
        position = idx;
      }
    }
  }
  if (position != -1) {
    cout << position - 500 << " repreated " << freq[position] << " times\n";
  }
}

void problem_4() {
  // Digits frequency
  int arr[200];
  int n;
  cin >> n;

  int tmp, digits[10]{0};
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] == 0) digits[0]++;
    tmp = arr[i];
    while (tmp) {
      int digit = tmp % 10;
      digits[digit]++;
      tmp /= 10;
    }
  }

  for (int i = 0; i < 10; ++i) {
    cout << i << " " << digits[i] << "\n";
  }
}

void problem_5() {
  // Unique Numbers of unordered list
  int arr[901];
  int n;
  cin >> n;

  bool occurance[501]{false};
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (occurance[arr[i]] == false) {
      cout << arr[i] << " ";
      occurance[arr[i]] = true;
    }
  }
  cout << "\n";
}

void problem_6() {
  // Sorting numbers
  int arr[901];
  int n;
  cin >> n;

  int freq[501]{0};
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    freq[arr[i]] += 1;
  }

  for (int i = 0; i < 501; ++i) {
    int repeat = freq[i];
    while (repeat--) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  problem_1();
  problem_2_nested_loops();
  problem_2_single_loop();
  problem_3();
  problem_4();
  problem_5();
  problem_6();

  return 0;
}
