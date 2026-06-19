// using inheritance and abstraction 
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Entity {
protected:
    string name;

public:
    Entity(string n) : name(n) {} // Constructor
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Entity() {} // Virtual destructor
};

// Doctor class derived from Entity
class Doctor : public Entity {
    string specialization;
    string department;

public:
    Doctor(string n = "", string s = "", string d = "") : Entity(n), specialization(s), department(d) {}

    void displayInfo()const override  {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization
             << ", Department: " << department << endl;
    }
};

// Department class derived from Entity
class Department : public Entity {
    Doctor doctors[10]; // Array to store doctors (max 10)
    int doctorCount;

public:
    Department(string n) : Entity(n), doctorCount(0) {}

    void addDoctor(Doctor d) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = d;
        } else {
            cout << "Cannot add more doctors to the department. Limit reached!" << endl;
        }
    }

    void removeDoctor(string doctorName) {
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i].name == doctorName) {
                for (int j = i; j < doctorCount - 1; j++) {
                    doctors[j] = doctors[j + 1];
                }
                doctorCount--;
                cout << "Doctor " << doctorName << " removed from the department." << endl;
                return;
            }
        }
        cout << "Doctor " << doctorName << " not found in the department." << endl;
    }

    void displayInfo() const override {
        cout << "Department: " << name << endl;
        for (int i = 0; i < doctorCount; i++) {
            doctors[i].displayInfo();
        }
    }
};

// Hospital class derived from Entity
class Hospital : public Entity {
    string location;
    Department departments[5]; // Array to store departments (max 5)
    int departmentCount;

public:
    Hospital(string n, string l) : Entity(n), location(l), departmentCount(0) {}

    void addDepartment(Department d) {
        if (departmentCount < 5) {
            departments[departmentCount++] = d;
        } else {
            cout << "Cannot add more departments to the hospital. Limit reached!" << endl;
        }
    }

    void removeDepartment(string departmentName) {
        for (int i = 0; i < departmentCount; i++) {
            if (departments[i].name == departmentName) {
                for (int j = i; j < departmentCount - 1; j++) {
                    departments[j] = departments[j + 1];
                }
                departmentCount--;
                cout << "Department " << departmentName << " removed from the hospital." << endl;
                return;
            }
        }
        cout << "Department " << departmentName << " not found in the hospital." << endl;
    }

    void displayInfo() const override {
        cout << "Hospital Name: " << name << ", Location: " << location << endl;
        cout << "Departments: " << endl;
        for (int i = 0; i < departmentCount; i++) {
            departments[i].displayInfo();
        }
    }
};

int main() {
    // Create a hospital
    Hospital hospital("City Hospital", "Main Street");

    // Create departments
    Department cardiology("Cardiology");
    Department neurology("Neurology");

    // Create doctors
    Doctor doc1("Dr. Smith", "Cardiologist", "Cardiology");
    Doctor doc2("Dr. Jones", "Neurologist", "Neurology");

    // Add doctors to departments
    cardiology.addDoctor(doc1);
    neurology.addDoctor(doc2);

    // Add departments to hospital
    hospital.addDepartment(cardiology);
    hospital.addDepartment(neurology);

    // Display information
    hospital.displayInfo();

    // Remove a doctor and department for testing
    cardiology.removeDoctor("Dr. Smith");
    hospital.removeDepartment("Cardiology");

    // Display updated information
    hospital.displayInfo();

    return 0;
}
