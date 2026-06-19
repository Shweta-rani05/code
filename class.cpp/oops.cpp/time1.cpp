#include<iostream>
using namespace std;

class Twelve{
    public:
    int min; //minutes
    int hr; //hour
    string time; //time
    
    Twelve(int h,int m,string t){
        if (h < 1 || h > 12) {
            cout<<"Hour must be between 1 and 12 in 12-hour format."<<endl;
        }
        if (m < 0 || m >= 60) {
            cout<<"Minutes must be between 0 and 59."<<endl;
        }
        if (t != "am" && t != "pm") {
            cout<<"Time period must be 'am' or 'pm'."<<endl;
        }
        min = m;
        hr = h;
        time = t;
    }
    
    void display(){
        cout<<hr<<":"<<min<<" "<<time<<endl;
    }
    
};

class TwentyFour{
    public:
    int min;
    int hr;
    
    TwentyFour(int h,int m){  // constructor call 
        min = m;
        hr = h;
    }

    TwentyFour(Twelve t){
        min = t.min;
        if(t.time=="pm" && t.hr !=12){
            hr= 12 + t.hr;
        }else if(t.time=="am" && t.hr ==12){
            hr =0;
        }else{
            hr =t.hr;
        }
        
    }

    void display(){
        cout<<hr<<":"<<min<<endl;
    }
};

int main(){
    Twelve t1(3,45, "pm");
    TwentyFour t2 = t1;
    t2.display();

    return 0;
}