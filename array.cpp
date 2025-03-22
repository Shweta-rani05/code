#include<iostream>
using namespace std;
// function for creating the array by taking input from the user 
int main(){
    int size = 5;
    int marks[size];

    //input from the user
    for(int i= 0;i<size;i++){
        cin >> marks[i];
    }

    //loop for output
     for(int i= 0;i<size;i++){
        cout << marks[i]<< endl;
    }
    return 0 ;
} 