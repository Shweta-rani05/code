/*
Author - Shweta (231653)
Program (01)- Write a swap function to swap two integer values using pass by reference
args-temp,a,b
class- Swapper()

*/
#include <iostream>

using namespace std;

class Swapper {
public:
    void swap(int& a, int& b) { //constructor 
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    int x = 10, y = 20;
    
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    
    swap(x, y); // Call the swap function 
    
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}