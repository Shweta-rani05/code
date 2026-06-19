/*
program for operator overloading 
*/

#include<iostream>
using namespace std;

class demo{
    public:
    int a;
    void getdata(){
        cout<<"enter a no."<<endl;
        cin>>a;
    }
    void putdata(){
        cout<<"value"<<" "<<a<<endl;
    }

    void operator++(){ //operator overloading 
        // demo cc;
        // cc.a = a+ bb.a;
        // return cc;
        a=a+1;
    }
    void operator++(int){//a++ case-value is mandatory which get implicitly handle by the compiler
        a=a+1;
    }

    void operator=(demo bb){//assignment operator
        a=bb.a;
    }
    void display(){
        cout<<"value of a"<<endl;
    }
};

int main(){
    // demo aa,bb,cc;
    // aa.getdata();
    // bb.getdata();
    // cc=aa+bb;
    // cc.putdata();
    // return 0;
    demo aa;
    aa.getdata();
     aa++;
    aa.putdata();
    // ++aa;
    aa.putdata();
    return 0;
}