/*
ขั้นตอนที่ 2.1 : ประกาศ class studentmanager (Blueprint ของระบบจัดการ)
ประกาศ member function ในการจัดการนักเรียนหลายคน ได้แก่

-addStudent
-showStudents
-deleteStudents
-top3GPA
-statisticsGPA
-searchStudents
-saveFile
-loadFile

*/

#ifndef STUDENTMANAGER_H 
#define STUDENTMANAGER_H

#include<vector>//เก็บนักเรียนหลายคน ใช้ vector
#include"student.h"//เรียกใช้ข้อมูโครงสร้างของ class student จาก student.h
using namespace std;

class studentmanager{

//ข้อมูลส่วนตัว
    private:
    vector<student> students; //สร้าง veator students ไว้เก็บนักเรียนทั้งหทด

//ข้อมูลที่ main สามารถเรียกใช้ได้เลย
    public:
    //สร้าง function member
    void addstudents(); //1 เพิ่มข้อมูลนักเรียน
    void showstudent(); //2 แสดงข้อมูลทั้งหมด
    void deletestudents();//3 ลบข้อมูลนักเรียน
    void showtop3_gpa();//4 แสดงท๊อป3
    void showstat_gpa();//5 แสดงค่าเฉลี่ยทั้งห้อง
    void search_by_id();//6 ค้นหาผ่านid
    void save_file();//7 บันทึกข้อมูล
    void load_from_file();//8 โหลดข้อมูลมาแก้ไข
};


#endif





