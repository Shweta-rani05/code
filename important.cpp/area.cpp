#include<iostream>
using namespace std;

int area(int);
float area(int,int);

int main()
{
    int a;
    cout<<"enter the length of side";
    cin>>a;
    cout<<endl;
    cout<<"area of the square is " <<area(a);
    cout<<endl;
    int l,b;
    cout<< "enter the length and width of the rectangle ";
    cin>>l>>b;
    cout<<"area of the rectangle is " <<area(l,b);
    cout<<endl;

}

float area (int l,int b)
{
    return l*b;
}

int area(int a)
{
    return a*a;

}