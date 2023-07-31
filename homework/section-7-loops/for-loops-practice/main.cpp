#include <iostream>
#include <string>
using namespace std;

void special_sum() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      int num;
      int added_num = 1;
      cin >> num;

      for (int j = 0; j <= i; ++j) added_num *= num;

      sum += added_num;
    }

    cout << sum << '\n';
  }
}

void pair_of_numbers() {
  int n, m, sum;
  cin >> n >> m >> sum;

  for (int a = 1; a <= n; ++a) {
    for (int b = 1; b <= m; ++b) {
      if (a + b == sum) cout << a << ' ' << b << '\n';
    }
  }
}

void pair_of_numbers_optimized() {
  int n, m, sum;
  cin >> n >> m >> sum;

  if (sum > 1) {
    int b = (m < sum) ? m : sum;
    int a = sum - b;

    while (b > 0 && a <= n) {
      cout << a++ << ' ' << b-- << '\n';
    }
  }
}

void triples_of_numbers() {
  int n, m, w;
  cin >> n >> m >> w;

  int cnt = 0;
  for (int a = 1; a <= n; ++a) {
    for (int b = a; b <= m; ++b) {
      for (int c = 1; c <= w; ++c) {
        if (a + b <= c) ++cnt;
      }
    }
  }
  cout << cnt << '\n';
}

void triples_of_numbers_optimized() {
  int n, m, w;
  cin >> n >> m >> w;

  int cnt = 0;
  for (int a = 1; a <= n; ++a) {
    for (int b = a; b <= m; ++b) {
      /**
       * 1     <= c <= w
       * a + b <= c
       * Since a starts from 1 and b starts from a then we know that a + b must
       * be greater than 1
       *
       * So:
       * a + b <= c <= w
       * c = w - (a + b) + 1
       * the extra 1 here for counting, for instance if you count number of
       * pages from 1 to 10, you will find out that there are 10 pages as:
       * no_of_pages = (10 - 1) + 1
       */

      int c = w - (a + b) + 1;
      if (c > 0) cnt += c;
    }
  }
  cout << cnt << '\n';
}

void fibonacci_sequence() {
  int n;
  int last = 1;
  int before_last = 0;
  cin >> n;
  n -= 2;  // As we already know the first 2 numbers in the sequence
  cout << before_last << ' ' << last;

  // Using for loop
  for (int i = 0; i < n; ++i) {
    last = last + before_last;
    before_last = last - before_last;
    cout << ' ' << last;
  }

  cout << '\n';
}

namespace WhileLoopsPractice {
void numbers_divisible_by_3() {
  int x;
  cin >> x;

  for (int i = 1; i <= x; ++i) {
    if (i % 3 == 0) cout << i << ' ';
  }
}

void power_function() {
  int x, y;
  int result = 1;
  cin >> x >> y;

  for (int i = 0; i < y; ++i) result *= x;

  cout << result << '\n';
}

void number_of_digits() {
  int num;
  int count = 1;
  cin >> num;

  for (int i = 1; num != 0; ++i) {
    num /= 10;
    count = i;
  }

  cout << count << '\n';
}

void nested_loop() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    int sum = 0;
    cin >> n;

    for (int j = 1; j <= n; ++j) sum += j;

    cout << "Sum from 1 to " << n << " = " << sum << '\n';
  }
}
}  // namespace WhileLoopsPractice

namespace WhileLoopsHomework1 {
void problem_1() {
  // Print Range
  int x, y;
  cin >> x >> y;

  if (x < y) {
    for (int i = x; i <= y; ++i) cout << i << '\n';
  } else {
    for (int i = x; i >= y; --i) cout << i << '\n';
  }
}

void problem_2() {
  // Line Of Characters
  int n;
  char ch;
  cin >> n >> ch;

  for (int i = 0; i < n; ++i) cout << ch;
  cout << '\n';
}

void problem_3() {
  // Print left angled triangle
  int n;
  cin >> n;

  for (int row = 0; row < n; ++row) {
    for (int col = 0; col <= row; col++) {
      cout << '*';
    }
    cout << '\n';
  }
}

void problem_4() {
  // Print face down left angled triangle
  int n;
  cin >> n;

  for (int row = 0; row < n; ++row) {
    for (int col = n; col > row; --col) {
      cout << '*';
    }
    cout << '\n';
  }
}

void problem_5() {
  // Special Average
  int n;
  int value;
  double odd_sum = 0;
  double even_sum = 0;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> value;
    if (i % 2 == 0)
      even_sum += value;
    else
      odd_sum += value;
  }

