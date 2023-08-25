#include <iostream>
#include <string>
using namespace std;

void conc_strings() {
  string S;
  string T;
  size_t s_idx{0};
  size_t t_idx{0};
  cin >> S >> T;

  while (S[s_idx] || T[t_idx]) {
    if (S[s_idx]) {
      cout << S[s_idx];
      s_idx++;
    }
    if (T[t_idx]) {
      cout << T[t_idx];
      t_idx++;
    }
  }

  cout << '\n';
}

void letters_frequency() {
  const int SIZE = 26;
  int freq[SIZE]{0};
  string str;
  cin >> str;

  for (size_t i = 0; i < str.size(); ++i) {
    if ('a' <= str[i] && str[i] <= 'z') {
      freq[str[i] - 'a']++;
    }
  }

  for (size_t i = 0; i < SIZE; ++i) {
    if (freq[i]) {
      cout << (char)(i + 'a') << ' ' << freq[i] << '\n';
    }
  }
}

void special_string_mapping() {
  string lower_letters_map{"YZIMNESTODUAPWXHQFBRJKCGVL"};
  string digits_map{"!@#$%^&*()"};
  string str;
  cin >> str;

  for (size_t i = 0; i < str.size(); ++i) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      cout << str[i];
    } else if ('a' <= str[i] && str[i] <= 'z') {
      size_t idx = (size_t)str[i] - 'a';
      cout << lower_letters_map[idx];
    } else if ('0' <= str[i] && str[i] <= '9') {
      size_t idx = (size_t)str[i] - '0';
      cout << digits_map[idx];
    }
  }
  cout << '\n';
}

void special_string_mapping_lecture_solution() {
  string from = "abcdefghijklmnopqrstuvwxyz0123456789";
  string to = "YZIMNESTODUAPWXHQFBRJKCGVL!@#$%^&*()";

  char map[128];
  for (size_t i = 0; i < from.size(); ++i) {
    map[(size_t)from[i]] = to[i];
  }

  string str;
  cin >> str;

  for (size_t i = 0; i < str.size(); ++i) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      cout << str[i];
    } else if (('a' <= str[i] && str[i] <= 'z') ||
               ('0' <= str[i] && str[i] <= '9')) {
      cout << map[(size_t)str[i]];
    }
  }
  cout << '\n';
}

int main() {
  conc_strings();
  letters_frequency();
  special_string_mapping();
  special_string_mapping_lecture_solution();

  return 0;
}
