#include <functional>
#include <iostream>
#include <string>
using namespace std;

const int SIZE{200};

void printMenu();
void addNewEmployee(string name[], int age[], double salary[], char gender[],
                    bool isUsed[]);
void printEmployees(string name[], int age[], double salary[], char gender[],
                    bool isUsed[]);
void deleteByAge(int age[], bool isUsed[]);
void updateSalary(string name[], double salary[], bool isUsed[]);
void getlineInput(string &str, string inputName = "");
void getInput(int &input, string inputName = "");
void getInputAndValidate(int &input, function<bool(int)> validate,
                         string inputName, string errorMessage);
void getInputAndValidate(double &input, function<bool(double)> validate,
                         string inputName, string errorMessage);
void getInputAndValidate(char &input, function<bool(string)> validate,
                         string inputName, string errorMessage);

void run() {
  // Variables
  string name[SIZE];
  int age[SIZE];
  double salary[SIZE];
  char gender[SIZE];
  bool isUsed[SIZE]{false};
  bool isProgramRunning{true};

  // Run Program
  cout << "<<< Employee Management System >>>\n\n";

  while (isProgramRunning) {
    printMenu();
    int choice{0};
    getInput(choice, "choice");

    switch (choice) {
      case 1:
        addNewEmployee(name, age, salary, gender, isUsed);
        break;
      case 2:
        printEmployees(name, age, salary, gender, isUsed);
        break;
      case 3:
        deleteByAge(age, isUsed);
        break;
      case 4: {
        updateSalary(name, salary, isUsed);
      } break;
      case 5:
        isProgramRunning = false;
        break;
      default:
        cout << "Invalid input, please enter a number from the list\n";
    }
    cout << '\n';
  }
}

int main() {
  /* Employee Program (v2) */
  run();
  return 0;
}

void printMenu() {
  cout << "1) Add new employee\n2) Print "
          "all employees\n3) "
          "Delete by age\n4) Update Salary by name\n5) Exit\n";
}

void getlineInput(string &str, string inputName) {
  cout << "Enter " << inputName << ": ";
  cin.ignore(256, '\n');
  getline(cin, str);
}

void addNewEmployee(string name[], int age[], double salary[], char gender[],
                    bool isUsed[]) {
  for (size_t i = 0; i < SIZE; i++) {
    if (!isUsed[i]) {
      getlineInput(name[i], "name");
      getInputAndValidate(
          age[i], [](int i) -> bool { return (18 <= i && i <= 200); }, "age",
          "Age should be between 18 and 200 years\n");
      getInputAndValidate(
          salary[i], [](double d) -> bool { return d >= 0; }, "salary",
          "Salary cannot be negative\n");
      getInputAndValidate(
          gender[i],
          [](string s) -> bool {
            return s.size() == 1 && (s[0] == 'M' || s[0] == 'F');
          },
          "gender (M/F)", "Invalid input, gender should be either M or F\n");
      isUsed[i] = true;
      break;
    }
  }
}

void printEmployees(string name[], int age[], double salary[], char gender[],
                    bool isUsed[]) {
  cout << "*************************\n";
  for (size_t i = 0; i < SIZE; i++) {
    if (isUsed[i]) {
      cout << name[i] << ' ' << age[i] << ' ' << salary[i] << ' ' << gender[i]
           << '\n';
    }
  }
}

void deleteByAge(int age[], bool isUsed[]) {
  int startAge;
  int endAge;
  getInput(startAge, "start age");
  getInput(endAge, "end age");

  int counter{0};
  for (size_t i = 0; i < SIZE; i++) {
    if (isUsed[i] && startAge <= age[i] && age[i] <= endAge) {
      isUsed[i] = false;
      counter++;
    }
  }
  string unit = counter == 1 ? "record" : "records";
  cout << counter << " " << unit << " deleted\n";
}

void updateSalary(string name[], double salary[], bool isUsed[]) {
  string employeeName;
  getlineInput(employeeName, "employee name");

  double newSalary;
  getInputAndValidate(
      newSalary, [](double d) -> bool { return d >= 0; }, "new salary",
      "Salary cannot be negative\n");

  bool foundEmployee = false;
  for (size_t i = 0; i < SIZE; i++) {
    if (name[i] == employeeName && isUsed[i]) {
      salary[i] = newSalary;
      foundEmployee = true;
      break;
    }
  }
  foundEmployee ? cout << "Employee salary updated successfully\n"
                : cout << "There is no employee with such name\n";
}

void getInput(int &input, string inputName) {
  string typeName{"integer"};
  string inputString{};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  bool isValidInput{false};
  do {
    cin >> inputString;
    try {
      input = stoi(inputString);
      typeName = "integer";
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    isValidInput = true;
  } while (!isValidInput);
}

void getInputAndValidate(int &input, function<bool(int)> validate,
                         string inputName, string errorMessage) {
  string typeName{"integer"};
  string inputString{};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  bool isValidInput{false};
  do {
    cin >> inputString;
    try {
      input = stoi(inputString);
      typeName = "integer";
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    if (validate(input)) {
      isValidInput = true;
    } else {
      cout << errorMessage;
      isValidInput = false;
    }
  } while (!isValidInput);
}

void getInputAndValidate(double &input, function<bool(double)> validate,
                         string inputName, string errorMessage) {
  string typeName{"double"};
  string inputString{};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  bool isValidInput{false};
  do {
    cin >> inputString;
    try {
      input = stod(inputString);
      typeName = "double";
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    if (validate(input)) {
      isValidInput = true;
    } else {
      cout << errorMessage;
      isValidInput = false;
    }
  } while (!isValidInput);
}

void getInputAndValidate(char &input, function<bool(string)> validate,
                         string inputName, string errorMessage) {
  string typeName{"character"};
  string inputString{};
  if (inputName.size()) {
    cout << "Enter " << inputName << ": ";
  }
  bool isValidInput{false};
  do {
    cin >> inputString;
    try {
      input = inputString[0];
      typeName = "character";
    } catch (...) {
      cout << "Invalid input, please enter a valid " << typeName << " for "
           << inputName << "\n";
      continue;
    }
    if (validate(inputString)) {
      isValidInput = true;
    } else {
      cout << errorMessage;
      isValidInput = false;
    }
  } while (!isValidInput);
}
