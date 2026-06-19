#include <iostream>
#include <vector>
using namespace std;

// Recursive approach (Exponential Time Complexity)
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Memoization (Top-down DP)
int fibDP(int n, vector<int> &f) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (f[n] != -1) {
        return f[n];
    }

    f[n] = fibDP(n - 1, f) + fibDP(n - 2, f);
    return f[n];
}

// Tabulation (Bottom-up DP)
//smallest to largest 
int fibTab(int n) {
    vector<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n = 5;

    // Recursive
    cout << "Recursive: " << fib(n) << endl;

    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << fibDP(n, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << fibTab(n) << endl;

    return 0;
}