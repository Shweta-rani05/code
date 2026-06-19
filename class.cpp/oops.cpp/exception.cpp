#include<iostream>
using namespace std;

int main(){
    int numerator,denominator,result;
    cout<<"enter numerator and denominator :" << endl;
    cin>>numerator>>denominator;

    try{
        if(denominator == 0){
            throw denominator;
        }
        result=numerator/denominator;// divison occur here
    }
    catch(int ex){
        cout<<"expection : Divide by zero is not allowed  !!"<<ex<<endl;
    }
    
    
    cout<< "Division is:"<< result;

    return 0;
}