  int odd_count = (n % 2 == 0) ? n / 2 : (n / 2) + 1;
  int even_count = n / 2;
  cout << odd_sum / odd_count << " ";
  cout << even_sum / even_count << "\n";
}
}  // namespace WhileLoopsHomework1

namespace WhileLoopsHomework2 {
void problem_1() {
  // Print diamond
  int n;
  cin >> n;

  // Upper triangle
  for (int row = 1; row <= n; ++row) {
    int stars = 2 * row - 1;
    int spaces = n - row;

    for (int col = 0; col < spaces; ++col) cout << ' ';
    for (int col = 0; col < stars; ++col) cout << '*';

    cout << '\n';
  }

  // Lower triangle
  for (int row = n; row > 0; --row) {
    int stars = 2 * row - 1;
    int spaces = n - row;

    for (int col = 0; col < spaces; ++col) cout << ' ';
    for (int col = 0; col < stars; ++col) cout << '*';

    cout << '\n';
  }
}

void problem_2() {
  // Special multiplies 1
  int n;
  cin >> n;

  for (int i = 0; i <= n; ++i) {
    if (i % 8 == 0 || (i % 4 == 0 && i % 3 == 0)) cout << i << ' ';
  }
}

void problem_3() {
  // Special multiplies 2
  int n;
  int count = 0;
  cin >> n;

  for (int i = 0; count < n; i += 3) {
    if (i % 4 != 0) {
      cout << i << ' ';
      count++;
    }
  }
  cout << '\n';
}

void problem_4() {
  // Minimum of values
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    int num, min;
    cin >> n;

    for (int j = 0; j < n; ++j) {
      cin >> num;
      if (j == 0)
        min = num;
      else {
        if (min > num) min = num;
      }
    }

    cout << min << '\n';
  }
}
}  // namespace WhileLoopsHomework2

namespace WhileLoopsHomework3 {
string toLowerCase(string str) {
  string result = "";
  int tweak;
  size_t pos = 0;
  while (str[pos] != '\0') {
    tweak = 0;
    if (str[pos] >= 65 && str[pos] <= 90) {
      tweak = 32;
    }
    result += (str[pos] + (char)tweak);
    pos++;
  }
  return result;
}

bool validString(string str) {
  string result = toLowerCase(str);
  return (result == "no" || result == "on");
}

void problem_1_using_functions() {
  // Find NOs
  int n;
  string str;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> str;
    if (validString(str)) cout << str << ' ';
  }
  cout << '\n';
}

void problem_1() {
  // Find NOs
  int n;
  string str;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> str;
    if (str == "no" || str == "NO" || str == "nO" || str == "No" ||
        str == "on" || str == "ON" || str == "oN" || str == "On")
      cout << str << ' ';
  }
  cout << '\n';
}

void problem_2() {
  // Reverse number
  int n, reverse;
  cin >> n;

  for (reverse = 0; n != 0; n /= 10) {
    reverse = (reverse * 10) + (n % 10);
  };

  cout << reverse << ' ' << reverse * 3 << '\n';
}

void problem_3() {
  // Multiplication table
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cout << i << " x " << j << " = " << i * j << '\n';
}

void problem_4() {
  // Special Sum
  int t;
  cin >> t;

  int n, num, result, sum;
  for (int i = 0; i < t; ++i) {
    sum = 0;

    cin >> n;
    for (int j = 1; j <= n; ++j) {
      result = 1;
      cin >> num;
      for (int k = 0; k < j; ++k) {
        result *= num;
      }
      sum += result;
    }
    cout << sum << '\n';
  }
}
}  // namespace WhileLoopsHomework3

int main() {
  special_sum();
  pair_of_numbers();
  pair_of_numbers_optimized();
  triples_of_numbers();
  triples_of_numbers_optimized();
  fibonacci_sequence();

  WhileLoopsPractice::numbers_divisible_by_3();
  WhileLoopsPractice::power_function();
  WhileLoopsPractice::number_of_digits();
  WhileLoopsPractice::nested_loop();

  WhileLoopsHomework1::problem_1();
  WhileLoopsHomework1::problem_2();
  WhileLoopsHomework1::problem_3();
  WhileLoopsHomework1::problem_4();
  WhileLoopsHomework1::problem_5();

  WhileLoopsHomework2::problem_1();
  WhileLoopsHomework2::problem_2();
  WhileLoopsHomework2::problem_3();
  WhileLoopsHomework2::problem_4();

  WhileLoopsHomework3::problem_1_using_functions();
  WhileLoopsHomework3::problem_1();
  WhileLoopsHomework3::problem_2();
  WhileLoopsHomework3::problem_3();
  WhileLoopsHomework3::problem_4();

  return 0;
}
