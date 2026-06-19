
 #include<iostream>
 #include<vector>
 using namespace std;

//code using recursion 

// int BinarySearch(vector<int> arr,int tar){
//     int st=0,end=arr.size()-1;
//     while(st<=end){
//         int mid=(st+end)/2;
//         if(tar > arr[mid]){
//             st=mid+1;
//         }
//         else if(tar<arr[mid]){
//             st= mid-1;
//         }else{
//             return mid;
//         }
//         return -1;
//     }
// }

//recursive code

int recbinarySearch(vector<int>arr,int tar,int st,int end){
    int mid=st+(end-st)/2;
    if(tar>arr[mid]){
        return recbinarySearch(arr,tar,mid+1,end);
    }
    else if(tar<arr[mid]){
        return recbinarySearch(arr,tar,st,mid-1);
    }else{
        return mid;
    }
}

int main(){
    vector<int> arr1={-1,2,3,4,5,6,7,8};
    int tar1= 7,st=6,end=8;
    cout<< recbinarySearch( arr1, tar1,st,end)<<endl;
     return 0;
}