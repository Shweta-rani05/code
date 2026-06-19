#include <iostream>
#include <string>
using namespace std;

// Abstract base class 'Person'
class Person {
protected:
    string name;
    int age;

 public:
     Person(string n, int a) : name(n), age(a) {} // Constructor
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Person() {} // Virtual destructor for proper cleanup
};

// Derived class 'Employee'
class Employee : public Person {
protected:
    int employeeID;
    string department;

public:
    Employee(string n, int a, int id, string dept) 
        : Person(n, a), employeeID(id), department(dept) {} // Constructor

    // Override displayInfo
    void displayInfo() const override {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nEmployee ID: " << employeeID 
             << "\nDepartment: " << department << endl;
    }
};

// Further derived class 'Manager'
class Manager : public Employee {
    int teamSize;
    double budget;

public:
    Manager(string n, int a, int id, string dept, int tSize, double b) 
        : Employee(n, a, id, dept), teamSize(tSize), budget(b) {} // Constructor

    // Override displayInfo
    void displayInfo() const override {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nEmployee ID: " << employeeID 
             << "\nDepartment: " << department 
             << "\nTeam Size: " << teamSize 
             << "\nBudget: $" << budget << endl;
    }
};

int main() {
    // Create a Manager object (concrete implementation of Person)
    Manager manager("John Doe", 45, 101, "IT", 10, 50000.0);

    // Use base class pointer for abstraction and polymorphism
    Person* personPtr = &manager;

    // Display complete information
    personPtr->displayInfo();

    return 0;
}