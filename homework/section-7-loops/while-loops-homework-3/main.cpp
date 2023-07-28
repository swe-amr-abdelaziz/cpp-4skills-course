#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string str) {
  string result = "";
  int tweak, pos = 0;
  while (str[pos] != '\0') {
    tweak = 0;
    if (str[pos] >= 65 && str[pos] <= 90) {
      tweak = 32;
    }
    result += (str[pos] + tweak);
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

  while (n--) {
    cin >> str;
    if (validString(str)) cout << str << ' ';
  }
}

void problem_1() {
  // Find NOs
  int n;
  string str;
  cin >> n;

  while (n--) {
    cin >> str;
    if (str == "no" || str == "NO" || str == "nO" || str == "No" ||
        str == "on" || str == "ON" || str == "oN" || str == "On")
      cout << str << ' ';
  }
}

void problem_2() {
  // Reverse number
  int n, reverse = 0;
  cin >> n;

  while (n) {
    reverse *= 10;
    reverse += n % 10;
    n /= 10;
  }

  cout << reverse << ' ' << reverse * 3 << '\n';
}

void problem_3() {
  // Multiplication table
  int n, m;
  cin >> n >> m;

  int n_cnt = 1, m_cnt = 1;

  while (n_cnt <= n) {
    m_cnt = 1;
    while (m_cnt <= m) {
      cout << n_cnt << " x " << m_cnt << " = " << n_cnt * m_cnt << '\n';
      m_cnt++;
    }
    n_cnt++;
  }
}

void problem_4() {
  // Special Sum
  int t;
  cin >> t;

  int n, num, pos, current_pos, result, sum;
  while (t--) {
    pos = 1;
    sum = 0;

    cin >> n;
    while (pos <= n) {
      result = 1;
      cin >> num;
      current_pos = pos;
      while (current_pos--) {
        result *= num;
      }
      sum += result;
      pos++;
    }
    cout << sum << '\n';
  }
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();

  return 0;
}
