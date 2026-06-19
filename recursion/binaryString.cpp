//for print the binary string of size N without any consecutive 1s

#include<iostream>
#include<string>
using namespace std;

// void binstr(int n,int lastPlace , string ans){
//     if(n == 0){
//         cout << ans << endl;
//         return;
//     }

//     if(lastPlace != 1){
//         binstr(n-1,0,ans+'0');
//         binstr(n-1,1,ans+'1'); 
//     }else{
//         binstr(n-1,0,ans+'0');
//     }

// } using lastvariable 


//without lastvariable 
void binstr(int n,string ans){
    if(n == 0){
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1] !='1' ){ //incase of == '0' shrif ek call jaige kyuki ans initially empty string h 
        binstr(n-1,ans+'0');
        binstr(n-1,ans+'1'); 
    }else{
        binstr(n-1,ans+'0');
    }

}

int main(){
    string ans = "";
    binstr(3,ans);
    return 0;
}