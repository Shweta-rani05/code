#include<iostream>
#include<vector> // Uncommented this line to include the vector header
#include<algorithm> // Include this for the sort function
using namespace std;

void sortcolor(vector<int>& arr) { // brute force approach 
    sort(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {2, 3, 0, 0, 0, 3, 2, 3, 2, 3, 0};
    sortcolor(arr);

    // Printing the sorted array to verify the output
    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}


