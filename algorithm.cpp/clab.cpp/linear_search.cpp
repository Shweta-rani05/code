//program for recursive linear search 
#include<iostream>
using namespcae std ;

int linear_search(int arr[] , int n ,int i , int key ){
    //base case
    if(i>= n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    //recursive case
    return linear_search(arr,n,i+1 , key );
}

// int main(){
//     int arr[] = {1,2,3,4,5};
//     int key = 3 ;
//     cout <<linear_search(arr , n,0,key);
//     return 0 ; 
//}

int main(){
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }

    int key ;
    cin >> key;
    cout << linear_search(arr , n , 0, key);
    return 0 ; 
}