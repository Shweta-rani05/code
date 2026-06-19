#include<iostream>
using namespace std;
int sum(int,int,int=0);
int main()
{
    int x,y,z;
    cout<<"enter the values";
    cin>>x>>y>>z;
    cout<< "sum is"<<sum(x,y,z);
    return 0;
}

int sum(int x,int y,int z)
{
    return x+y+z;
}