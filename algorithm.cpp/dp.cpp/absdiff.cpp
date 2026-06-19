#include<iostream>
#include<vector>
using namespace std ;

int main(){
    vector<int> A = {4,1,8,9};
    vector<int> B = {2,3,6,5};
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    return 0;

    int absDiff =0;
    for(int i =0;i<A.size();i++){
       absDiff +=abs(A[i] - B[i]);
    }

    cout << "MIN abs Diff = " <<absDiff <<endl;
    return 0 ;
}
