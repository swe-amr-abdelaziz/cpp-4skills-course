#include <iostream>
using namespace std;

void problem1() {
  /* Smaller row? */

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

  // Read queries
  int q;
  cin >> q;
  while (q--) {
    int row1;
    int row2;
    cin >> row1 >> row2;
    row1--, row2--;
    bool isSmaller{true};
    for (int i = 0; i < cols; i++) {
      if (matrix[row1][i] >= matrix[row2][i]) {
        isSmaller = false;
        break;
      }
    }
    if (isSmaller) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

void problem2() {
  /* Triangular matrix */

  // Read the matrix
  int matrix[100][100];
  int n;
  cin >> n;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      cin >> matrix[row][col];
    }
  }

  // Calculate lower and upper triangle matrices sum
  int sumLowerTriangle{0};
  int sumUpperTriangle{0};
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (col <= row) {
        sumLowerTriangle += matrix[row][col];
      }
      if (col >= row) {
        sumUpperTriangle += matrix[row][col];
      }
    }
  }

  // Print results
  cout << sumLowerTriangle << '\n';
  cout << sumUpperTriangle << '\n';
}

void problem3() {
  /* Transpose */

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

  // Generate transpose matrix
  int transposeMatrix[100][100];
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      transposeMatrix[col][row] = matrix[row][col];
    }
  }

  // Print transpose matrix
  for (int row = 0; row < cols; row++) {
    for (int col = 0; col < rows; col++) {
      cout << transposeMatrix[row][col] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  problem1();
  problem2();
  problem3();

  return 0;
}
