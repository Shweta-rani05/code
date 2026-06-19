//code for matrix multiplication 
#include<iostream>
using namespace std ;

void inputMat(int mat[][MAX_SIZE] , int rows , int cols){
    for(int i=0;i = rows ;i++){
        for(int j= 0;j = cols ;j++){
            cout << "Enter element of "<< rows << "x" << cols << endl;
            cin >> mat[i][j] ; 
        }
    }
}

void displaymat(int mat[][MAX_SIZE] , int rows , int cols){
    for(int i=0;i = rows ;i++){
        for(int j= 0;j = cols ;j++){
            cout << mat[i][j] << endl; 
        }
    }
}

void calculateElement(int A[][MAX_SIZE],int B[][MAX_SIZE],int rows,int cols , int k , int common ){
    if(k == common ){
        return 0 ;
    }
    return ( A[rows][k] * B[k][cols]) + calculateElement(A,B,rows,cols,k+1 , common);
}

void multiplymatrix(int A[][MAX_SIZE] , int B[][MAX_SIZE] , int result[][MAX_SIZE],int rowA,int colB,int common ,int i ,int j ){
    if(i == rowA){
        return; 
    }
    if(j == colB){
        multiplymatrix(A, B , result , rowA,colB , common ,i+1 , 0);
        return ;
    }
    result[i][j] = calculateElement(A,B,i,j,0,common);
    multiplymatrix(A,B,result ,rowA,colB,common,i , j+1);
}

int main(){
    int A[MAX_SIZE][MAX_SIZE],int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE] ;
    int rowA,colB ,rowB ,colB;

    cout << "Maximum matrix size supported "<<MAX_SIZE << "x " << MAX_SIZE << endl;
    cout << "Rows "<< MAX_SIZE << endl;
    cin >> rowA;
    cout << "Cols "<< MAX_SIZE << endl;
    cin >> rowA;
     
}

