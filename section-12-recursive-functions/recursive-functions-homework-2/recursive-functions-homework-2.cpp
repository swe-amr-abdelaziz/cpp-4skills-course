#include <cmath>
#include <iostream>
using namespace std;

namespace Problem9 {
void rightMaxEasy(int arr[], int len, int startPosition = 0) {
  if (startPosition == len - 1) {
    return;
  }
  rightMaxEasy(arr, len, startPosition + 1);
  arr[startPosition] = max(arr[startPosition], arr[startPosition + 1]);
}

void rightMaxHard(int arr[], int len) {
  if (len == 1) {
    return;
  }
  rightMaxHard(arr + 1, len - 1);
  arr[0] = max(arr[0], arr[1]);
}
}  // namespace Problem9

namespace Problem10 {
int suffixSum(int arr[], int len, int n) {
  if (n == 0) {
    return 0;
  }
  return arr[len - 1] + suffixSum(arr, len - 1, n - 1);
}
}  // namespace Problem10

namespace Problem11 {
int prefixSumV1(int arr[], int len, int n) {
  if (n == 0) {
    return 0;
  }
  return arr[n - 1] + prefixSumV1(arr, len, n - 1);
}

int prefixSumV2(int arr[], int n) {
  if (n == 0) {
    return 0;
  }
  return arr[0] + prefixSumV2(arr + 1, n - 1);
}
}  // namespace Problem11

namespace Problem12 {
bool isPalindromeV1(int arr[], int len, int start = 0) {
  const int end = len - 1;
  if (start >= end) {
    return true;
  }
  if (arr[end] != arr[start]) {
    return false;
  }
  return isPalindromeV1(arr, end, start + 1);
}

bool isPalindromeV2(int arr[], int len) {
  const int end = len - 1;
  if (end <= 0) {
    return true;
  }
  if (arr[0] != arr[end]) {
    return false;
  }
  return isPalindromeV2(arr + 1, end - 1);
}
}  // namespace Problem12

namespace Problem13 {
bool isPrefixV1(string main, string prefix, size_t startPos = 0) {
  if (prefix.size() > main.size()) {
    return false;
  }
  if (startPos == prefix.size()) {
    return true;
  }
  if (main[startPos] != prefix[startPos]) {
    return false;
  }
  return isPrefixV1(main, prefix, startPos + 1);
}

bool isPrefixV2(string main, string prefix) {
  if (prefix.size() > main.size()) {
    return false;
  }
  if (prefix[0] == '\0') {
    return true;
  }
  if (main[0] != prefix[0]) {
    return false;
  }
  return isPrefixV2(main.substr(1), prefix.substr(1));
}
}  // namespace Problem13

namespace Problem14 {
void doSomethingV1(int n) {
  if (n) {
    cout << n % 10;
    doSomethingV1(n / 10);
  }
}

void doSomethingV2(int n) {
  if (n) {
    doSomethingV2(n / 10);
    cout << n % 10;
  }
}
}  // namespace Problem14

namespace Problem15 {
bool isPrime(int num, int mod = 2) {
  if (num < 2) {
    return false;
  }
  if (mod > sqrt(num) + 1 || num == 2) {
    return true;
  }
  if (num % mod == 0) {
    return false;
  }
  return isPrime(num, mod + 1);
}

int countPrimes(int start, int end) {
  if (start > end) {
    return 0;
  }
  return isPrime(start) + countPrimes(start + 1, end);
}
}  // namespace Problem15

namespace Problem16 {
int pathSum(int grid[100][100], int ROWS, int COLS, int row = 0, int col = 0) {
  if (row == ROWS - 1 && col == COLS - 1) {
    return grid[row][col];
  }
  if (row == ROWS - 1) {
    return grid[row][col] + pathSum(grid, ROWS, COLS, row, col + 1);
  }
  if (col == COLS - 1) {
    return grid[row][col] + pathSum(grid, ROWS, COLS, row + 1, col);
  }
  int maxRow = row + 1;
  int maxCol = col + 1;
  if (grid[maxRow][maxCol] < grid[row][col + 1]) {
    maxRow = row;
    maxCol = col + 1;
  }
  if (grid[maxRow][maxCol] < grid[row + 1][col]) {
    maxRow = row + 1;
    maxCol = col;
  }
  return grid[row][col] + pathSum(grid, ROWS, COLS, maxRow, maxCol);
}

int pathSumShorter(int grid[100][100], int ROWS, int COLS, int row = 0,
                   int col = 0) {
  int bestRow{-1};
  int bestCol{-1};
  int maxValue{};
  // Right, Diagonal, Bottom
  int di[]{0, 1, 1};
  int dj[]{1, 1, 0};

  for (int d = 0; d < 3; d++) {
    int tmpRow{row + di[d]};
    int tmpCol{col + dj[d]};
    if (tmpRow < ROWS && tmpCol < COLS) {
      if (bestRow == -1 || grid[tmpRow][tmpCol] > maxValue) {
        bestRow = tmpRow;
        bestCol = tmpCol;
        maxValue = grid[bestRow][bestCol];
      }
    }
  }
  if (bestRow == -1) {
    return grid[row][col];
  }
  return grid[row][col] + pathSumShorter(grid, ROWS, COLS, bestRow, bestCol);
}
}  // namespace Problem16

