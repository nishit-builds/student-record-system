#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

const string FILE_NAME = "students.txt";
vector<Student> students;

// Load records from file
void loadStudents() {
    ifstream file(FILE_NAME);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string rollText, name, marksText;

        if (getline(ss, rollText, '|') &&
            getline(ss, name, '|') &&
            getline(ss, marksText)) {
            try {
                Student s;
                s.rollNo = stoi(rollText);
                s.name = name;
                s.marks = stof(marksText);
                students.push_back(s);
            } catch (...) {
                cout << "Warning: Invalid record skipped.\n";
            }
        }
    }

    file.close();
}

// Save all records to file
bool saveStudents() {
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "Error: Could not open the file for saving.\n";
        return false;
    }

    for (const Student& s : students) {
        file << s.rollNo << '|'
             << s.name << '|'
             << s.marks << '\n';
    }

    file.close();
    return true;
}

// Add a student
void addStudent() {
    Student s;

    cout << "Enter roll number: ";
    if (!(cin >> s.rollNo) || s.rollNo <= 0) {
        cout << "Invalid roll number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const Student& existing : students) {
        if (existing.rollNo == s.rollNo) {
            cout << "This roll number already exists.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    getline(cin, s.name);

    if (s.name.empty() || s.name.find('|') != string::npos) {
        cout << "Invalid name. Do not leave it empty or use '|'.\n";
        return;
    }

    cout << "Enter marks (0-100): ";
    if (!(cin >> s.marks) || s.marks < 0 || s.marks > 100) {
        cout << "Invalid marks. Enter a value from 0 to 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    students.push_back(s);

    if (saveStudents()) {
        cout << "Student added and saved successfully!\n";
    } else {
        students.pop_back();
    }
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n----- STUDENT RECORDS -----\n";
    cout << left << setw(12) << "Roll No"
         << setw(25) << "Name" << "Marks\n";
    cout << "------------------------------------------\n";

    for (const Student& s : students) {
        cout << left << setw(12) << s.rollNo
             << setw(25) << s.name
             << fixed << setprecision(2) << s.marks << '\n';
    }
}

// Search for a student
void searchStudent() {
    int roll;

    cout << "Enter roll number to search: ";
    if (!(cin >> roll)) {
        cout << "Invalid roll number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const Student& s : students) {
        if (s.rollNo == roll) {
            cout << "\nStudent found!\n";
            cout << "Roll Number: " << s.rollNo << '\n';
            cout << "Name: " << s.name << '\n';
            cout << "Marks: " << s.marks << '\n';
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    loadStudents();

    int choice;

    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid menu number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                cout << "Records are saved in "
                     << FILE_NAME << ". Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Choose 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
