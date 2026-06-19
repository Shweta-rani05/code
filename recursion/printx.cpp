//to calculate x**n 
//recursion basic se salove kro 

#include<iostream>
#include<vector>
using namespace std;

int pow(int x, int n){  //TC:O(logn)
    if(n==0){
        return 1;
    }

    int halfpow = pow(x,n/2);
    int halfpowsquare = halfpow * halfpow;

    if(n % 2 != 0){ //odd 
        return x * halfpowsquare;
    }
    return halfpowsquare ; //even
}

int main(){
    cout << pow(2,5) << endl;
    return 0 ;
}


