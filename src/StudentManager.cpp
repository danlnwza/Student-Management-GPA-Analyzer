/*
ขั้นตอนที่ 2.2 เขียนการทำงานจริงของระบบจัดการทั้งหมด

*/
#include"studentmanager.h"//เรียกใช้ข้อมูลจาก studentmanager.h
#include<iostream>// ใช้ cin cout
#include<iomanip>// แสดงการจัดเรียงข้อมูลที่เป็นระเบียบ
#include<fstream>//การอ่านและเขียนไฟล์txt
#include<algorithm>// ใช้เพื่อเรียงข้อมูล
#include<cmath>//คํานวณค่าสถิติ

//1 เพิ่มข้อมูล

void studentmanager::addstudents(){

    int n;

while(true){

    cout<<"Input Count Of Students : ";// รับจํานวน นร
    cin>>n;

    //ตรวจสอบค่าอื่นที่ไม่ใช่ตัวเลข
    if(cin.fail()){
    cout<<"Invalid Count Please Enter Number\n";
    cin.clear(); // ล้างข้อมูลผิดพลาด ผิดประเภท
    cin.ignore(1000,'\n');// ข้ามข้อมูลขยะที่ไม่เกี่ยว จนกว่าจะกด enter
    }
    //กรณีกรอก 0
    else if(n == 0) {
    cout << "No students added.\n";
    return;
    //กรณีติดลบ
    }else if(n < 0){
        cout<<"Input positive number\n";
    }else break;

}
//รายหัว
for(int i = 0 ; i < n;i++){

    cout<<"\n#Student"<<i+1<<endl;

//ตรวจสอบการรับค่า id
string id;
while(true){
    cout<<"\nEnter ID Student["<<i+1<<"] : ";
    cin>>id;

    //เป็นตัวเลขป่าว
    bool isAllDigit = true;
    for(char c : id){
        if(!isdigit(c)){ isAllDigit = false; break; }
    }

    if(id.empty() || !isAllDigit){
        cout<<"\nInvalid ID! Please enter numbers only.\n";
        continue;
    }


//เช็ค id ซํ้า
bool duplicate = false; //กําหนดให้ไม่มีตัวซั้าก่อน
for(int j = 0; j < students.size(); j++){
    if(students[j].get_id() == id){
        duplicate = true;
        break;
    }
}

if(duplicate){
    cout<<"\nID "<<id<<" already exists! Please enter another ID.\n";
}else break; //ผ่านได้เมื่อไม่ซ้ำและเป็นเลขถูกต้อง


}

//ตรวจสอบการรับค่า name
string name;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ล้าง buffer ก่อน getline
while(true) {
        cout<<"\nEnter Name Student["<<i+1<<"] : ";//รับ name
        getline(cin, name);//เว้นวรรค
        /*
        getline(cin,name);
        cin>>name;
        */

        //cin.clear();

        //ตรวจสอบว่า name มีเลขปนมั้ย
        bool hasdigit = false;//กําหนดค่าเริ่มต้น
        //if(hasdigit) cin.ignore(1000,'\n');//ignore เฉพาะตอนที่ name ผิดเท่านั้น

        for(char c : name){ //char ในตําแหน่ง name ทุกตัว
            if(isdigit(c)){//เช็คว่าใช่ตัวเลขมั้ย
                hasdigit = true;//เปลี่ยนค่า
                break;
            }
        }
        //ถ้ามีให้แจ้งเตือน
        //if(hasdigit)cout<<"\nInvalid Name must not have numbers\n";else break;
        if(name.empty()){
            cout<<"\nInvalid Name! Name must not be empty.\n";
        }else if(hasdigit){
            cout<<"\nInvalid Name! Name must not contain numbers.\n";
        }else break;
    }
        
        /*
        do{
            cout<<"enter GPA students["<<i+1<<"]: ";
            cin>>gpa;
            if(gpa < 0||gpa > 4||gpa)cout<<"Invalid input.Please enter between 0.00 - 4.00"<<endl;
            
            }while(cinfail() || gpa < 0 || gpa > 4);
            */

//ตรวจสอบการรับค่า gpa           
double gpa;
while(true){
            cout<<"\nEnter GPA Students["<<i+1<<"] : ";// รับ gpa
            cin>>gpa;
            //กรอกข้อมูลอื่นนอกจากตัวเลขหรือไม่ หรือ กรอกตัวเลขเกินกําหนดมั้ย
            if(cin.fail() || gpa < 0 || gpa > 4){
                cout<<"\nInvalid GPA! Please enter between 0.00 - 4.00\n";
                cin.clear(); // กันข้อมูลผิดประเภท
                cin.ignore(1000,'\n');// ข้ามข้อมูลขยะที่ไม่เกี่ยว จนกว่าจะกด enter
            }else break; //ถ้าไม่มีข้อผิดพลาดจะหยุด
        }

        // **ต้องเข้าถึงข้อมูลให้ได้
        student s(id,name,gpa);//สร้าง obj s จาก class student 1 เก็บข้อมูลสําหรับ 1 คน
        students.push_back(s);//เพิ่มข้อมูลลง vector students (สําหรับทั้งห้อง)
    }
    //ออกloop
    cout<<"\nAdded Successfully"<<endl;//แจ้งเตือนตอนแอดสําเร็จ

}


