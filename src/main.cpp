#include<iostream>
using namespace std;

int cal(int );

int main(void) 
{
    //test
    cout <<"test"<<endl;
    cout<<cal(56);
    return 0;
}

int cal(int x){
    x+=26;
    return x;
}