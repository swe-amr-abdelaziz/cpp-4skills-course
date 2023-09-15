#include <iostream>
using namespace std;

void print3nPlus1(int n) {
  cout << n << ' ';
  if (n == 1) {
    cout << '\n';
    return;
  }
  n % 2 == 0 ? print3nPlus1(n / 2) : print3nPlus1(3 * n + 1);
}

int main() {
  print3nPlus1(5);
  print3nPlus1(6);
  print3nPlus1(7);
  return 0;
}
