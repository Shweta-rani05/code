#include<iostream>
#include<vector>
using namespace std;


bool searchMatrix(vector<vector<int>>mat,int target ){
    int m=mat.size(),n=mat[0].size();
    int startRow = 0 ,endRow = m-1;
    while(startRow <= endRow){
        int midRow = startRow + (endRow - startRow)/2;
        if(target >= mat[midRow][0] && target <= mat[midRow][n-1]){
            //found the row 
        }else if(target >= mat[midRow][n-1]){
            //down-right 
            startRow = mid+1;
        }else{
            //up-left
            endRow = mid-1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> mat[4][4]={{1,2,3,4},{6,7,8,9},{11,12,15,17},{18,19,25,29}} //values are in non-decreasing order ,the first integer of each row is greater than the last integer of previous row
    int target = 25;
    cout <<searchMatrix(mat[4][4],target)<<endl;
    
}