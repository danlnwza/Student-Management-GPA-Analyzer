#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student(string i, string n, double g) {
    id = i;
    name = n;
    gpa = g;
}

string Student::getID() const { return id; }
string Student::getName() const { return name; }
double Student::getGPA() const { return gpa; }

void Student::display() const {
    
    cout << left << setw(10) << id
         << setw(20) << name
         << fixed << setprecision(2) << gpa << endl;
}