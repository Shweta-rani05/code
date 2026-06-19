//code for knapsack 0-1
#include<iostream>
#include<vector>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt , int W, int n){

    if(n == 0 || W == 0){
        return 0 ;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W){
        //include
        int ans1 =knapsackRec(val,wt,W-itemWt ,n-1) + itemVal ; 

        //exclude
        int ans2 = knapsackRec(val,wt,W,n-1);
        return max(ans1,ans2);
    }else{
        //exclude
        return knapsackRec(val,wt,W,n-1);
    }


}

int main(){
    vector<int> val = {15 , 14 , 10,45, 30};
    vector<int> wt = {2,4,1,3,4};
    int W = 7;
    int n = 5;

    return 0 ;
}

 