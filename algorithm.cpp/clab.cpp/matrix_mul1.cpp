//matrix multiplication by taking input form the user 
#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum matrix dimension

// Function to input a matrix
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Recursive function to calculate single element of result matrix
// Calculates result[row][col] by computing dot product of row 'row' of A and column 'col' of B
int calculateElement(int A[][MAX_SIZE], int B[][MAX_SIZE], int row, int col, int k, int common) {
    // Base case: when we've processed all elements in the dot product
    if (k == common) {
        return 0;
    }
    
    // Recursive case: current element + rest of the dot product
    return (A[row][k] * B[k][col]) + calculateElement(A, B, row, col, k + 1, common);
}

// Recursive function to fill entire result matrix
void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], 
                     int rowsA, int colsB, int common, int i, int j) {
    // Base case: if we've processed all rows
    if (i == rowsA) {
        return;
    }
    
    // If we've completed current row, move to next row
    if (j == colsB) {
        multiplyMatrices(A, B, result, rowsA, colsB, common, i + 1, 0);
        return;
    }
    
    // Calculate current element recursively
    result[i][j] = calculateElement(A, B, i, j, 0, common);
    
    // Move to next column
    multiplyMatrices(A, B, result, rowsA, colsB, common, i, j + 1);
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    
    cout << "=== Recursive Matrix Multiplication (No Vectors) ===" << endl;
    cout << "Maximum matrix size supported: " << MAX_SIZE << "x" << MAX_SIZE << endl;
    cout << "Note: For multiplication A×B, columns of A must equal rows of B" << endl << endl;
    
    // Input dimensions for first matrix
    cout << "Enter dimensions of first matrix:" << endl;
    cout << "Rows (max " << MAX_SIZE << "): ";
    cin >> rowsA;
    cout << "Columns (max " << MAX_SIZE << "): ";
    cin >> colsA;
    
    // Validate dimensions
    if (rowsA <= 0 || colsA <= 0 || rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        cout << "Invalid dimensions for first matrix!" << endl;
        return 1;
    }
    
    // Input dimensions for second matrix
    cout << "\nEnter dimensions of second matrix:" << endl;
    cout << "Rows (max " << MAX_SIZE << "): ";
    cin >> rowsB;
    cout << "Columns (max " << MAX_SIZE << "): ";
    cin >> colsB;
    
    // Validate dimensions
    if (rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        cout << "Invalid dimensions for second matrix!" << endl;
        return 1;
    }
    
    // Check if multiplication is possible
    if (colsA != rowsB) {
        cout << "\nError: Matrix multiplication not possible!" << endl;
        cout << "Columns of first matrix (" << colsA << ") must equal rows of second matrix (" << rowsB << ")" << endl;
        return 1;
    }
    
    // Input matrices
    cout << "\n--- Input First Matrix ---" << endl;
    inputMatrix(A, rowsA, colsA);
    
    cout << "\n--- Input Second Matrix ---" << endl;
    inputMatrix(B, rowsB, colsB);
    
    // Initialize result matrix
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform recursive multiplication
    cout << "\nPerforming recursive matrix multiplication..." << endl;
    multiplyMatrices(A, B, result, rowsA, colsB, colsA, 0, 0);
    
    // Display results
    cout << "\n=== RESULTS ===" << endl;
    cout << "\nFirst Matrix A (" << rowsA << "x" << colsA << "):" << endl;
    displayMatrix(A, rowsA, colsA);
    
    cout << "\nSecond Matrix B (" << rowsB << "x" << colsB << "):" << endl;
    displayMatrix(B, rowsB, colsB);
    
    cout << "\nResult Matrix A×B (" << rowsA << "x" << colsB << "):" << endl;
    displayMatrix(result, rowsA, colsB);
    
    return 0;
}