/*********************************************************************/
//2 แสดงข้อมูล

void studentmanager::showstudent(){

//ตรวจสอบก่อนว่ามีข้อมูลในvectorมั้ย
    if(students.empty()){

    cout<<"\n-----No Student Data-----\n";
    return;//หยุดการทํางานเมื่อไม่มีข้อมูล

    }
//สร้างตารางแจ้ง
    cout<<"\n========================================\n";
    cout<<"           STUDENT LIST\n";
    cout<<"========================================\n";
    cout<<left<<setw(5)<<"No."<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"GPA";
    cout<<"\n----------------------------------------\n";
/*
cout<<"\n-------------Student List---------------\n";
//กําหนดความห่างของหัวข้อ
cout<<left<<setw(5)<<"No."<<setw(10)<<"ID."<<setw(20)<<"Name"<<setw(10)<<"GPA\n";
cout<<left<<"----------------------------------------\n";
*/

//เอา(ดึง get method)ข้อมูลมาแสดง
    for(int i = 0; i < students.size() ; i++){
        cout<<left<<setw(5)<<i+1 //คอลัม No.
        <<setw(10)<<students[i].get_id()//คอลัม id
        <<setw(20)<<students[i].get_name()// คอลัม name
        <<setw(10)<<fixed<<setprecision(2)<<students[i].get_gpa()<<endl;//คอคัม gpa พร้อมทั้งsetทศนิยม2ตัวแหน่ง
    }
    //cout<<resetiosflags(ios::fixed);
    cout<<"----------------------------------------\n";
    cout<<"Total Students : "<< students.size()<<"\n\n\n";
    //cout<<"========================================\n";

}

/**********************************************************************/
//3 ลบข้อมูล

