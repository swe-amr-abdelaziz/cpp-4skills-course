#include <iostream>
using namespace std;

void problem_1() {
  // Recaman's sequence
  bool is_visited[2000]{false};
  int value = 0;
  is_visited[0] = true;
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    int last_index = i - 1;
    int last_value = value;

    value = last_value - last_index - 1;
    if (value < 0 || is_visited[value]) value = last_value + last_index + 1;

    is_visited[value] = true;
  }

  cout << value << '\n';
}

void problem_2() {
  // Fixed sliding window
  int k;
  int n;
  int max_sum;
  int max_idx;
  int arr[200];
  int sum = 0;
  cin >> k >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i < k)
      sum += arr[i];
    else {
      if (i == k) {
        max_sum = sum;
        max_idx = i;
      }
      sum = sum - arr[i - k] + arr[i];
    }
    if (max_sum < sum) {
      max_sum = sum;
      max_idx = i;
    }
  }

  cout << max_idx - k + 1 << " " << max_idx << " " << max_sum << "\n";
}

void problem_2_accumulation() {
  // Fixed sliding window
  int k;
  int n;
  int max_sum;
  int max_idx;
  int arr[200];
  cin >> k >> n;

  for (int i = 0; i < n; ++i) {
    int value;
    cin >> value;
    if (i == 0) {
      arr[i] = value;
    } else {
      arr[i] = value + arr[i - 1];
    }
  }

  max_sum = arr[2];
  max_idx = k - 1;
  for (int i = k; i < n; ++i) {
    if (arr[i] - arr[i - k] > max_sum) {
      max_sum = arr[i] - arr[i - k];
      max_idx = i;
    }
  }

  cout << max_idx - k + 1 << " " << max_idx << " " << max_sum << "\n";
}

void problem_3() {
  // Count increasing subarrays
  int n;
  int arr[200];
  int result{0};
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n - i; j++) {
      bool is_increasing_array = true;
      for (int k = j; k < j + i - 1; k++) {
        if (arr[k] > arr[k + 1]) is_increasing_array = false;
      }
      if (is_increasing_array) result++;
    }
  }

  cout << result << '\n';
}

void problem_3_optimized_1() {
  // Count increasing subarrays
  int n;
  int arr[200];
  int mark[199];
  cin >> n;
  int result{n};

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int mark_length = n - 1;
  for (int i = 0; i < mark_length; ++i) {
    mark[i] = arr[i] > arr[i + 1] ? -1 : 1;
  }

  int increament = 0;
  for (int i = 0; i < mark_length; ++i) {
    if (mark[i] == 1) {
      ++increament;
    } else {
      increament = 0;
    }
    result += increament;
  }

  cout << result << '\n';
}

void problem_3_optimized_2() {
  // Count increasing subarrays
  int n;
  int arr[200];
  cin >> n;
  int result{0};
  int cnt{1};

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; ++i) {
    result += cnt;
    if (arr[i - 1] < arr[i]) {
      cnt++;
    } else {
      cnt = 1;
    }
  }
  result += cnt;
  cout << result << '\n';
}

void problem_4() {
  // Josephus problem
  bool excluded[200]{false};
  int n;
  int k;
  int current = 0;
  int tmp;
  bool finished = false;
  cin >> n >> k;

  while (!finished) {
    int steps = k - 1;
    while (steps) {
      current = (current + 1) % n;
      if (!excluded[current]) {
        steps--;
      }
    }
    cout << current + 1 << " ";
    excluded[current] = true;
    tmp = current;
    while (excluded[current]) {
      current = (current + 1) % n;
      if (current == tmp) {
        finished = true;
        break;
      }
    }
  }
  cout << "\n";
}

void problem_4_optimized() {
  // Josephus problem
  bool excluded[200]{false};
  int n;
  int k;
  int current = 0;
  int tmp;
  bool finished = false;
  cin >> n >> k;
  int cnt = n;

  while (!finished) {
    int steps = (k - 1) % cnt;
    while (steps) {
      current = (current + 1) % n;
      if (!excluded[current]) {
        steps--;
      }
    }
    cout << current + 1 << " ";
    excluded[current] = true;
    tmp = current;
    cnt--;
    while (excluded[current]) {
      current = (current + 1) % n;
      if (current == tmp) {
        finished = true;
        break;
      }
    }
  }
  cout << "\n";
}

void problem_5_3_nested_loops() {
  // Longest subarray
  int arr[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int result = 0;
  int idx = 0;
  for (int len = 2; len <= n; len += 2) {
    for (int i = 0; i <= n - len; ++i) {
      int sum = 0;
      for (int j = i; j < i + len; ++j) {
        sum += arr[j];
      }
      if (sum == len / 2 && sum > result) {
        result = sum;
        idx = i;
      }
    }
  }

  result *= 2;
  cout << result << endl;
  for (int i = idx; i < idx + result; ++i) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

void problem_5_2_nested_loops() {
  // Longest subarray
  int arr[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    if (i == 0) {
      arr[i] = num;
    } else {
      arr[i] = num + arr[i - 1];
    }
  }

  int result = 0;
  int idx = 0;
  for (int len = 2; len <= n; len += 2) {
    for (int i = 0; i <= n - len; ++i) {
      int sum = 0;
      if (i == 0) {
        sum = arr[i + len - 1];
      } else {
        sum = arr[i + len - 1] - arr[i - 1];
      }
      if (sum == len / 2 && sum > result) {
        result = sum;
        idx = i;
      }
    }
  }

  result *= 2;
  cout << result << endl;
  for (int i = idx; i < idx + result; ++i) {
    int value = i ? arr[i - 1] : 0;
    cout << arr[i] - value << ' ';
  }
  cout << '\n';
}

void problem_5_1_loop() {
  // Longest subarray
  int arr[1000];
  int zeros[1000];
  int ones[1000];
  int sumDiff[1000];
  int repeated_at[2000]{};
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];

    if (arr[i] == 0) {
      zeros[i] = 1;
      ones[i] = 0;
    } else if (arr[i] == 1) {
      zeros[i] = 0;
      ones[i] = 1;
    }
    if (i > 0) {
      zeros[i] += zeros[i - 1];
      ones[i] += ones[i - 1];
    }
    sumDiff[i] = zeros[i] - ones[i];

    // Add n to prevent accessing negative index in repeated_at array
    // Initialize with -1 means first time occurance, will be updated later
    repeated_at[sumDiff[i] + n] = -1;
  }

  int result = 0;
  int idx = 0;

  for (int i = 0; i < n; ++i) {
    int value{0};

    if (sumDiff[i] == 0) {
      value = i + 1;
    } else if (repeated_at[sumDiff[i] + n] == -1) {
      repeated_at[sumDiff[i] + n] = i;
    } else {
      value = i - repeated_at[sumDiff[i] + n];
    }

    if (result < value) {
      result = value;
      idx = i - value + 1;
    }
  }

  cout << result << endl;
  for (int i = idx; i < idx + result; ++i) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_2_accumulation();
  problem_3();
  problem_3_optimized_1();
  problem_3_optimized_2();
  problem_4();
  problem_4_optimized();
  problem_5_3_nested_loops();
  problem_5_2_nested_loops();
  problem_5_1_loop();

  return 0;
}
