#include <iostream>
using namespace std;

void problem1() {
  /* How many primes */

  // Read the matrix
  int prime[100][100]{0};
  int rows;
  int cols;
  int value;
  cin >> rows >> cols;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cin >> value;
      if (value < 2) {
        prime[row][col] = 0;
      } else {
        prime[row][col] = 1;
        for (int i = 2; i < value; i++) {
          if (value % i == 0) {
            prime[row][col] = 0;
            continue;
          }
        }
      }
    }
  }

  // Read queries
  int q;
  cin >> q;
  while (q--) {
    int i, j, r, c;
    int count{0};
    cin >> i >> j >> r >> c;
    for (int row = i; row < i + r; row++) {
      for (int col = j; col < j + c; col++) {
        count += prime[row][col];
      }
    }
    cout << count << '\n';
  }
}

void problem2() {
  /* Find mountains */

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

  // Output all mountains
  int di[8]{-1, -1, 0, 1, 1, 1, 0, -1};
  int dj[8]{0, 1, 1, 1, 0, -1, -1, -1};
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      bool isMountain{true};
      for (int d = 0; d < 8; d++) {
        int dx = row + di[d];
        int dy = col + dj[d];
        bool pointInRange = !(dx < 0 || dx >= rows || dy < 0 || dy >= cols);
        if (pointInRange && matrix[row][col] <= matrix[dx][dy]) {
          isMountain = false;
          break;
        }
      }
      if (isMountain) {
        cout << row << ' ' << col << '\n';
      }
    }
  }
}

void problem3() {
  /* Active Robot */

  int rows;
  int cols;
  int k;
  cin >> rows >> cols >> k;
  int row{0};
  int col{0};

  while (k--) {
    int direction;
    int steps;
    cin >> direction >> steps;
    switch (direction) {
      case 1:
        steps %= rows;
        row -= steps;
        if (row < 0) {
          row += rows;
        }
        break;
      case 2:
        steps %= cols;
        col += steps;
        if (col >= cols) {
          col -= cols;
        }
        break;
      case 3:
        steps %= rows;
        row += steps;
        if (row >= rows) {
          row -= rows;
        }
        break;
      case 4:
        steps %= rows;
        col -= steps;
        if (col < 0) {
          col += cols;
        }
    }
    cout << "(" << row << ", " << col << ")\n";
  }
}

void problem3Shorter() {
  /* Active Robot */

  int rows;
  int cols;
  int k;
  cin >> rows >> cols >> k;
  int row{0};
  int col{0};

  // Up, Right, Down, Left
  int di[]{-1, 0, 1, 0};
  int dj[]{0, 1, 0, -1};

  while (k--) {
    int direction;
    int steps;
    cin >> direction >> steps;
    row = (row + di[direction - 1] * steps) % rows;
    col = (col + dj[direction - 1] * steps) % cols;

    if (row < 0) row += rows;
    if (col < 0) col += cols;

    cout << "(" << row << ", " << col << ")\n";
  }
}

void problem4() {
  /* Flatten 3D Array */

  int depth;
  int rows;
  int cols;
  int choice;
  cin >> depth >> rows >> cols >> choice;

  switch (choice) {
    case 1:
      int d, r, c;
      cin >> d >> r >> c;
      cout << d * rows * cols + r * cols + c << '\n';
      break;
    case 2:
      int idx;
      cin >> idx;
      d = idx / (rows * cols);
      idx %= (rows * cols);
      r = idx / cols;
      idx %= cols;
      c = idx;
      cout << d << ' ' << r << ' ' << c << '\n';
  }
}

int main() {
  // problem1();
  // problem2();
  // problem3();
  problem3Shorter();
  // problem4();

  return 0;
}
