#include<iostream>
using namespace std;

int main(){
    int size = 5;
    int marks[size];
    int smallest= INT8_MAX;
    int largest = INT8_MIN ; 

    //input from the user
    for(int i= 0;i<size;i++){
        cin >> marks[i];
    }

    //loop for output
     for(int i= 0;i<size;i++){
        cout << marks[i]<< endl;
    }

    //for smalllest no.
    for(int i = 0;i<size ; i++){
        if(marks[i]< smallest){  //inbuilt function min 
             smallest = marks[i];
              largest = max(marks[i],largest);  //smallest = min(num[i],smallest)
             }      
        }
        
    cout << "smallest ="<< smallest << endl;
    cout << "largest =" << largest <<endl;
    return 0 ;
} 