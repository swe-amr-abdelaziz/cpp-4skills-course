#include <math.h>

#include <iostream>
using namespace std;

void problem_1() {
  // Printing X
  int n;
  cin >> n;

  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; ++col) {
      if (row == col || row == n - col - 1)
        cout << '*';
      else
        cout << ' ';
    }
    cout << '\n';
  }
}

void problem_2() {
  // Find Special Pairs
  int cnt = 0;

  for (int x = 50; x <= 300; ++x) {
    for (int y = 70; y <= 400; ++y) {
      if (x < y && (x + y) % 7 == 0) ++cnt;
    }
  }

  cout << cnt << '\n';
}

void problem_2_optimized() {
  // Find Special Pairs
  int cnt = 0;

  for (int y = 70; y <= 400; ++y) {
    int start = 50;
    start -= (start + y) % 7;
    if (start < 50) start += 7;

    for (int x = start; x <= 300 && x < y; x += 7) ++cnt;
  }

  cout << cnt << '\n';
}

void problem_3() {
  // Find all quadruples
  int cnt = 0;

  for (int a = 1; a <= 200; ++a) {
    for (int b = 1; b <= 200; ++b) {
      for (int c = 1; c <= 200; ++c) {
        for (int d = 1; d <= 200; ++d) {
          if (a + b == c + d) ++cnt;
        }
      }
    }
  }

  cout << cnt << '\n';
}

void problem_3_optimized() {
  // Find all quadruples
  int cnt = 0;

  for (int a = 1; a <= 200; ++a) {
    for (int b = 1; b <= 200; ++b) {
      for (int c = 1; c <= 200; ++c) {
        int d = a + b - c;
        if (1 <= d && d <= 200) ++cnt;
      }
    }
  }

  cout << cnt << '\n';
}

void problem_4() {
  // Is Prime?
  int n;
  cin >> n;

  bool is_prime = true;
  if (n < 2)
    is_prime = false;
  else if (n != 2) {
    for (int i = 2; i <= ceil(sqrt(n)) && is_prime; ++i) {
      if (n % i == 0) is_prime = false;
    }
  }

  is_prime ? cout << "YES\n" : cout << "NO\n";
}

void problem_5() {
  // Print Primes
  int n;
  cin >> n;

  bool is_first = true;
  for (int i = 2; i <= n; ++i) {
    bool is_prime = true;
    if (i != 2) {
      for (int j = 2; j <= ceil(sqrt(i)) && is_prime; ++j) {
        if (i % j == 0) is_prime = false;
      }
    }
    if (is_prime) {
      if (is_first)
        is_first = false;
      else
        cout << ",";

      cout << i;
    }
  }
  cout << '\n';
}

void problem_6() {
  // Digits sum in range
  int n, a, b;
  cin >> n >> a >> b;

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int digits_sum = 0;
    int tmp = i;
    while (tmp) {
      digits_sum += tmp % 10;
      tmp /= 10;
    }
    if (a <= digits_sum && digits_sum <= b) sum += i;
  }
  cout << sum << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_2_optimized();
  problem_3();
  problem_3_optimized();
  problem_4();
  problem_5();
  problem_6();

  return 0;
}
