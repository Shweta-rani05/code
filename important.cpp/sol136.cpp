#include<iostream>
#include<vector>
using namespace std;

class sol {
    public: // Changed to public so it can be accessed from outside the class
    int singleNumber(vector<int>& num){
        int ans = 0;
        for (int val : num){
            ans = ans ^ val;
        }
        return ans;
    }
};

int main(){
    vector<int> num = {1,2,3,2,1};
    sol solution; // Create an instance of the sol class
    int result = solution.singleNumber(num); // Call the singleNumber method on the instance
    cout << "The single number is: " << result << endl;
    return 0;
}
