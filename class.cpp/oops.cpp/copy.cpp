/*
Program (03)-Demonstrate shallow copy and deep copy
args:data,value
method:class ShallowDeepCopy()-display()
*/

#include <iostream>
#include <cstring>

using namespace std;

class ShallowDeepCopy {
private:
    char* data; // Pointer to dynamically allocated memory
public:
    // Constructor
    ShallowDeepCopy(const char* value) {
        data = new char[strlen(value) + 1]; // Allocate memory
        strcpy(data, value);
    }

    // **Shallow Copy Constructor**
    ShallowDeepCopy(const ShallowDeepCopy& other) {
        data = other.data; // Copy pointer, not memory (shallow copy)
    }

    // **Deep Copy Constructor**
    ShallowDeepCopy(const ShallowDeepCopy& other, bool deepCopy) {
        if (deepCopy) {
            data = new char[strlen(other.data) + 1]; // Allocate new memory
            strcpy(data, other.data); // Copy actual data
        } else {
            data = other.data; // Shallow copy
        }
    }

    // Display function
    void display() const {
        cout << "Data: " << data << endl;
    }

    // Destructor
    ~ShallowDeepCopy() {
        delete[] data; // Free allocated memory
    }
};

int main() {
    ShallowDeepCopy original("Hello");

    // Shallow Copy
    ShallowDeepCopy shallowCopy = original;
    cout << "Original object: ";
    original.display();
    cout << "Shallow copy: ";
    shallowCopy.display();

    // Deep Copy
    ShallowDeepCopy deepCopy(original, true);
    cout << "Deep copy: ";
    deepCopy.display();

    return 0;
}