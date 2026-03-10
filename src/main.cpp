/*

ขั้นตอนที่ 3 : เขียนควบคุมของโปรแกรมทั้งหมด

-ใช้ควบคุมการทำงานหลักของโปรแกรม
-เรียกใช้ฟังก์ชันจากไฟล์อื่น(ความสัมพันธ์คือ main.cpp เรียกใช้ studentmanager.cpp 
 และ studentmanager.cpp ก็เรียกใช้ student.cpp อีกทีหนึ่ง เหมือนเป็นชั้นๆ ไป)

*/
#include <iostream>
#include "studentmanager.h"//ให้รู้จัก

using namespace std;

int main(){

    studentmanager sm;
    int menu;

//วนมาหน้าเมนูหลักตลอด
    while(true){

        //แสดงหน้าหลัก
        cout<<"\n\n========================================\n";
        cout<<"        STUDENT MANAGEMENT SYSTEM\n";
        cout<<"========================================\n"<<endl;
        //เมนู function ต่างๆ
        cout<<"1. Add Students\n";
        cout<<"2. Show All Students\n";
        cout<<"3. Delete Students\n";
        cout<<"4. Show Top 3 GPA\n";
        cout<<"5. Show Statistics GPA\n";
        cout<<"6. Search Student by ID\n";
        cout<<"7. Save to File\n";
        cout<<"8. Load from File\n";
        cout<<"0. Exit\n\n";
        
        cout<<endl;
        //ช่องเลือกทํารายการ
        cout<<"\nSelect Menu (0-8): ";
        cin>>menu;
        
        //cin.clear();
        //cin.ignore(1000,'\n');
        

        //กรณีกรอกอย่างอื่นที่ไม่ใช่ตัวเลข

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid menu! Try again.\n";
            continue;
        }   

        cin.ignore(1000,'\n'); //ล้าง buffer หลังรับค่า

        switch(menu){

            case 1: sm.addstudents();break; //1 เพิ่มข้อมูลนักเรียน
            case 2: sm.showstudent();break;//2 แสดงข้อมูลทั้งหมด
            case 3: sm.deletestudents();break;//3 ลบข้อมูลนักเรียน
            case 4: sm.showtop3_gpa();break;//4 แสดงท๊อป3
            case 5: sm.showstat_gpa();break;//5 แสดงค่าเฉลี่ยทั้งห้อง
            case 6: sm.search_by_id();break;//6 ค้นหาผ่านid
            case 7: sm.save_file();break;//7 บันทึกข้อมูล
            case 8: sm.load_from_file();break;//8 โหลดข้อมูลมาแก้ไข

            case 0: 
                cout<<"\nThank you for using Student Management System\n"<<"See you again!\n";
                return 0;//เพื่อออกจากโปรแกรม

        default: cout<<"Invalid menu! Please enter 0-8\n"; //กรณีกรอกเลขอื่น


        }
    }
}