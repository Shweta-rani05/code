/*
Program (06) : Write a program a string concatenation using operator overloading
agrs :string str1,string str2
method :MyString(),display()
*/
#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
    string str; // Internal string storage

public:
    // Constructor
    MyString(string s = "") : str(s) {}

    // Overloaded + operator for concatenation
    MyString operator+(const MyString& other) {
        return MyString(str + other.str);
    }

    // Display function
    void display() const {
        cout << str << endl;
    }
};

int main() {
    MyString str1("Hello, ");
    MyString str2("World!");
    
    MyString result = str1 + str2; // Using overloaded + operator

    cout << "Concatenated String: ";
    result.display();

    return 0;
}