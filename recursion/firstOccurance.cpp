#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int>arr,int i,int target){
    if(i==arr.size()){
        return -1;
    }

    if(arr[i]==target){
        return i;
    }
    return firstOccurance(arr,i+1,target);
}

int lastOccurance(vector<int>arr,int target ,int i){
    if(i==arr.size()){
        return -1;
    }

    int idxfound = lastOccurance(arr,target,i+1);
    if(idxfound == -1 && arr[i] == target){
        return i;
    }
    return idxfound;
}

int main(){
    vector<int>arr ={1,34,4,32,2,1,3};
    // cout<< firstOccurance(arr,0,32) <<endl;
    cout<< lastOccurance(arr,4,0) <<endl;
    return 0;
}