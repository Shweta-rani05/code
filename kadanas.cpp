#include<iostream>
#include<vector>
using namespace std;

int main(){   //to find max sum of an given array 
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum = INT8_MIN;
    int currSum =0;

    for (int st= 0; st<n; st++){
        currSum = arr[st]+ currSum ;// using kadana's algorithm
        maxSum = max(currSum,maxSum );
        if (currSum <0 ){
            currSum = 0 ;

        } 
        //cout << "max subarray sum = "<< maxSum <<endl;
    }
    cout << "max subarray sum = "<< maxSum <<endl;
}