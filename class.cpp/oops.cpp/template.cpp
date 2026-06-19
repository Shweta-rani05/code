/*
program (09):Write a Class Template to implement Stack.
args:typename T
method:push(),pop(),isEmpty(),size()
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements; // Using a vector for dynamic storage

public:
    // Push element onto stack
    void push(T value) {
        elements.push_back(value);
    }

    // Pop element from stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty! Cannot pop." << endl;
        }
    }

    // Peek top element of stack
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            throw runtime_error("Stack is empty! No top element.");
        }
    }

    // Check if stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get size of stack
    int size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl;

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    
    cout << "Top element in string stack: " << stringStack.top() << endl;
    
    return 0;
}