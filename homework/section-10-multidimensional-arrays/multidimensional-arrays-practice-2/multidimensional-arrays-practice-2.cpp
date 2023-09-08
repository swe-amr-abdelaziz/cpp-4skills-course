#include <iostream>
using namespace std;

void problem1() {
  /* Greedy Robot */

  // Read the matrix
  int matrix[100][100];
  size_t rows;
  size_t cols;
  cin >> rows >> cols;
  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < cols; col++) {
      cin >> matrix[row][col];
    }
  }

  // Collecting points
  size_t row{0};
  size_t col{0};
  int points{matrix[0][0]};
  size_t maxRow{0};
  size_t maxCol{0};
  int maxPoint{0};
  while (row + 1 < rows || col + 1 < cols) {
    if (row + 1 < rows && col + 1 < cols) {
      maxPoint = matrix[row + 1][col + 1];
      maxRow = row + 1;
      maxCol = col + 1;
      if (maxPoint < matrix[row][col + 1]) {
        maxPoint = matrix[row][col + 1];
        maxRow = row;
        maxCol = col + 1;
      }
      if (maxPoint < matrix[row + 1][col]) {
        maxPoint = matrix[row + 1][col];
        maxRow = row + 1;
        maxCol = col;
      }
    } else if (row + 1 < rows) {
      maxPoint = matrix[row + 1][col];
      maxRow = row + 1;
    } else if (col + 1 < cols) {
      maxPoint = matrix[row][col + 1];
      maxCol = col + 1;
    }
    points += maxPoint;
    row = maxRow;
    col = maxCol;
  }

  cout << points << '\n';
}

void problem1Shorter() {
  /* Greedy Robot */

  // Read the matrix
  int matrix[100][100];
  int rows;
  int cols;
  cin >> rows >> cols;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> matrix[row][col];
    }
  }

  // Collecting points
  int row{0};
  int col{0};
  int di[]{0, 1, 1};  // Right, Diagonal, Bottom
  int dj[]{1, 1, 0};  // Right, Diagonal, Bottom
  int points{0};
  while (row < rows && col < cols) {
    points += matrix[row][col];
    int bestRow{-1};
    int bestCol{-1};

    for (int n = 0; n < 3; n++) {
      if (row + di[n] < rows && col + dj[n] < cols) {
        if (bestRow == -1 ||
            matrix[bestRow][bestCol] < matrix[row + di[n]][col + dj[n]]) {
          bestRow = row + di[n];
          bestCol = col + dj[n];
        }
      }
    }

    if (bestRow == -1) {
      break;
    }
    row = bestRow;
    col = bestCol;
  }

  cout << points << '\n';
}

int main() {
  problem1();
  problem1Shorter();

  return 0;
}
