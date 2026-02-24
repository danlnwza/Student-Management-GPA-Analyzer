#include "StudentManager.h"


#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void StudentManager::addStudent() {

    string id, name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4)cout << "Invalid GPA\n";
    

    students.push_back(Student(id, name, gpa));
    cout << "Student added!\n";
}

void StudentManager::showAllStudents() const {

    if (students.empty()) {
        cout << "No students.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << "GPA\n";

    for (const auto& s : students) {
        s.display();
    }
}

void StudentManager::showTop3() {

    if (students.size() < 3) {
        cout << "Not enough students.\n";
        return;
    }

    vector<Student> temp = students;

    sort(temp.begin(), temp.end(),
         [](Student a, Student b) {
             return a.getGPA() > b.getGPA();
         });

    for (int i = 0; i < 3; i++) {
        temp[i].display();
    }
}

void StudentManager::showAverageGPA() const {
    if (students.empty()) {
        cout << "No students.\n";
        return;
    }

    double sum = 0;
    for (const auto& s : students) {
        sum += s.getGPA();
    }

    cout << "Average GPA: "
         << fixed << setprecision(2)
         << sum / students.size() << endl;
}

void StudentManager::saveToFile() {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.getID() << ","
             << s.getName() << ","
             << s.getGPA() << endl;
    }

    file.close();
    cout << "Saved successfully.\n";
}

void StudentManager::loadFromFile() {
    ifstream file("students.txt");

    if (!file) {
        cout << "File not found.\n";
        return;
    }

    students.clear();

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.rfind(",");

        string id = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        double gpa = stod(line.substr(pos2 + 1));

        students.push_back(Student(id, name, gpa));
    }

    file.close();
    cout << "Loaded successfully.\n";
}