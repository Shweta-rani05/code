#include<iostream>
#include<vector>
using namespace std ;

vector<int> plusOne(vector<int>& digit) {
    int n = digit.size();
    int i=0;
    for(int i=0;i<n;i++){
        digit[n-1]= digit[i]+1;
    }
    void display(){
        for(int i=0;i<n;i++){
            cout<<digit[i]<<endl;
        }
    }
}

int main(){
    vector<int> digit = {1,2,3};
    plusOne(digit);
    display();

}