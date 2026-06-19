//climbing stairs problem 

#include<iostream>
#include<vector>
using namespace std;

int countWaysRec(int n ){ //  TC : 0(n)
    if(n ==0 || n==1){
        return 1;
    }
    return countWaysRec(n-1) + countWaysRec(n-2);
}

int countWaysMem(int n, vector<int> &dp) { //TC : O(n) 
    if (n == 0 || n == 1) {
        return 1 ;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = countWaysMem(n - 1, dp) + countWaysMem(n - 2, dp);
    return dp[n];
}

int countWaysTab(int n ) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


int main() {
    int n = 5;

    // Recursive
    cout << "Recursive: " << countWaysRec(n) << endl;

    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << countWaysMem(n, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << countWaysTab(n) << endl;

    return 0;
}

