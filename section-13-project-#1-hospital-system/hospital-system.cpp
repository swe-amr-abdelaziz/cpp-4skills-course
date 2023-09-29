#include <functional>
#include <iostream>
#include <string>
using namespace std;

const int SPECIALIZATION_SIZE{20};
const int QUEUE_SIZE{5};

namespace GeneralUtils {
void getInput(int &input, string inputName = "");
void getInputAndValidate(int &input, function<bool(int)> validate,
                         string inputName, string errorMessage);
void getlineInput(string &str, string inputName = "");
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

void getlineInput(string &str, string inputName) {
  cout << "Enter " << inputName << ": ";
  cin.ignore(256, '\n');
  getline(cin, str);
}
}  // namespace GeneralUtils

namespace HospitalSystemUtils {
void printAllSpecializations(string specializations[]);
bool isQueueEmpty(int count[], int specialization);
bool isQueueFull(int count[], int specialization);
void shiftQueues(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                 int specialization, int count[], bool reverse = false);

void printAllSpecializations(string specializations[]) {
  for (int i = 0; i < SPECIALIZATION_SIZE; i++) {
    cout << i + 1 << " " << specializations[i] << '\n';
  }
}

bool isQueueEmpty(int count[], int specialization) {
  return (count[specialization] <= 0);
}

bool isQueueFull(int count[], int specialization) {
  return (count[specialization] >= QUEUE_SIZE);
}

void shiftQueues(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                 int specialization, int count[], bool reverse) {
  int index = count[specialization];
  if (reverse) {
    for (int i = index; i > 0; i--) {
      status[specialization][i] = status[specialization][i - 1];
      names[specialization][i] = names[specialization][i - 1];
    }
  } else {
    for (int i = 0; i < index; i++) {
      status[specialization][i] = status[specialization][i + 1];
      names[specialization][i] = names[specialization][i + 1];
    }
  }
}
}  // namespace HospitalSystemUtils

namespace HospitalSystem {
void printMenu();
void addNewPatient(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                   string specializations[], int count[]);
void printPatients(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                   string specializations[], int count[]);
void getNextPatient(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                    string specializations[], int count[]);

void run() {
  // Variables
  bool isProgramRunning{true};
  int count[SPECIALIZATION_SIZE]{0};
  int status[SPECIALIZATION_SIZE][QUEUE_SIZE]{};
  string names[SPECIALIZATION_SIZE][QUEUE_SIZE]{};
  string specializations[SPECIALIZATION_SIZE]{
      "Cardiology",          "Oncology",
      "Neurology",           "Orthopedics",
      "Gynecology",          "Pediatrics",
      "Dermatology",         "Radiology",
      "Anesthesiology",      "Urology",
      "Ophthalmology",       "Gastroenterology",
      "Nephrology",          "Pulmonology",
      "Hematology",          "Endocrinology",
      "Infectious Diseases", "Psychiatry",
      "Rheumatology",        "Emergency Medicine"};

  // Run Program
  cout << "<<< Hospital Management System >>>\n\n";

  while (isProgramRunning) {
    printMenu();
    int choice{0};
    GeneralUtils::getInput(choice, "choice");

    switch (choice) {
      case 1:
        addNewPatient(status, names, specializations, count);
        break;
      case 2:
        printPatients(status, names, specializations, count);
        break;
      case 3:
        getNextPatient(status, names, specializations, count);
        break;
      case 4:
        isProgramRunning = false;
        break;
      default:
        cout << "Invalid input, please enter a number from the list\n";
    }
    cout << '\n';
  }
}

void printMenu() {
  cout << "1) Add new patient\n"
          "2) Print all patients\n"
          "3) Get next patient\n"
          "4) Exit\n";
}

void addNewPatient(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                   string specializations[], int count[]) {
  int specialization{0};
  HospitalSystemUtils::printAllSpecializations(specializations);
  GeneralUtils::getInputAndValidate(
      specialization,
      [](int i) -> bool { return (i >= 1 && i <= SPECIALIZATION_SIZE); },
      "specialization", "Invalid input, please enter a number from the list\n");
  specialization--;  // Convert from 1-based to 0-based
  if (HospitalSystemUtils::isQueueFull(count, specialization)) {
    cout << "Sorry, we can't add more patients for this specialization\n";
  } else {
    int index = count[specialization];
    string patientName{""};
    int patientStatus{};
    GeneralUtils::getlineInput(patientName, "name");
    GeneralUtils::getInputAndValidate(
        patientStatus, [](int i) -> bool { return (i == 0 || i == 1); },
        "status (0 -> regular / 1 -> urgent)",
        "Invalid input, patient status should be either 0 or 1\n");
    if (patientStatus == 1) {
      HospitalSystemUtils::shiftQueues(status, names, specialization, count,
                                       true);
      index = 0;
    }
    names[specialization][index] = patientName;
    status[specialization][index] = patientStatus;
    count[specialization]++;
  }
}

void printPatients(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                   string specializations[], int count[]) {
  cout << "*************************\n";
  for (int specialization = 0; specialization < SPECIALIZATION_SIZE;
       specialization++) {
    int specCount = count[specialization];
    if (specCount > 0) {
      specCount == 1 ? cout << "There is " << specCount << " patient in "
                            << specializations[specialization] << '\n'
                     : cout << "There are " << specCount << " patients in "
                            << specializations[specialization] << '\n';
      for (int patient = 0; patient < specCount; patient++) {
        string state =
            status[specialization][patient] == 0 ? "Regular" : "Urgent";
        cout << names[specialization][patient] << " | " << state << '\n';
      }
      cout << '\n';
    }
  }
}

void getNextPatient(int status[][QUEUE_SIZE], string names[][QUEUE_SIZE],
                    string specializations[], int count[]) {
  int specialization{0};
  HospitalSystemUtils::printAllSpecializations(specializations);
  GeneralUtils::getInputAndValidate(
      specialization,
      [](int i) -> bool { return (i >= 1 && i <= SPECIALIZATION_SIZE); },
      "specialization", "Invalid input, please enter a number from the list\n");
  specialization--;  // Convert from 1-based to 0-based
  if (HospitalSystemUtils::isQueueEmpty(count, specialization)) {
    cout << "No patients at the moment. Have rest, Dr\n";
  } else {
    cout << names[specialization][0] << ", please go with the Dr\n";
    HospitalSystemUtils::shiftQueues(status, names, specialization, count);
    count[specialization]--;
  }
}
}  // namespace HospitalSystem

int main() {
  HospitalSystem::run();
  return 0;
}
