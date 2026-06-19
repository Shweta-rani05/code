#include <iostream>
#include <string>
using namespace std;
// example for containership "hsa-a" relationship
// Doctor class (independent class)
class Doctor {
    string name;
    string specialization;
    string department;

public:
    Doctor(string n = "", string s = "", string d = "") : name(n), specialization(s), department(d) {}

    void displayInfo() const {
        cout << "Doctor Name: " << name << ", Specialization: " << specialization
             << ", Department: " << department << endl;
    }

    string getName() const { return name; } // Helper function for operations
};

// Department class contains Doctor
class Department {
    string name;
    Doctor doctors[10]; // Array to store doctors (max 10)
    int doctorCount;

public:
    Department(string n = "") : name(n), doctorCount(0) {}

    void addDoctor(const Doctor& d) {
        if (doctorCount < 10) {
            doctors[doctorCount++] = d;
        } else {
            cout << "Cannot add more doctors to the department. Limit reached!" << endl;
        }
    }

    void removeDoctor(string doctorName) {
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i].getName() == doctorName) { // Search for doctor by name
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

    void displayInfo() const {
        cout << "Department: " << name << endl;
        for (int i = 0; i < doctorCount; i++) {
            doctors[i].displayInfo();
        }
    }

    string getName() const { return name; } // Helper function for operations
};

// Hospital class contains Department
class Hospital {
    string name;
    string location;
    Department departments[5]; // Array to store departments (max 5)
    int departmentCount;

public:
    Hospital(string n = "", string l = "") : name(n), location(l), departmentCount(0) {}

    void addDepartment(const Department& d) {
        if (departmentCount < 5) {
            departments[departmentCount++] = d;
        } else {
            cout << "Cannot add more departments to the hospital. Limit reached!" << endl;
        }
    }

    void removeDepartment(string departmentName) {
        for (int i = 0; i < departmentCount; i++) {
            if (departments[i].getName() == departmentName) { // Search for department by name
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

    void displayInfo() const {
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