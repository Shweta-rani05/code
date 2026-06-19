#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 64; // Maximum matrix size (must be power of 2)

// Function to input a matrix
void inputMatrix(int matrix[][MAX_SIZE], int n) {
    cout << "Enter elements of " << n << "x" << n << " matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to add two matrices
void addMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to copy a submatrix from source to destination
void copySubMatrix(int source[][MAX_SIZE], int dest[][MAX_SIZE], int startRow, int startCol, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = source[startRow + i][startCol + j];
        }
    }
}

// Function to copy a matrix back to a submatrix of destination
void copyToSubMatrix(int source[][MAX_SIZE], int dest[][MAX_SIZE], int startRow, int startCol, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[startRow + i][startCol + j] = source[i][j];
        }
    }
}

// Standard matrix multiplication for base case
void standardMultiply(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's matrix multiplication algorithm
void strassenMultiply(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int n) {
    // Base case: if matrix size is small, use standard multiplication
    if (n <= 2) {
        standardMultiply(A, B, C, n);
        return;
    }
    
    int newSize = n / 2;
    
    // Temporary matrices for submatrices
    int A11[MAX_SIZE][MAX_SIZE], A12[MAX_SIZE][MAX_SIZE], A21[MAX_SIZE][MAX_SIZE], A22[MAX_SIZE][MAX_SIZE];
    int B11[MAX_SIZE][MAX_SIZE], B12[MAX_SIZE][MAX_SIZE], B21[MAX_SIZE][MAX_SIZE], B22[MAX_SIZE][MAX_SIZE];
    int C11[MAX_SIZE][MAX_SIZE], C12[MAX_SIZE][MAX_SIZE], C21[MAX_SIZE][MAX_SIZE], C22[MAX_SIZE][MAX_SIZE];
    
    // Temporary matrices for Strassen's intermediate results
    int P1[MAX_SIZE][MAX_SIZE], P2[MAX_SIZE][MAX_SIZE], P3[MAX_SIZE][MAX_SIZE], P4[MAX_SIZE][MAX_SIZE];
    int P5[MAX_SIZE][MAX_SIZE], P6[MAX_SIZE][MAX_SIZE], P7[MAX_SIZE][MAX_SIZE];
    
    // Temporary matrices for calculations
    int temp1[MAX_SIZE][MAX_SIZE], temp2[MAX_SIZE][MAX_SIZE];
    
    // Divide matrices A and B into 4 submatrices each
    copySubMatrix(A, A11, 0, 0, newSize);
    copySubMatrix(A, A12, 0, newSize, newSize);
    copySubMatrix(A, A21, newSize, 0, newSize);
    copySubMatrix(A, A22, newSize, newSize, newSize);
    
    copySubMatrix(B, B11, 0, 0, newSize);
    copySubMatrix(B, B12, 0, newSize, newSize);
    copySubMatrix(B, B21, newSize, 0, newSize);
    copySubMatrix(B, B22, newSize, newSize, newSize);
    
    // Calculate P1 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, temp1, newSize);
    strassenMultiply(A11, temp1, P1, newSize);
    
    // Calculate P2 = (A11 + A12) * B22
    addMatrix(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, P2, newSize);
    
    // Calculate P3 = (A21 + A22) * B11
    addMatrix(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, P3, newSize);
    
    // Calculate P4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, temp1, newSize);
    strassenMultiply(A22, temp1, P4, newSize);
    
    // Calculate P5 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, P5, newSize);
    
    // Calculate P6 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, P6, newSize);
    
    // Calculate P7 = (A11 - A21) * (B11 + B12)
    subtractMatrix(A11, A21, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassenMultiply(temp1, temp2, P7, newSize);
    
    // Calculate C11 = P5 + P4 - P2 + P6
    addMatrix(P5, P4, temp1, newSize);
    subtractMatrix(temp1, P2, temp2, newSize);
    addMatrix(temp2, P6, C11, newSize);
    
    // Calculate C12 = P1 + P2
    addMatrix(P1, P2, C12, newSize);
    
    // Calculate C21 = P3 + P4
    addMatrix(P3, P4, C21, newSize);
    
    // Calculate C22 = P5 + P1 - P3 - P7
    addMatrix(P5, P1, temp1, newSize);
    subtractMatrix(temp1, P3, temp2, newSize);
    subtractMatrix(temp2, P7, C22, newSize);
    
    // Combine the 4 submatrices into result matrix C
    copyToSubMatrix(C11, C, 0, 0, newSize);
    copyToSubMatrix(C12, C, 0, newSize, newSize);
    copyToSubMatrix(C21, C, newSize, 0, newSize);
    copyToSubMatrix(C22, C, newSize, newSize, newSize);
}

// Function to check if a number is power of 2
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Function to pad matrix to next power of 2
int padMatrix(int matrix[][MAX_SIZE], int n) {
    int newSize = 1;
    while (newSize < n) {
        newSize *= 2;
    }
    
    // Pad with zeros
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            if (i >= n || j >= n) {
                matrix[i][j] = 0;
            }
        }
    }
    
    return newSize;
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int n, originalN;
    
    cout << "=== Strassen's Matrix Multiplication ===" << endl;
    cout << "Note: This algorithm works efficiently with square matrices" << endl;
    cout << "Maximum matrix size supported: " << MAX_SIZE << "x" << MAX_SIZE << endl << endl;
    
    cout << "Enter size of square matrix (n for nxn): ";
    cin >> n;
    originalN = n;
    
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid matrix size!" << endl;
        return 1;
    }
    
    // Input matrices
    cout << "\n--- Input First Matrix A ---" << endl;
    inputMatrix(A, n);
    
    cout << "\n--- Input Second Matrix B ---" << endl;
    inputMatrix(B, n);
    
    // Pad matrices to power of 2 if needed
    if (!isPowerOfTwo(n)) {
        cout << "\nMatrix size is not a power of 2. Padding with zeros..." << endl;
        n = padMatrix(A, n);
        padMatrix(B, n);
        cout << "New padded size: " << n << "x" << n << endl;
    }
    
    // Initialize result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    
    cout << "\nPerforming Strassen's matrix multiplication..." << endl;
    
    // Perform Strassen's multiplication
    strassenMultiply(A, B, C, n);
    
    // Display results
    cout << "\n=== RESULTS ===" << endl;
    
    if (originalN != n) {
        cout << "\nFirst Matrix A (original " << originalN << "x" << originalN << ", padded to " << n << "x" << n << "):" << endl;
    } else {
        cout << "\nFirst Matrix A (" << n << "x" << n << "):" << endl;
    }
    displayMatrix(A, originalN);
    
    if (originalN != n) {
        cout << "\nSecond Matrix B (original " << originalN << "x" << originalN << ", padded to " << n << "x" << n << "):" << endl;
    } else {
        cout << "\nSecond Matrix B (" << n << "x" << n << "):" << endl;
    }
    displayMatrix(B, originalN);
    
    cout << "\nResult Matrix C = A × B (" << originalN << "x" << originalN << "):" << endl;
    displayMatrix(C, originalN);
    
    cout << "\n--- Algorithm Information ---" << endl;
    cout << "Strassen's algorithm reduces multiplication complexity from O(n³) to O(n^2.807)" << endl;
    cout << "It uses 7 recursive multiplications instead of 8 in traditional divide-and-conquer" << endl;
    
    return 0;
}