void studentmanager::deletestudents(){
//ตรวจสอบก่อนว่ามีข้อมูลในvectorมั้ย
    if(students.empty()){cout<<"\n-----No Student Data----"<<endl;
    return;}

//ลบหมด vs ลบบางคน
while(true){

int choice;
    //ถามว่าต้องการแบบไหน
    cout << "\nDelete Menu\n"
         << "1. Delete selected students\n"
         << "2. Delete ALL students\n"

         << "Select: ";
         cin >> choice;


    //ลบข้อมูลทั้งหมด
    if(choice == 2){
        
        char confirm;
        while(true){

        cout << "\nYou are about to delete ALL student data.\n";
        cout << "\nConfirm delete? (y/n) : ";
        cin >> confirm;
        cin.ignore(1000,'\n');

        if(confirm == 'y' || confirm == 'Y')
        {
            students.clear();
            cout << "All student data deleted.\n";
            break;
        }
        else if(confirm == 'n' ||confirm == 'N'){
            cout << "Delete cancelled.\n";
            break;
        }else {
            cout<<"\n\nPlease enter only (y/n)\n ";
        }
    }
    return;
} 
//ลบบางคน
else if(choice == 1){   

//ระบุจํานวนที่ต้องการลบ
int n;
while(true){
    cout<<"\nCount Of Students To Want Delete : ";
    cin>>n;

    //เช็คค่าที่เป็นไปได้
    if(cin.fail() || n <= 0){
        cout<<"\nInvalid! Please enter a positive number.\n";
        cin.clear();
        cin.ignore(1000,'\n');
    }else if(n > students.size()){
        cout<<"\nInvalid Only "<<students.size()<<" students available"<<endl;
    }else break;
}

//สร้างเวกเตอร์เก็บ index ของข้อมูลที่ต้องการลบ
vector<int> idxlist;


//ถาม id ผู้ที่ต้องการลบ
for(int i = 0; i < n ; i++){

    string id;
    cout<<"\nEnter ID["<<i+1<<"] : ";//รับ id
    cin>>id;

    //เช็คว่าตรงมั้ย
    bool found = false;//ค่าเริ่มต้นให้ไม่เจอ id
    for(int j = 0 ; j<students.size();j++){//ค้นหาใน vector students
        if(students[j].get_id()==id){//ตรวจสอบว่า id ที่ระบุตรงกับฐานข้อมูลมั้ย
            idxlist.push_back(j);//ถ้าเจอก็ให้เก็บตําแหน่ง idx นั้นไว้ใน vector idxlist
            found = true;//เปลี่ยนค่าว่า เจอ id
            break;//หยุด loop ค้นหา
        }
    }
    //ถ้าไม่เจอ
    if(!found){
        cout<<"\nID not found";//ถ้าไม่เจอจะแจ้ง
    }
    //else break;
}

//ตรวจความถูกต้องของ ข้อมูลที่เราเลือกมา

//ตรวจสอบว่า vector ว่างมั้ย
if(idxlist.empty()){cout<<"\nNo valid student selected.\n";//ถ้าไม่มีจะขึ้นแจ้งไม่ถูก หรือ ไม่มี id
//return;
break;}

//กรณีที่มีการระบุ id เรียบร้อย
cout<<"\n------------------------------\n";
cout<<"\nStudents selected for deletion\n";
cout<<"\n------------------------------\n";

//แสดงข้อมูล id name gpa ของ id นั้นๆ
for(int idx:idxlist){//วนตาม idx ที่เก็บไว้
    cout<<"\nID : "<<students[idx].get_id()
        <<"  Name : "<<students[idx].get_name()
        <<"  GPA : "<<fixed<<setprecision(2)<<students[idx].get_gpa()<<endl;
}

//ถามยืนยัน
char confirm;
while(true){

cout<<"\nconfrim to delete (y/n) : ";
cin>>confirm;
cin.ignore(1000,'\n');
if(confirm == 'y'|| confirm == 'Y'){//ตรวจสอบว่าตกลงมั้ย
    for(int i = idxlist.size()-1;i >= 0 ; i--)students.erase(students.begin() + idxlist[i]);
    //เงื่อนไขตรง ทําการลบข้อมูล idx จากหลังมาหน้าใน veแtor  (กันการเลื่อนidx)
    cout<<"\n---Delete completed---"<<endl;//แจ้งเตือนเมื่อลบสําเสร็จ
    break;
}else if(confirm == 'n' || confirm =='N') {
cout<<"\n---Delete cancelled---\n";//เงื่อนไขไม่ตรง ทําการยกเลิก
break;
}else{
    cout<<"\nPlease enter only (y/n)\n";
    }
}
return;


 }//กรณีที่ไม่เป็นไปตาม choice
 else {
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"\nplease enter number (1 or 2)\n"<<endl;
}   //if(cin.fail()||choice != 1||choice != 2) 
 
}
 
}

