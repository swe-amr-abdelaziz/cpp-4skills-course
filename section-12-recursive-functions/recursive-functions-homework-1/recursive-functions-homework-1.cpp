#include <iostream>
using namespace std;

namespace Problem1 {
int length3nPlus1(int n) {
  if (n == 1) {
    return 1;
  }
  return 1 + (n % 2 == 0 ? length3nPlus1(n / 2) : length3nPlus1(3 * n + 1));
}
}  // namespace Problem1

namespace Problem2 {
int myPow(int value, int p = 2) {
  if (p <= 0) {
    return 1;
  }
  return value * myPow(value, p - 1);
}
}  // namespace Problem2

namespace Problem3 {
int arrMax(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }
  return max(arr[len - 1], arrMax(arr, len - 1));
}
}  // namespace Problem3

namespace Problem4 {
int sum(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }
  return arr[len - 1] + sum(arr, len - 1);
}
}  // namespace Problem4

namespace Problem5 {
double average(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }
  return (arr[len - 1] + average(arr, len - 1) * (len - 1)) / len;
}
}  // namespace Problem5

namespace Problem6 {
void arrayIncrement(int arr[], int len) {
  if (len == 1) {
    return;
  }
  arr[len - 1] += len - 1;
  arrayIncrement(arr, len - 1);
}
}  // namespace Problem6

namespace Problem7 {
void accumulationArr(int arr[], int len) {
  if (len == 1) {
    return;
  }
  accumulationArr(arr, len - 1);
  arr[len - 1] += arr[len - 2];
}
}  // namespace Problem7

namespace Problem8 {
void leftMax(int arr[], int len) {
  if (len == 1) {
    return;
  }
  leftMax(arr, len - 1);
  arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}
}  // namespace Problem8

int main() {
  cout << Problem1::length3nPlus1(5) << '\n';
  cout << Problem1::length3nPlus1(6) << '\n';
  cout << Problem1::length3nPlus1(7) << '\n';

  cout << Problem2::myPow(7, 3) << '\n';
  cout << Problem2::myPow(2, 10) << '\n';

  int arr1[]{1, 8, 2, 10, 3};
  cout << Problem3::arrMax(arr1, 5) << '\n';

  cout << Problem4::sum(arr1, 5) << '\n';

  cout << Problem5::average(arr1, 5) << '\n';

  Problem6::arrayIncrement(arr1, 5);
  for (size_t i = 0; i < 5; i++) cout << arr1[i] << ' ';
  int arr2[]{1, 2, 5, 9};
  cout << '\n';
  Problem6::arrayIncrement(arr2, 4);
  for (size_t i = 0; i < 4; i++) cout << arr2[i] << ' ';
  cout << '\n';

  int arr3[]{1, 2, 3, 4, 5, 6};
  Problem7::accumulationArr(arr3, 6);
  for (size_t i = 0; i < 6; i++) cout << arr3[i] << ' ';
  cout << '\n';

  int arr4[]{1, 3, 5, 7, 4, 2};
  Problem8::leftMax(arr4, 6);
  for (size_t i = 0; i < 6; i++) cout << arr4[i] << ' ';
  cout << '\n';

  return 0;
}
