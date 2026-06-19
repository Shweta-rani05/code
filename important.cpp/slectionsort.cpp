#include<iostream>
using namespace std;

void selectionsort(int arr[],int n ){ //O(n*n)
    for(int i=0;i<n-1;i++){ //1*n
        int smallestIdx = i;
        for(int j=i+1;j<n; j++){
            if(arr[j]<arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap( arr[i],arr[smallestIdx]);
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i] << "";
    }
    cout<< endl;
}


int main(){
    int n=5;
    int arr[]={4,1,5,2,3};
    selectionsort(arr,n);
    printarray(arr,n);
    return 0;
}