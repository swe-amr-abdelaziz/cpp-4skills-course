#include <iostream>
#include <string>
using namespace std;

int main() {
  // Employee Program (v1)
  string main_menu =
      "Enter your choice:\n1) Add new employee\n2) Print all employees\n3) "
      "Delete by age\n4) Update Salary by name\n";
  const int SIZE = 200;
  string name[SIZE];
  int age[SIZE];
  double salary[SIZE];
  char gender[SIZE];
  bool is_used[SIZE]{false};

  while (true) {
    string choice_str{};
    int choice{0};
    cout << main_menu;
    cin >> choice_str;

    try {
      choice = stoi(choice_str);
    } catch (...) {
    }

    switch (choice) {
      case 1:
        // Add new employee
        for (size_t i = 0; i < SIZE; i++) {
          if (!is_used[i]) {
            cout << "Enter name: ";
            cin.ignore(256, '\n');
            getline(cin, name[i]);

            cout << "Enter age: ";
            string age_str{};
            bool valid{false};
            do {
              cin >> age_str;
              try {
                age[i] = stoi(age_str);
              } catch (...) {
                cout << "Invalid input, please enter a number for age\n";
                continue;
              }
              if (age[i] < 18 || age[i] > 200) {
                cout << "Age should be between 18 and 200 years\n";
                valid = false;
              } else {
                valid = true;
              }
            } while (!valid);

            cout << "Enter salary: ";
            string salary_str{};
            do {
              cin >> salary_str;
              try {
                salary[i] = stod(salary_str);
              } catch (...) {
                cout << "Invalid input, please enter a float for salary\n";
                valid = false;
                continue;
              }
              if (salary[i] < 0) {
                cout << "Salary cannot be negative\n";
                valid = false;
              } else {
                valid = true;
              }
            } while (!valid);

            cout << "Enter gender (M/F): ";
            do {
              string gender_str{};
              cin >> gender_str;
              if (gender_str.size() == 1 &&
                  (gender_str[0] == 'M' || gender_str[0] == 'F')) {
                gender[i] = gender_str[0];
                valid = true;
              } else {
                cout << "Invalid input, gender should be either M or F\n";
                valid = false;
              }
            } while (!valid);
            is_used[i] = true;
            break;
          }
        }
        break;
      case 2:
        cout << "*************************\n";
        for (size_t i = 0; i < SIZE; i++) {
          if (is_used[i]) {
            cout << name[i] << ' ' << age[i] << ' ' << salary[i] << ' '
                 << gender[i] << '\n';
          }
        }
        break;
      case 3: {
        cout << "Enter start age: ";
        string start_age_str{};
        int start_age{0};
        bool valid{false};
        do {
          cin >> start_age_str;
          try {
            start_age = stoi(start_age_str);
          } catch (...) {
            cout << "Invalid input, please enter a number for start age\n";
            continue;
          }
          valid = true;
        } while (!valid);

        cout << "Enter end age: ";
        string end_age_str;
        int end_age;
        valid = false;
        do {
          cin >> end_age_str;
          try {
            end_age = stoi(end_age_str);
          } catch (...) {
            cout << "Invalid input, please enter a number for end age\n";
            continue;
          }
          valid = true;
        } while (!valid);

        int counter{0};
        for (size_t i = 0; i < SIZE; i++) {
          if (is_used[i] && start_age <= age[i] && age[i] <= end_age) {
            is_used[i] = false;
            counter++;
          }
        }
        string unit = counter == 1 ? "record" : "records";
        cout << counter << " " << unit << " deleted\n";
      }

      break;
      case 4: {
        cout << "Enter name: ";
        string employee_name{};
        cin.ignore(256, '\n');
        getline(cin, employee_name);

        cout << "Enter salary: ";
        string updated_salary_str{};
        double updated_salary;
        bool valid{false};
        do {
          cin >> updated_salary_str;
          try {
            updated_salary = stod(updated_salary_str);
          } catch (...) {
            cout << "Invalid input, please enter a float for salary\n";
            valid = false;
            continue;
          }
          if (updated_salary < 0) {
            cout << "Salary cannot be negative\n";
            valid = false;
          } else {
            valid = true;
          }
        } while (!valid);

        valid = false;
        for (size_t i = 0; i < SIZE; i++) {
          if (name[i] == employee_name && is_used[i]) {
            salary[i] = updated_salary;
            valid = true;
            break;
          }
        }
        valid ? cout << "Employee salary updated successfully\n"
              : cout << "There is no employee with such name\n";
      } break;
      default:
        cout << "Invalid input, please enter a number from the list\n";
    }
    cout << '\n';
  }

  return 0;
}
