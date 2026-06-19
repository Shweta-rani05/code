#include <iostream>
using namespace std;

class UserDefined {
    int value;
public:
    // Constructor to convert basic type (int) to user-defined type
    UserDefined(int x) {
        value = x;
    }
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    int basicValue = 42;
    UserDefined obj = basicValue; // Conversion happens here
    obj.display();
    return 0;
}


// User-Defined to Basic Conversion
#include <iostream>
using namespace std;

class UserDefined {
    int value;
public:
    UserDefined(int x) : value(x) {} // Constructor for initialization
    
    // Overloading type-cast operator to convert to basic type
    operator int() {
        return value;
    }
};

int main() {
    UserDefined obj(99); // User-defined type
    int basicValue = obj; // Conversion to basic type
    cout << "Basic Value: " << basicValue << endl;
    return 0;
}



//User-Defined to User-Defined Conversion
#include <iostream>
using namespace std;

class TypeA {
    int value;
public:
    TypeA(int x) : value(x) {} // Constructor
    int getValue() const { return value; }
};

class TypeB {
    int data;
public:
    TypeB(TypeA a) { // Conversion from TypeA to TypeB
        data = a.getValue();
    }
    void display() {
        cout << "Data in TypeB: " << data << endl;
    }
};

int main() {
    TypeA objA(55); // Object of TypeA
    TypeB objB = objA; // Conversion from TypeA to TypeB
    objB.display();
    return 0;
}