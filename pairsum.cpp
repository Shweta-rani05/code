#include<iostream>
#include<vector>
using namespace std;


// vector<int>pairSum(vector<int>nums ,int target){
//     vector<int>ans;
//     int n = nums.size();
//     for(int i =0;i<n;i++){
//         for(int j= 0;j<n;j++){
//             if(nums[i]+nums[j]== target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
// }

vector<int>pairSum1(vector<int>nums ,int target){
    vector<int>ans;
    int n = nums.size();
    int i=0 , j=n-1;
    while (i<j){
        int pairSum1= nums[i]=nums[j];
        if(pairSum1> target){
            j++;
        }else if(pairSum1 <target ){
            i++;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
           
        }
    
    }
}




int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
   // vector<int>ans = pairSum(nums,target );
    vector<int>ans = pairSum1(nums,target );
    cout << ans[0] << " ,"<< ans[1]<< endl;
    return 0;

}