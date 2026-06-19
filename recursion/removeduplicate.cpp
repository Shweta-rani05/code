//function for removing duplicates from a string 
// #include<iostream>
// #include<string>
// using namespace std;

// void removeDuplicates(string str, string ans,int i,int map[26]){
//     if(i== str.size()){
//         cout << "ans:"<< ans << endl;
//         return;
//     }

//     int mapidx = (int)(str[i]-'a');
    
//     if(map[mapidx]){
//         removeDuplicates(str,ans,i+1,map);
//     }else{
//         map[mapidx] = true;
//         removeDuplicates(str,ans+str[i],i+1,map);
//     }
// }

// int main(){

//     string str="appnacollegemnp";
//     string ans = "";
//     int map[26] = {false};

//     removeDuplicates(str,ans,0,map);
//     return 0 ;
// }

//without i code 
#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string str, string ans,int map[26]){
    if( str.size()==0){
        cout << "ans:"<< ans << endl;
        return;
    }
    int n = str.size(); 
    char ch = str[n-1];
    int mapidx = (int)(str[n-1]-'a');
    str = str.substr(0,n-1);
    
    if(map[mapidx]){
        removeDuplicates(str,ans,map);
    }else{
        map[mapidx] = true;
        removeDuplicates(str,ch+ans ,map);
    }
}

int main(){

    string str="appnacollege"; //last se duplicate remove hoge 
    string ans = "";
    int map[26] = {false};

    removeDuplicates(str,ans,map);
    return 0 ;
}