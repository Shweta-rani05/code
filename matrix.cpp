#include<iostream>
using namespace std;

class matrix
{
private:
    int **mat;
    int rows , cols;
public:
    matrix(int m , int n){
        rows = m;
        cols = n;
        mat = new int* [rows];
        for(int i=0;i<rows ; i++ )
        {
            mat[i]=new int[cols];
        }
        //initialization of matrix
        for(int i=0;i<rows; i++)
        {
           for(int j=0;j<cols ; j++)
           {
               mat[i][j] = 0 ;
           }
           
        } 
    }


// function for input into the matrix

    void inputMatrix()
    {

        cout <<"enter the details for the matrix :"<< endl;
        for(int i =0;i< rows ; i++)
        { 
            for(int j =0 ; j< cols ; j++)
            {
                cout <<"enter the details ("<<i<<","<<j<<") "<< endl;
                cin >> mat[i][j];
            }
        }
   
    }

     //for output 
    void outputMatrix()
    {
        for(int i =0;i< rows ; i++)
        { 
            for(int j =0 ; j<cols ; j++)
            {
                cout<<"output of the matrix("<<i<<","<<j<<"):"<< mat[i][j];
            }
            cout << endl;
        }

    }

    //destructor to deallocate the memory 
    // ~matrix()
    // { 
    //   for(int i=0; i<rows;i++)
    //   {  
    //      delete[] mat[i];
    //   } 
    //   delete[] mat;
    // }

    void deleteMatrix()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j= 0; i<cols ;j++)
            {
                delete[] mat[i];
            }
        }
    }
  
  
};


int main()
{
  int m , n;
  cout << "Enter the no. of rows";
  cin >>m;
  cout << "Enter the no. of columns" ;
  cin >> n ;
  
  //function for input ,output from the matrix 
  matrix mat(m,n);
  mat.inputMatrix();
  mat.outputMatrix();
  //mat.deleteMatrix();
  //mat.outputMatrix();
  
  return 0 ; 

}


