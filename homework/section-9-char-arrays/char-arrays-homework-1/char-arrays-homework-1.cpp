#include <iostream>
#include <string>
using namespace std;

void problem_1() {
  // Is Prefix?
  string str1;
  string str2;
  cin >> str1 >> str2;

  bool is_prefix = str1.size() >= str2.size() ? true : false;
  for (size_t i = 0; i < str2.size() && is_prefix; i++) {
    if (str1[i] != str2[i]) {
      is_prefix = false;
    }
  }

  is_prefix ? cout << "YES\n" : cout << "NO\n";
}

void problem_2() {
  // Is Suffix?
  string str1;
  string str2;
  cin >> str1 >> str2;

  bool is_suffix = str1.size() >= str2.size() ? true : false;
  const size_t shift = str1.size() - str2.size();
  for (size_t i = 0; i < str2.size() && is_suffix; i++) {
    if (str1[i + shift] != str2[i]) {
      is_suffix = false;
    }
  }

  is_suffix ? cout << "YES\n" : cout << "NO\n";
}

void problem_3() {
  // Is Substring?
  string str1;
  string str2;
  cin >> str1 >> str2;

  if (str1.size() < str2.size()) {
    cout << "NO\n";
    return;
  }
  size_t limit = str1.size() - str2.size() + 1;
  bool is_substring = false;
  for (size_t i = 0; i < limit && !is_substring; i++) {
    bool result = true;
    for (size_t j = 0; j < str2.size(); j++) {
      if (str1[j + i] != str2[j]) {
        result = false;
        break;
      }
    }
    is_substring = result;
  }

  is_substring ? cout << "YES\n" : cout << "NO\n";
}

void problem_4() {
  // Is Subsequence?
  string str1;
  string str2;
  cin >> str1 >> str2;

  size_t idx = 0;
  bool is_subsequence = str1.size() >= str2.size() ? true : false;
  for (size_t i = 0; i < str1.size(); i++) {
    if (str1[i] == str2[idx]) {
      idx++;
    }
  }
  if (str2[idx] != 0) {
    is_subsequence = false;
  }

  is_subsequence ? cout << "YES\n" : cout << "NO\n";
}

void problem_5() {
  // Convert to number
  string str;
  cin >> str;
  int num = 0;
  for (size_t i = 0; i < str.size(); i++) {
    num *= 10;
    if ('0' <= str[i] && str[i] <= '9') {
      num += str[i] - '0';
    }
  }
  if (str[0] == '-') {
    num *= -1;
  }
  cout << num << ' ' << num * 3 << '\n';
}

void problem_6() {
  // Grouping
  string str;
  cin >> str;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] != str[i - 1] && i) {
      cout << ' ';
    }
    cout << str[i];
  }
  cout << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();
  problem_5();
  problem_6();

  return 0;
}