/**********************************************************************/
//4 แสดง top gpa 3 คน

void studentmanager::showtop3_gpa(){
//ตรวจสอบก่อนว่ามีข้อมูลในvectorมั้ย
    if(students.empty()){
        cout<<"\n-----No student data----"<<endl; 
        return;}
//ค้นหา & ตรวจสอบข้อมูลล่าสุดผ่าน sort algor

vector<student> temp = students; //สร้างตัวแปร temp ที่จะ copy(สํารองข้อมูล) จาก students

//เรียงข้อมูล temp ทั้งหมด ตัวแรกไปตัวท้าย จากมากไปน้อย
sort(temp.begin(),temp.end(),
[](student a,student b){return a.get_gpa()>b.get_gpa();} //กําหนดเงื่อนไขการเรียงเรียงลําดับ ผ่านตัว lambda function (เอา 2 ตัวมาเทียบมาก-น้อยกัน)
);
     cout<<"\n---------top 3 GPA students---------\n"<<endl;
    //แสดงผล 3 อันดับแรก
     for(int i = 0 ; i < 3 && i < temp.size(); i++)
     cout<<i+1<<". "<<temp[i].get_name()<<"   GPA : "<<fixed<<setprecision(2)<<temp[i].get_gpa()<<endl<<endl;
}

/***********************************************************************/
//5 show stat

void studentmanager::showstat_gpa(){

//ตรวจสอบก่อนว่ามีข้อมูลใน vector มั้ย
    if(students.empty()){cout<<"\n-----No student data-----"<<endl; 
    return; }

    int n = students.size();//จํานวนนร ทั้งหมด

//กําหนดค่าเริ่มต้น
    double sum = 0;//ผลรวมgpa
    double sumlog = 0;//ผมรวมค่าlog
    double sumin = 0;//ผมรวมค่า1/x
    double sumsqrt = 0;//ผลรวมค่ากําลังสองผลต่าง

    double max = students[0].get_gpa(); //ค่าที่อยู่ idx แรก
    double min = students[0].get_gpa(); //เหมือนกัน

    

    for(student &s:students){

        sum += s.get_gpa();//หาผมรวม gpa
        sumlog += log(s.get_gpa());//หาผลรวม log
        sumin += 1.0/s.get_gpa();//หาผลรวม invers

        if(s.get_gpa()>max) max =s.get_gpa();//หาค่า max
        if(s.get_gpa()<min) min =s.get_gpa();//หาค่า min
    }

    double ari_mean = sum/n; //ค่าเฉลี่ย = sum / N

    for(student &s:students){
        sumsqrt += pow((s.get_gpa()-ari_mean),2);//หาผลรวมของกําลังสองของผลต่างค่าเฉลี่ย
}

        double std_dev = sqrt(sumsqrt/n); // sqrt( Σ(x - mean)^2 / N )
        double geo_mean = exp(sumlog/n); // (x1 × x2 × x3 × ... × xN)^(1/N)
        double harm_mean = n/sumin; // N / sumin
        double max_gpa = max;//max
        double min_gpa = min;//min

//แสดงผลค่ากลาง
    cout << "---------- Class Statistics ----------"<<endl;

    cout<<fixed<<setprecision(2);//ทศนิยม 2 ตําแหน่ง

    cout<< "Arithmetic Mean      = " << ari_mean << endl//ค่าเฉลี่ยเลขคณิต
        << "Standard Deviation   = " << std_dev << endl//ส่วนเบี่ยงเบนมาตรฐาน
        << "Geometric Mean       = " << geo_mean << endl//ค่าเฉลี่ยเรขาคณิต
        << "Harmonic Mean        = " << harm_mean << endl//ค่าเฉลี่ยฮาร์โมนิก
        << "Max GPA              = " << max_gpa << endl//ค่าสูงสุด
        << "Min GPA              = " << min_gpa << endl;//ค่าตํ่าสุด
  
}

/***********************************************************************/
//6 search by id

