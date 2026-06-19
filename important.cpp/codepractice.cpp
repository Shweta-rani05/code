#include<iostream>
using namespace std ;

template <typename T>
void bubblesort(T arr[] , int size){
   for(int i =0 ;i< size-1;i++  ){
      for(int j=0; j<size -i-1 ;j++){
         if(arr[j] > arr[j+1]){
            //swap elements 
            T temp =arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp ;
         }
      }
   }
}

template <typename T>
void printArray(T arr[],int size){
   for(int i =0;i<size-1;i++){
      cout <<arr[i] <<"";
   }
   cout <<endl;
}

int main(){
   int intArr[] = {5,1,4,8};
   double doubleArt[]= {2.5,1.2,4.8,3.1};
   int intSize = sizeof(intArr)/sizeof(intArr[0]);
   int doubleSize = sizeof(doubleArr)/sizeof(doubleArr[0]);

   cout << "Original integer array";
   printArray(intArr,intSize);
}

