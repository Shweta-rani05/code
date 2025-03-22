#include <iostream>
#include <string>

using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    string department;

    Doctor(string docName, string docSpecialization, string dept) 
        : name(docName), specialization(docSpecialization), department(dept) {}

    void displayDoctor() {
        if (name.empty()) {
            cout << "No doctor details available." << endl;
        } else {
            cout << "Doctor Name: " << name << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "Department: " << department << endl;
        }
    }

    void removeDoctor() {
        name = "";
        specialization = "";
        department = "";
    }
};

class Department {
public:
    string departmentName;
    Doctor* doctors[10];  // Assuming a department can have a maximum of 10 doctors
    int doctorCount;

    Department(string deptName) 
        : departmentName(deptName), doctorCount(0) {}

    void displayDepartment() {
        if (departmentName.empty()) {
            cout << "No department details available." << endl;
        } else {
            cout << "Department Name: " << departmentName << endl;
        }
    }

    void addDoctor(string docName, string docSpecialization) {
        if (doctorCount < 10) {
            doctors[doctorCount] = new Doctor(docName, docSpecialization, departmentName);
            doctorCount++;
        } else {
            cout << "Cannot add more doctors to the department. Maximum limit reached." << endl;
        }
    }

    void removeDoctor(string docName) {
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i]->name == docName) {
                delete doctors[i];
                // Shift doctors in the array to fill the gap
                for (int j = i; j < doctorCount - 1; j++) {
                    doctors[j] = doctors[j + 1];
                }
                doctorCount--;
                return;
            }
        }
        cout << "Doctor not found in the department." << endl;
    }

    void displayDoctors() {
        if (doctorCount == 0) {
            cout << "No doctors available in the department." << endl;
        } else {
            for (int i = 0; i < doctorCount; i++) {
                doctors[i]->displayDoctor();
                cout << "-----------------------" << endl;
            }
        }
    }
};

class Hospital {
public:
    string hospitalName;
    string location;
    Department* departments[10];  // Assuming a hospital can have a maximum of 10 departments
    int departmentCount;

    Hospital(string hospName, string loc) 
        : hospitalName(hospName), location(loc), departmentCount(0) {}

    void displayHospital() {
        if (hospitalName.empty()) {
            cout << "No hospital details available." << endl;
        } else {
            cout << "Hospital Name: " << hospitalName << endl;
            cout << "Location: " << location << endl;
        }
    }

    void addDepartment(string deptName) {
        if (departmentCount < 10) {
            departments[departmentCount] = new Department(deptName);
            departmentCount++;
        } else {
            cout << "Cannot add more departments to the hospital. Maximum limit reached." << endl;
        }
    }

    void removeDepartment(string deptName) {
        for (int i = 0; i < departmentCount; i++) {
            if (departments[i]->departmentName == deptName) {
                delete departments[i];
                // Shift departments in the array to fill the gap
                for (int j = i; j < departmentCount - 1; j++) {
                    departments[j] = departments[j + 1];
                }
                departmentCount--;
                return;
            }
        }
        cout << "Department not found in the hospital." << endl;
    }

    void displayDepartments() {
        if (departmentCount == 0) {
            cout << "No departments available in the hospital." << endl;
        } else {
            for (int i = 0; i < departmentCount; i++) {
                departments[i]->displayDepartment();
                departments[i]->displayDoctors();
            }
        }
    }
};

int main() {
    Hospital hospital("City Hospital", "Main Street");

    hospital.addDepartment("Cardiology");
    hospital.addDepartment("Neurology");

    hospital.departments[0]->addDoctor("Dr. Smith", "Cardiologist");
    hospital.departments[0]->addDoctor("Dr. Jones", "Cardiologist");

    hospital.departments[1]->addDoctor("Dr. Brown", "Neurologist");

    cout << "Displaying Hospital Details:" << endl;
    hospital.displayHospital();
    cout << endl;

    cout << "Displaying Departments in Hospital:" << endl;
    hospital.displayDepartments();

    hospital.departments[0]->removeDoctor("Dr. Smith");

    cout << "Displaying Departments in Hospital after removing a doctor:" << endl;
    hospital.displayDepartments();

    hospital.removeDepartment("Cardiology");

    cout << "Displaying Departments in Hospital after removing a department:" << endl;
    hospital.displayDepartments();

    return 0;
}