void studentmanager::search_by_id(){
    string id;
    cout<<"\nEnter Student ID : ";//กรอก id ที่ต้องการค้นหา
    cin>>id;

    bool found = false;//กําหนดค่าเริ่มต้นให้ไม่เจอ
    for(student s:students){
        if(s.get_id()==id){//ตรวจสอบว่าพบหรือไม่
            //ถ้าพบ แสดงข้อมูล
            cout<<"\n----Student Found----"<<endl
            <<"ID : "<<s.get_id()<<endl
            <<"Name : "<<s.get_name()<<endl
            <<"GPA : "<<fixed<<setprecision(2)<<s.get_gpa()<<endl;
            found = true;//เปลี่ยนแปลงค่า
            
            break;//หยุดการทํางานเมื่อเจอ
        }
    }
    if(!found)cout<<"\n---student Not Found---\n";//ถ้าไม่พบจะแสดง แจ้งอีกที
}

/**********************************************************************/
//7 บันทึกลงไฟล์txt

void studentmanager::save_file(){

    //เขียนลงไฟล์ student.txt
    ofstream file("students.txt");

    //กรณีไฟล์มีปัญหา
    if(!file){
        cout<<"\nError file"<<endl;
        return;
    }

    //กรณีไม่มีข้อมูล
    if(students.empty()){
        cout<<"\nDon't have any data to save"<<endl;//แจ้งใน console
        file<<"No student data";//แจ้งใน txt
        file.close();//ทําการปิดไฟล์ทันที
        return;
    }
    //ตกแต่งหน้าไฟล์
    file<<"\n========================================\n"
        <<"\n              Student Data\n"
        <<"\n========================================\n\n";

    file<<left<<setw(5)<<"No"
        <<setw(10)<<"ID"
        <<setw(20)<<"Name"
        <<setw(10)<<"GPA"<<endl;

    file<<"----------------------------------------\n";


    //โชว์ข้อมูล นร.
    for(int i=0;i<students.size();i++){
        //จัดระเบียบ
        file<<left<<setw(5)<<i+1
            <<setw(10)<<students[i].get_id()//แสดง id
            <<setw(20)<<students[i].get_name()//แสดง name
            <<setw(10)<<fixed<<setprecision(2)<<students[i].get_gpa()<<endl; //แสดง gpa
    }

    file<<"----------------------------------------\n\n";

//โชว์ข้อมูลทางสถิติ

//กําหนดค่าเริ่มต้น
    int n = students.size();//จํานวนนร ทั้งหมด
    double sum = 0;//ผลรวมgpa
    double sumlog = 0;//ผมรวมค่าlog
    double sumin = 0;//ผมรวมค่า1/x
    double sumsqrt = 0;//ผลรวมค่ากําลังสอง

    double max = students[0].get_gpa(); //ค่าที่อยู่ idx แรก
    double min = students[0].get_gpa(); //เหมือนกัน

    for(student &s:students){

        sum += s.get_gpa();//หาผมรวม gpa
        sumlog += log(s.get_gpa());//หาผลรวม log
        sumin += 1.0/s.get_gpa();//หาผลรวม invers

        if(s.get_gpa()>max) max =s.get_gpa();//หาค่า max
        if(s.get_gpa()<min) min =s.get_gpa();//หาค่า min
    }

    double ari_mean = sum/n; //ค่าเฉลี่ย = sum / N

    for(student &s:students){
        sumsqrt += pow((s.get_gpa()-ari_mean),2);//หาผลรวมของกําลังสองของผลต่างค่าเฉลี่ย
}

        double std_dev = sqrt(sumsqrt/n); // sqrt( Σ(x - mean)^2 / N )
        double geo_mean = exp(sumlog/n); // (x1 × x2 × x3 × ... × xN)^(1/N)
        double harm_mean = n/sumin; // N / sumin
        double max_gpa = max;//max
        double min_gpa = min;//min

//แสดงผลค่ากลาง
    file << "------------ Class Statistics ------------"<<endl;

    file<<fixed<<setprecision(2);

    file<< "Arithmetic Mean      = " << ari_mean << endl//ค่าเฉลี่ยเลขคณิต
        << "Standard Deviation   = " << std_dev << endl//ส่วนเบี่ยงเบนมาตรฐาน
        << "Geometric Mean       = " << geo_mean << endl//ค่าเฉลี่ยเรขาคณิต
        << "Harmonic Mean        = " << harm_mean << endl//ค่าเฉลี่ยฮาร์โมนิก
        << "Max GPA              = " << max_gpa << endl//ค่าสูงสุด
        << "Min GPA              = " << min_gpa << endl;//ค่าตํ่าสุด
    
  
    
    file << "-------------------------------------------\n\n";
    
    file.close();

    cout<<"Saved to students.txt\n";//แจ้งเตือนว่าบันทึกแล้ว
}


