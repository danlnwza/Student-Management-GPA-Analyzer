#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager manager;
    int choice;

    do {
        
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Show Top 3 GPA\n";
        cout << "4. Show Class Average GPA\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.showAllStudents(); break;
            case 3: manager.showTop3(); break;
            case 4: manager.showAverageGPA(); break;
            case 5: manager.saveToFile(); break;
            case 6: manager.loadFromFile(); break;
            case 0: cout << "sawaddee!\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}