//program for finding single element in an sorted array

#include<iostream>
#include<vector>

using namespace std;
int singleElement(vector<int> arr){
    int st=0,end=arr.size()-1;
    if(arr.size()==1){
        return arr[0];
    }

    while(st<=end){
        int m=st+(end-st)/2;
        if(m==st && st!=arr[1]){
            return arr[m];
        }
        if(m==end && end!=end-1){
            return arr[m];
        }
        if(arr[m-1]!=arr[m] && arr[m]!=arr[m+1]){
            return m;
        }

        if(m%2==0){//even
            if(arr[m-1]==arr[m]){
                end=m-1;
            }else{
                st=m+1;
            }
        }else{
            if(arr[m-1]==arr[m]){
                st=m+1;
            }else{
                end=m-1;
            }
        }
    }
}

int main(){
    vector<int> arr={1,1,2,2,3};
    cout<< singleElement(arr)<<endl;
    
}