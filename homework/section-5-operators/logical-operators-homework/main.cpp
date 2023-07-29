#include <iostream>
using namespace std;

void problem_1() {
  // Guess the output
  int a = 10, b = 20, c = 30, d = 40;

  cout << (a + b == c) << "\n";  // 10 + 20 == 30
  cout << (a + b + c >= 2 * d) << "\n";
  /*
   * 10 + 20 + 30 >= 2 * 40
   * 60 >= 80
   */

  cout << (a > 5 || d < 30) << "\n";   // T || whatever = T
  cout << (a > 5 && d < 30) << "\n";   // T && F = F
  cout << (a <= b && b <= c) << "\n";  // T && T = T

  cout << ((a > 5 && d < 30) || c - b == 10) << "\n";
  /*
   * (a > 5 && d < 30 || 10 == 10)
   * T && F || T
   * F || T
   * T
   */
  cout << (a <= b && b <= c && c <= d) << "\n";
  /*
   * T && T && T
   * T
   */

  cout << ((a > 5 && d < 30) || c > d || d % 2 == 0) << "\n";
  /*
   * T && F || F || T
   * F || F || T
   * T
   */

  cout << ((a > 5 && d < 30) || (c > d && d % 2 == 0)) << "\n";
  /*
   * T && F || F && whatever
   * F || F
   * F
   */

  cout << (a == 10 || (b != 20 && c != 30) || d != 40) << "\n";
  /*
   * T || whatever
   * T
   */

  cout << (((a == 10 || b != 20) && c != 30) || d != 40) << "\n";
  /*
   * (T || whatever) && F || F
   * T && F || F
   * F || F
   * F
   */

  /*
   * Output:
   * 1
   * 0
   * 1
   * 0
   * 1
   * 1
   * 1
   * 1
   * 0
   * 1
   * 0
   *
   */
}

void problem_2() {
  // Create logic!
  // Write a program that reads 3 integers about the class room
  // Number of boys (nb), number of girls (ng), number of teachers (nt)
  int nb, ng, nt;
  cin >> nb >> ng >> nt;

  // Prepare and print a boolean variable for these cases:
  // nb greater than 25
  cout << (nb > 25) << endl;

  // ng less than or equal to 30
  cout << (ng <= 30) << endl;

  // nb > 20 and nt > 2 or ng > 30 and nt > 4
  cout << ((nb > 20 && nt > 2) || (ng > 30 && nt > 4)) << endl;

  // Either nb < 60 or ng < 70
  cout << (nb < 60 || ng < 70) << endl;

  // Neither nb >= 60 nor ng >= 70
  cout << (!(nb >= 60) && !(ng >= 70)) << endl;

  // nb is 10 more students than ng
  cout << (nb == ng + 10) << endl;

  // Difference between nb and ng is more than 10 or nt > 5
  cout << (nb - ng > 10 || nt > 5) << endl;

  // Either nb is 10 more students than ng or ng is 15 more students than nb
  cout << (nb == ng + 10 || ng == nb + 15) << endl;
}

void problem_3() {
  // Simplify expressions
  /*
   * For each expression:
   * Manually Simplify it step by step to finally be a T or F
   * Optional: Write a line of code to verify the result
   */
  int T = 1, F = 0;

  /*
   * T && T && F && T
   * F
   */
  cout << (T && T && F && T) << endl;

  /*
   * T && T && F && T || T && T
   * F || T
   * T
   */
  cout << ((T && T && F && T) || (T && T)) << endl;

  /*
   * T && T && T && T || T && (T || F)
   * T || whatever
   * T
   */
  cout << ((T && T && T && T) || (T && (T || F))) << endl;

  /*
   * T && T && T || T && (F || (T && (T && T)))
   * T || whatever
   * T
   */
  cout << ((T && T && T) || (T && (F || (T && (T && T))))) << endl;

  /*
   * T && T || T && F && T || T && T && F || (T && (T || F))
   * T || whatever
   * T
   */
  cout << ((T && T) || (T && F && T) || (T && T && F) || (T && (T || F))) << endl;

  /*
   * T && T || T && F && T || (T && T && F || (T && (T || F)))
   * T || whatever
   * T
   */
  cout << ((T && T) || (T && F && T) || ((T && T && F) || (T && (T || F)))) << endl;

  /*
   * (T && T || T && F && T || T) && T && F || (T && (T || F))
   * (T || whatever) && T && F || (T && T)
   * T && T && F || T
   * F || T
   * T
   */
  cout << ((((T && T) || (T && F && T) || T) && T && F) || (T && (T || F))) << endl;

  /*
   * T && T || T && (F && T || T && T) && F || (T && (T || F))
   * T || whatever
   * T
   */
  cout << ((T && T) || (T && ((F && T) || (T && T)) && F) || (T && (T || F))) << endl;

  /*
   * Output:
   * 0
   * 1
   * 1
   * 1
   * 1
   * 1
   * 1
   * 1
   */
}

int main() {
  problem_1();
  problem_2();
  problem_3();

  return 0;
}
