// problem for linear search

#include<iostream>
using namespace std;

int linearSearch(int *arr, int n ,int key){
    for(int i = 0 ; i <= n;i++){
        if(arr[i] == key ){
            return i;
        }
    }

    return -1;
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,10};
    int n = sizeof(arr)/sizeof(int);
    cout <<  linearSearch(arr,n,70) << endl;
    return 0 ;
    
}