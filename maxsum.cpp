#include<iostream>
#include<vector>
using namespace std;

int main(){   //to find max sum of an given array 
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum = INT8_MIN; 

    for (int st= 0; st<n; st++){
        int currSum = 0 ;
        for(int end=st; end<n; end++){
            currSum = arr[end]+ currSum;
            maxSum = max(currSum,maxSum);
            
            }
            cout<< " ";
        }
        cout << "max subarray sum = "<< maxSum <<endl;
    }
