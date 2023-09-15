#include <iostream>
#include <string>
using namespace std;

void problem_1() {
  // Compressing
  string str;
  cin >> str;
  int counter = 0;
  bool is_first = true;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == str[i + 1]) {
      counter++;
    } else {
      if (!is_first) {
        cout << '_';
      }
      cout << str[i] << counter + 1;
      counter = 0;
      is_first = false;
    }
  }
  cout << '\n';
}

void problem_2() {
  // Compare strings
  string str1;
  string str2;
  cin >> str1 >> str2;

  for (size_t i = 0; i < str1.size(); i++) {
    if (str1[i] < str2[i]) {
      cout << "YES\n";
      return;
    }
    if (str1[i] > str2[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

void problem_3() {
  // Add 5555
  string num;
  cin >> num;

  int reminder{0};
  string reversed_num = "";
  for (size_t i = 0; i < num.size(); i++) {
    if (i < 4) {
      reminder += 5;
    }
    int digit = num[num.size() - i - 1] - '0' + reminder;
    reminder = digit / 10;
    digit %= 10;
    reversed_num += (char)digit + '0';
  }
  if (reminder) {
    reversed_num += (char)reminder + '0';
  }

  num = "";
  for (size_t i = 0; i < reversed_num.size(); i++) {
    num += reversed_num[reversed_num.size() - i - 1];
  }
  cout << num << '\n';
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
