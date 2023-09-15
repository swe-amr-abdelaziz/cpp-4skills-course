#include <math.h>

#include <iostream>
using namespace std;

int main() {
  /* Tic Tac Toe */

  // Initialize game
  char board[9][9];
  int n;
  cout << "Enter board dimensions: ";
  cin >> n;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      board[row][col] = '.';
    }
  }

  char player;
  bool turn{true};
  int locationRow;
  int locationCol;
  bool invalidLocationRow;
  bool invalidLocationCol;
  bool invalidInput;

  for (int round = 0; round < n * n; round++) {
    player = turn ? 'x' : 'o';

    // Get Input
    do {
      cout << "Player " << player << " turn. Enter empty location (r, c): ";
      do {
        cin >> locationRow;
        if (locationRow < 1 || locationRow > n) {
          cout << "Row out of range, try again: ";
          invalidLocationRow = true;
        } else {
          invalidLocationRow = false;
        }
      } while (invalidLocationRow);
      do {
        cin >> locationCol;
        if (locationCol < 1 || locationCol > n) {
          cout << "Col out of range, try again: ";
          invalidLocationCol = true;
        } else {
          invalidLocationCol = false;
        }
      } while (invalidLocationCol);
      locationRow--;
      locationCol--;
      if (board[locationRow][locationCol] != '.') {
        cout << "Invalid input, try again\n";
        invalidInput = true;
      } else {
        invalidInput = false;
      }
    } while (invalidInput);

    // Print Board
    board[locationRow][locationCol] = player;
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        cout << board[row][col];
      }
      cout << '\n';
    }

    // Check Winner
    // Right, Down, Diagonal1, Diagonal2
    int di[]{0, 1, 1, -1};
    int dj[]{1, 0, 1, 1};
    int upperBound = n;
    int rowDestination = n;
    int colDestination = n;
    bool isWinner;

    for (int d = 0; d < 4; d++) {
      locationRow = 0;
      locationCol = 0;
      if (d == 2) {
        upperBound = 1;
      }
      if (d == 3) {
        locationRow = n - 1;
        rowDestination = -1;
      }
      isWinner = false;

      for (int i = 0; i < upperBound && !isWinner; i++) {
        while (locationRow != rowDestination && locationCol != colDestination) {
          isWinner = true;
          if (board[locationRow][locationCol] != player) {
            isWinner = false;
            break;
          }
          locationRow += di[d];
          locationCol += dj[d];
        }
        if (di[d] == 0) {
          locationRow++;
          locationCol = 0;
        }
        if (dj[d] == 0) {
          locationRow = 0;
          locationCol++;
        }
      }

      if (isWinner) {
        cout << "Player " << player << " won\n";
        return 0;
      }
    }

    // Switch Players
    turn = !turn;
  }

  cout << "Tie\n";
  return 0;
}
