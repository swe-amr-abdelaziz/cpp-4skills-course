#include <iostream>
using namespace std;

void problem_1() {
  // Math operations
  double x, y;
  cin >> x >> y;

  cout << x << " + " << y << " = " << x + y << endl;
  cout << x << " - " << y << " = " << x - y << endl;
  cout << x << " / " << y << " = " << x / y << endl;
  cout << x << " * " << y << " = " << x * y << endl;
}

void problem_2() {
  // Students grades

  // Student 1 data
  string name_1;
  cout << "What is student 1 name: ";
  cin >> name_1;

  int id_1;
  cout << "His id: ";
  cin >> id_1;

  double grade_1;
  cout << "His math exam grade: ";
  cin >> grade_1;

  // Student 2 data
  string name_2;
  cout << "What is student 2 name: ";
  cin >> name_2;

  int id_2;
  cout << "His id: ";
  cin >> id_2;

  double grade_2;
  cout << "His math exam grade: ";
  cin >> grade_2;

  // Print students data
  cout << "\nStudents grades in math\n";
  cout << name_1 << " (with id " << id_1 << ") got grade: " << grade_1 << endl;
  cout << name_2 << " (with id " << id_2 << ") got grade: " << grade_2 << endl;
  cout << "Average grade is " << (grade_1 + grade_2) / 2.0 << endl;
}

void problem_3() {
  // Even and Odd sum

  // 'e' stands for even and 'o' stands for odd
  int e1, e2, e3, e4, o1, o2, o3, o4;

  cin >> o1 >> e1 >> o2 >> e2 >> o3 >> e3 >> o4 >> e4;

  int evenSum = e1 + e2 + e3 + e4;
  int oddSum = o1 + o2 + o3 + o4;

  cout << evenSum << ' ' << oddSum << endl;
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
