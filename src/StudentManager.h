#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
using namespace std;
#include <vector>
#include "Student.h"


class StudentManager {

private:

    vector<Student> students;

public:
    void addStudent();
    void showAllStudents() const;
    void showTop3();
    void showAverageGPA() const;
    void saveToFile();
    void loadFromFile();
};

#endif