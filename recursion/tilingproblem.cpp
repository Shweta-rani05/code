//for n==0 ways = 1 , kyuki koi bhi tile fill nhi krna bhi ek way h, tile ko fill krne ka 
#include<iostream>
#include<vector>
using namespace std;

int tilingproblem(int n){
    if(n==0|| n==1){
        return 1;
    }

    //vertical
    int ans1 = tilingproblem(n-1);  //2*(n-1)
    //horizontal
    int ans2 = tilingproblem(n-2); //2*(n-2)

    return ans1+ans2; //return tilingproblem(n-1)+tilingproblem(n-2);
}

int main(){
    int n = 5;
    cout << tilingproblem(n) <<endl;
    return 0;
}