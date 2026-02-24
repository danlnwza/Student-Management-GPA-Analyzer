#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {

private:

    string id,name;
    double gpa;

public:


    Student(string i, string n, double g);

    string getID() const;

    string getName() const;

    double getGPA() const;

    void display() const;
};

#endif