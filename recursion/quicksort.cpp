#include<iostream>
#include<vector>
using namespace std;


int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for(int j=si;j<ei;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
}

void quickSort(int arr[], int si , int ei){ //O(log n )
    if(si >= ei){
        return ;
    }
    int pivotIdx = partition(arr,si, ei);

    quickSort(arr,si,pivotIdx-1);
    quickSort(arr,pivotIdx+1,ei);

}

void prinArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] ={6,3,7,10,15,5,2,4};
    int n = 8 ;
    quickSort(arr,0,n-1);
    prinArr(arr,n);
    return 0 ;
}  