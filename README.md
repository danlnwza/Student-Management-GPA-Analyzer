📚 Student Management System

Developed by Pattharawit Chomphupan  
Student Code: 680610702  

🗂️ Project Structure
├── main.cpp            # Program entry point & menu control
├── student.h           # Student class declaration (Blueprint)
├── student.cpp         # Student class implementation
├── studentmanager.h    # StudentManager class declaration
└── studentmanager.cpp  # StudentManager class implementation

✨ Features
========================================
        STUDENT MANAGEMENT SYSTEM
========================================

1. Add Students
2. Show All Students
3. Delete Students
4. Show Top 3 GPA
5. Show Statistics GPA
6. Search Student by ID
7. Save to File
8. Load from File

Select Menu (0-8):___


🛠️ Built With

-Language : C++
-Compiler : TDM-GCC 10.3.0 (MinGW-w64)
-IDE : Visual Studio Code
-Standard : C++11 or later


🧠 Concepts Used

-Object-Oriented Programming (Encapsulation, Constructor Overloading)
-STL Vector & Algorithm (sort with Lambda Function)
-File I/O (fstream)
-Input Validation (cin.fail, getline)
-String ID support (e.g. 001, 002)
-Statistical calculation (cmath)


🚀 How to Run
bash g++ main.cpp student.cpp studentmanager.cpp -o run
./run

📋 Input Validation

ID — Numbers only, no duplicates allowed
Name — Letters and spaces only, no numbers
GPA — Must be between 0.00 and 4.00
