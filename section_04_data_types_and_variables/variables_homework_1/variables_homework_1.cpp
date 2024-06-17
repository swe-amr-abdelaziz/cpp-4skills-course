#include <iostream>
using namespace std;

void problem_1()
{
    // Math operations
    int a, b;
    cin >> a >> b;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
}

void problem_2()
{
    // Students grades
    string name1, name2;
    int id1, id2;
    double grade1, grade2;

    cout << "What is student 1 name: ";
    cin >> name1;
    cout << "His id: ";
    cin >> id1;
    cout << "His math exam grade: ";
    cin >> grade1;

    cout << "What is student 2 name: ";
    cin >> name2;
    cout << "His id: ";
    cin >> id2;
    cout << "His math exam grade: ";
    cin >> grade2;

    cout << "Students grades in math\n";
    cout << name1 << " (with id " << id1 << ") got grade: " << grade1 << "\n";
    cout << name2 << " (with id " << id2 << ") got grade: " << grade2 << "\n";
    cout << "Average grade is " << (grade1 + grade2) / 2 << "\n";
}

void problem_3()
{
    // Even and Odd sum
    int even1, even2, even3, even4, odd1, odd2, odd3, odd4;
    cin >> odd1 >> even1 >> odd2 >> even2 >> odd3 >> even3 >> odd4 >> even4;
    cout << even1 + even2 + even3 + even4 << " " << odd1 + odd2 + odd3 + odd4;
}
