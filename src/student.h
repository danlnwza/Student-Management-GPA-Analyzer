/*
ขั้นตอนที่ 1.1 สร้าง class student ในการกําหนด member ต่างๆ (Blueprint ของนักเรียน 1 คน) เพื่อใช้ในการจัดการข้อมูลใน student.cpp
*/

//include guard ป้องกัน include ซํ้า
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

//ใช้ความรู้ในเรื่องของ class 

class student {
//ขั้นตอนที่ 1.1 ฐานข้อมูลระบบ id name gpa
    private:
    string id;
    string name;
    double gpa;

//Constructor Overloading
    public:
    student();//Default Constructor objเปล่า
    student(string id,string name,double gpa);// Parameterized Constructor พร้อม obj

//เข้าถึงข้อมูล private ผ่าน set&get method

    void set_id(string id);
    void set_name(string name);
    void set_gpa(double gpa);

    string get_id();
    string get_name();
    double get_gpa();
    

};

#endif



