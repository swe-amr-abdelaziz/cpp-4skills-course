#include <iostream>
using namespace std;

void problem1() {
  /* Max value */

  // Read the matrix
  int rows;
  int cols;
  int arr[100][100];
  cin >> rows >> cols;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> arr[row][col];
    }
  }

  // Get last occurance of max value in the matrix
  int maxRow = 0;
  int maxCol = 0;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (arr[row][col] >= arr[maxRow][maxCol]) {
        maxRow = row;
        maxCol = col;
      }
    }
  }

  // Print the results
  cout << "Max value at position " << maxRow << ' ' << maxCol
       << " with value = " << arr[maxRow][maxCol] << '\n';
}

void problem2() {
  /* Special print */

  // Read the matrix
  int rows;
  int cols;
  int arr[100][100];
  cin >> rows >> cols;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> arr[row][col];
    }
  }

  // Left diagonal sum
  int sum{0};
  int row{0};
  int col{0};
  bool stillInBoundaries = true;
  while (stillInBoundaries) {
    sum += arr[row][col];
    row++;
    col++;
    stillInBoundaries = row < rows && col < cols;
  }
  cout << sum << " ";

  // Right diagonal sum
  sum = 0;
  row = 0;
  col = cols - 1;
  stillInBoundaries = true;
  while (stillInBoundaries) {
    sum += arr[row][col];
    row++;
    col--;
    stillInBoundaries = row < rows && col >= 0;
  }
  cout << sum << "\n";

  // Last row sum
  sum = 0;
  row = rows - 1;
  col = 0;
  stillInBoundaries = true;
  while (stillInBoundaries) {
    sum += arr[row][col];
    col++;
    stillInBoundaries = col < cols;
  }
  cout << sum << " ";

  // Last column sum
  sum = 0;
  row = 0;
  col = cols - 1;
  stillInBoundaries = true;
  while (stillInBoundaries) {
    sum += arr[row][col];
    row++;
    stillInBoundaries = row < rows;
  }
  cout << sum << "\n";
}

void problem3() {
  /* Swap 2 columns */

  // Read the matrix
  int rows;
  int cols;
  int arr[100][100];
  cin >> rows >> cols;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> arr[row][col];
    }
  }

  // Swap col1 and col2
  int col1;
  int col2;
  cin >> col1 >> col2;
  for (int row = 0; row < rows; row++) {
    int tmpNum = arr[row][col1];
    arr[row][col1] = arr[row][col2];
    arr[row][col2] = tmpNum;
  }

  // Print the results
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cout << arr[row][col] << " ";
    }
    cout << "\n";
  }
}

int main() {
  problem1();
  problem2();
  problem3();

  return 0;
}
