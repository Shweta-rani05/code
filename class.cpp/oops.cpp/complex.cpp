/*
program for complex no 
*/

#include<iostream>
using namespace std;

class complex{
    public:
    int r,i;
    void getdata(){
        cout<<"real"<<r<<"image"<<i<<endl;
        cin>>r>>i;
    }
    void putdata(){
        cout<<r<<i<<endl;
    }
};

complex operator+(complex bb){
    complex cc;
    cc.r = r

}