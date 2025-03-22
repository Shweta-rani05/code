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
    operator Twelve(){
        int hour12 = hr;
        string period ="am";

        if(hr == 0){
            hour12= 12;
        }else if(hr == 12){
            period = "pm";
        }else if(hr >12){
            hour12 = hr-12;
            period="pm";
        }
        return Twelve(hour12,min,period);
    }

    void display(){
        cout<<hr<<":"<<min<<endl;
    }

    

};

int main(){
    Twelve t1(1, 45, "am");
    TwentyFour t2 = t1;
    t2.display();
    

    TwentyFour t3(13,56);
    Twelve t4= t3;
    t4.display();

    return 0;
}