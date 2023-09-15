#include <iostream>
using namespace std;

void problem_1() {
  // Print diamond
  int n;
  int row = 1;
  cin >> n;

  // Upper triangle
  while (row <= n) {
    int spaces = n - row;
    int stars = (2 * row) - 1;

    while (spaces > 0) {
      cout << ' ';
      spaces--;
    }
    while (stars > 0) {
      cout << '*';
      stars--;
    }

    cout << '\n';
    row++;
  }

  // Lower triangle
  while (row > 0) {
    row--;
    int spaces = n - row;
    int stars = (2 * row) - 1;

    while (spaces > 0) {
      cout << ' ';
      spaces--;
    }
    while (stars > 0) {
      cout << '*';
      stars--;
    }

    cout << '\n';
  }
}

void problem_2() {
  // Special multiples 1
  int n, iterator = 0;
  cin >> n;

  if (n < 0) {
    cout << "N cannot be negative\n";
  } else {
    while (iterator <= n) {
      if (iterator % 8 == 0 || (iterator % 4 == 0 && iterator % 3 == 0))
        cout << iterator << ' ';

      iterator++;
    }
    cout << '\n';
  }
}

void problem_3() {
  // Special nultiples 2
  int n, iterator = 0;
  cin >> n;

  while (n--) {
    if (iterator % 4 == 0)
      n++;
    else
      cout << iterator << ' ';

    iterator += 3;
  }
  cout << '\n';
}

void problem_4() {
  // Minimum of values
  int test_cases, n, num, minimum;
  bool is_first;

  cin >> test_cases;
  while (test_cases--) {
    is_first = true;

    cin >> n;
    while (n--) {
      cin >> num;
      if (is_first) {
        minimum = num;
        is_first = false;
      } else if (minimum > num)
        minimum = num;
    }

    cout << minimum << '\n';
  }
}

int main() {
  problem_1();
  problem_2();
  problem_3();
  problem_4();

  return 0;
}
