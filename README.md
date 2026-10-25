# 🎓 Student Record Management System

A menu-driven C++ application for adding, displaying, searching, and storing student records.

## 📌 About the Project

The **Student Record Management System** is a console-based application developed using C++. It helps manage basic student information, including roll numbers, names, and marks.

The application stores records in a text file, allowing student data to be loaded again when the program is restarted.

## ✨ Features

- **Add Student:** Enter a student's roll number, name, and marks.
- **Display Students:** View all stored student records in a formatted table.
- **Search Student:** Find a student using their roll number.
- **File Handling:** Save student records in `students.txt` and load them when the program starts.
- **Duplicate Prevention:** Prevents adding another student with an existing roll number.
- **Input Validation:** Checks roll numbers, names, marks, and menu choices.
- **Formatted Output:** Displays marks up to two decimal places.
- **Data Persistence:** Keeps saved records available across program restarts.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Header Files:** `iostream`, `fstream`, `sstream`, `string`, `vector`, `limits`, and `iomanip`
- **Concepts:** Structures, functions, loops, conditional statements, vectors, file handling, exception handling, and input validation.

## 🚀 Getting Started

### Prerequisites

- A C++ compiler, such as GCC or MinGW.
- A terminal or command prompt.

### Installation

1. Clone or download this repository.
2. Open the project folder.
3. Compile the source file using a C++ compiler.
4. Run the generated executable.

### Compile the Program

If your source file is named `main.cpp`, use:

```bash
g++ main.cpp -o student-record-system
```

### Run the Program

**Linux or macOS:**

```bash
./student-record-system
```

**Windows:**

```bash
student-record-system.exe
```

## 💻 Sample Output

```text
===== STUDENT RECORD SYSTEM =====
1. Add Student
2. Display Students
3. Search Student
4. Exit
Enter your choice: 1

Enter roll number: 22
Enter student name: Rahul
Enter marks (0-100): 85.5
Student added and saved successfully!
```

## 📁 Data Storage

Student records are stored in a file named `students.txt`.

Each record contains the following information:

- Roll number
- Student name
- Marks

The program uses a pipe (`|`) as the separator between these fields. The file is loaded automatically when the application starts.

**Note:** Keep `students.txt` in the program's working directory so existing records can be loaded correctly.

## 🎯 Learning Objectives

This project demonstrates how to:

- Create and use structures in C++.
- Organise programs using functions.
- Store and manage multiple records using vectors.
- Read and write data using file handling.
- Search for records using conditional statements.
- Validate user input and handle invalid data.
- Format console output using `iomanip`.

## 👨‍💻 Author

**Nishit Shah**

- **GitHub:** [nishit-builds](https://github.com/nishit-builds)
- **Portfolio:** [Visit My Portfolio](https://nishit-builds.github.io/personal-portfolio-website/)

## 📂 Project Repository

[View Student Record Management System on GitHub](https://github.com/nishit-builds/student-record-system)

---

⭐ Thanks for checking out my project!
