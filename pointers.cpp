#include<iostream>
using namespace std;

void changeA(int* ptr) {
    *ptr = 10; // Dereference the pointer and assign the value 10
}

int main() {
    int a = 20;
    changeA(&a);
    cout << a << endl; // This will now print 10

}

