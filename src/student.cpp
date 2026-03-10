/*
ขั้นตอนที่ 1.2 : เขียนการทำงานจริงของ class student ใน student.h
-จัดการข้อมูลนักเรียนแต่ละคนแบบเรียวไทม์
*/

#include"student.h"//นําไฟล์ header student.h มาใช้

//defualt constructor เปล่า กําหนดค่าเริ่มต้นทุกครั้งในการสร้าง obj
student::student(){
    id="";
    name="";
    gpa=0;
}

//parameter constructor สร้าง obj พร้อมข้อมูล
student::student(string id,string name,double gpa){
    //กําหนดค่า ผ่าน this pointer (เพื่อให้โปรแกรมไม่สับสน)
    this->id=id; //id ของ obj = id (พารามิเตอร์ที่รับมา)
    this->name=name;
    this->gpa=gpa;
}

//Data abstraction

//setter function แก้ไขค่า (set ค่าข้อมูล)
void student::set_id(string id){
    this->id=id;
}

void student::set_name(string name){
    this->name=name;
}

void student::set_gpa(double gpa){
    this->gpa=gpa;
}

//getter function ใช้ดึงค่าออดมาใช้ (get ค่าข้อมูล)
string student::get_id(){
    return id;//มีการส่งค่ากลับไป
}

string student::get_name(){
    return name;
}

double student::get_gpa(){
    return gpa;
}