namespace Problem17 {
int fibonacci(int n) {
  // Uncomment to count how many times the function is called to get the result
  // static int counter{0};
  // cout << counter++ << '\n';
  if (n <= 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciEffecient(int n, int memory[]) {
  // Uncomment to count how many times the function is called to get the result
  static int counter{0};
  cout << counter++ << '\n';
  if (n <= 1) {
    return 1;
  }
  if (!memory[n - 1]) {
    memory[n - 1] = fibonacciEffecient(n - 1, memory);
  }
  if (!memory[n - 2]) {
    memory[n - 2] = fibonacciEffecient(n - 2, memory);
  }
  return memory[n - 1] + memory[n - 2];
}
}  // namespace Problem17

int main() {
  int arr0[]{1, 3, 5, 7, 4, 2};
  Problem9::rightMaxEasy(arr0, 6);
  for (size_t i = 0; i < 6; i++) cout << arr0[i] << ' ';
  cout << '\n';
  int arr1[]{1, 3, 5, 7, 4, 2};
  Problem9::rightMaxHard(arr1, 6);
  for (size_t i = 0; i < 6; i++) cout << arr1[i] << ' ';
  cout << '\n';

  int arr2[]{1, 3, 4, 6, 7};
  cout << Problem10::suffixSum(arr2, 5, 3) << '\n';

  cout << Problem11::prefixSumV1(arr2, 5, 3) << '\n';
  cout << Problem11::prefixSumV2(arr2, 3) << '\n';

  int arr3[]{10, 30, 20, 30, 10};
  int arr4[]{1, 2, 2, 1};
  cout << Problem12::isPalindromeV1(arr1, 6) << '\n';
  cout << Problem12::isPalindromeV1(arr2, 5) << '\n';
  cout << Problem12::isPalindromeV1(arr3, 5) << '\n';
  cout << Problem12::isPalindromeV1(arr4, 4) << '\n';
  cout << Problem12::isPalindromeV2(arr1, 6) << '\n';
  cout << Problem12::isPalindromeV2(arr2, 5) << '\n';
  cout << Problem12::isPalindromeV2(arr3, 5) << '\n';
  cout << Problem12::isPalindromeV2(arr4, 4) << '\n';

  cout << Problem13::isPrefixV1("abcdefgh", "abcd") << '\n';
  cout << Problem13::isPrefixV1("abcdefgh", "") << '\n';
  cout << Problem13::isPrefixV1("abcdefgh", "abd") << '\n';
  cout << Problem13::isPrefixV2("abcdefgh", "abcd") << '\n';
  cout << Problem13::isPrefixV2("abcdefgh", "") << '\n';
  cout << Problem13::isPrefixV2("abcdefgh", "abd") << '\n';

  Problem14::doSomethingV1(123456);
  /**
   * Output: 654321
   * The function prints the reverse of the number
   */
  cout << '\n';
  Problem14::doSomethingV2(123456);
  /**
   * Output: 123456
   * The function prints the number as it is
   */
  cout << '\n';

  cout << Problem15::countPrimes(10, 20) << '\n';
  cout << Problem15::countPrimes(2, 11) << '\n';
  cout << Problem15::countPrimes(10, 200) << '\n';

  int grid[100][100]{{1, 7, 8}, {2, 10, 11}, {20, 5, 9}};
  cout << Problem16::pathSum(grid, 3, 3) << '\n';
  cout << Problem16::pathSumShorter(grid, 3, 3) << '\n';

  cout << Problem17::fibonacci(40) << '\n';
  cout << "*****************************\n";
  int memory[1000]{0};
  cout << Problem17::fibonacciEffecient(40, memory) << '\n';

  return 0;
};
