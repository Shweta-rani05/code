#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    // Base case: target 0 is always possible (empty subset)
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Print dp table
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {4,2,7,1,3};
    int target = 10;
    cout << (targetSum(nums, target) ? "Yes" : "No") << endl;
    return 0;
}