/**********************************************************************/
//8 load from file


/*
void studentmanager::load_from_file(){
    //อ่านไฟล์ student.txt
    ifstream file("students.txt");

    //ถ้าอ่านไม่สําเร็จ จะแจ้งว่าไม่พบ
    if(!file){
        cout<<"File not found\n";
        return;
    }

    cout<<"Load complete\n";//แจ้งเตือนเมื่ออ่านสําเส็จ

    file.close();
}
*/

void studentmanager::load_from_file(){
    //อ่านไฟล์
    ifstream file("students.txt");

    //กรณีไฟล์มีปัญหา
    if(!file){
        cout<<"Error opening file\n";
        return;
    }
    //ล้างข้อมูลก่อน (เกิดข้อมูลต่อกันซํ้า)
    students.clear();

    string line;
    //วนทีละบันทัด
    while(getline(file,line)){
        //ข้อมูลที่ไม่ต้องการ

        /*
        //หยุดอ่าน เมื่อเจอ statistics data
        if(line.find("Class Statistics") != string::npos)
        break;
        */
        
        //ข้าม header (ต้องการแค่ข้อมูล นร)
        if(line.find("Student Data") != string::npos ||
        line.find("====") != string::npos ||
        line.find("----") != string::npos ||
        line.find("No") != string::npos ||
        line.empty())
        continue;
        
        stringstream ss(line); //อ่าน string 

        //ประกาศตัวแปร
        int no;
        string id;
        double gpa;

        //อ่าน no และ id    ss ถ้าอ่านไม่ได้ ให้ข้าม
        if(!(ss>>no>>id))
            continue;

        string name;
        string temp;//สร้างพื้นที่จัดเก็บ

        vector<string> words;

        while(ss>>temp)
            words.push_back(temp);
        //อ่านคำที่เหลือในบรรทัดทั้งหมดใส่ vector words เพราะเรายังไม่รู้ว่า name มีกี่คำ

        if(words.empty())
            continue;
        //ถ้าไม่มีคำเหลือเลย แสดงว่าบรรทัดนี้ข้อมูลไม่ครบ (ข้ามไป)

        //แปลง string คําสุดท้ายให้เป็น double เพื่อที่จะระบุเกรด
        try{//ถ้าแปลงได้
            gpa = stod(words.back());
        }
        //แปลงไม่ได้
        catch(...){
            continue;//แทนที่จะแคสต่อ ก็ข้ามไป
        }

        words.pop_back();//เอา gpa ออกจาก vector words มาใช้ต่อ เหลือแค่ name

        //วน string name ที่เหลืออยู่
        for(int i=0;i<words.size();i++){
            name += words[i];//เอา ต่อกันไป
            if(i != words.size()-1)//เช็คว่าไม่ใช่คําสุดท้าย
                name += " ";//เพิ่ม_สําหรับชื่อที่เว้นวรรค (ต่อไม่ติดกัน)
        }
        //เก็บลงใน vector เลย
        students.push_back(student(id,name,gpa));
    }

    file.close();

    cout<<"Load complete\n";

}
















