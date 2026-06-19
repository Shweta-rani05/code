//for rotated search array 
#include<iostream>
#include<vector>
using namespace std;

int rotatedArray(vector<int>arr,int tar,int st,int end){
    int st=0,end=arr.size()-1;
    while(st<= end){
        int mid=st+(end-st)/2;
        if(arr[mid]==tar){
            return mid;
        }else if(arr[st]<=tar<=arr[mid]){
                end=mid-1;
                }else{
                    st=mid+1;
            } 
        else(arr[mid]<=tar<=arr[end]){
            st=mid+1;
            }else{
                end=mid-1;
            }
        }
    return -1;
    }
}
    

        




int main(){
    vector<int> arr1={3,4,6,7,0,1,2}
    int tar=0;
    cout <<rotatedArray(arr1,tar)<<endl;
}