#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the LCS length table and direction table
void LCS_LENGTH(const string &X, const string &Y,
                vector<vector<int>> &c, vector<vector<char>> &b) {
    int m = X.length();
    int n = Y.length();

    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<char>(n + 1, ' '));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';  // Diagonal (↖)
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';  // Up (↑)
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';  // Left (←)
            }
        }
    }
}

// Function to print the LCS using the direction table
void PRINT_LCS(const vector<vector<char>> &b, const string &X, int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'D') {  // Diagonal: character matched
        PRINT_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == 'U') {
        PRINT_LCS(b, X, i - 1, j);
    } else {
        PRINT_LCS(b, X, i, j - 1);
    }
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

    vector<vector<int>> c;
    vector<vector<char>> b;

    LCS_LENGTH(X, Y, c, b);

    cout << "LCS length = " << c[X.length()][Y.length()] << endl;
    cout << "LCS = ";
    PRINT_LCS(b, X, X.length(), Y.length());
    cout << endl;

    return 0;
}
