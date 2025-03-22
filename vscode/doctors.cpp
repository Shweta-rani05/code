#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    string department;

    Doctor(string n, string s, string d) : name(n), specialization(s), department(d) {}
};

class Department {
public:
    string name;
    vector<Doctor> doctors;

    Department(string n) : name(n) {}

    void addDoctor(Doctor d) {
        doctors.push_back(d);
    }

    void removeDoctor(string name) {
        for (auto it = doctors.begin(); it != doctors.end(); ++it) {
            if (it->name == name) {
                doctors.erase(it);
                break;
            }
        }
    }

    void displayDoctors() {
        cout << "Doctors in department " << name << ":\n";
        for (const auto& doctor : doctors) {
            cout << "Name: " << doctor.name << ", Specialization: " << doctor.specialization << "\n";
        }
    }
};

class Hospital {
public:
    string name;
    string location;
    vector<Department> departments;

    Hospital(string n, string l) : name(n), location(l) {}

    void addDepartment(Department d) {
        departments.push_back(d);
    }

    void removeDepartment(string name) {
        for (auto i = departments.begin(); i != departments.end(); ++i) {
            if (i->name == name) {
                departments.erase(i);
                break;
            }
        }
    }

    void displayDepartments() {
        cout << "Departments in hospital " << name << ":\n";
        for (const auto& department : departments) {
            cout << "Department Name: " << department.name << "\n";
        }
    }
};

int main() {
    Hospital hospital("City Hospital", "Main Street");

    Department cardiology("Cardiology");
    Department neurology("Neurology");

    Doctor doc1("Dr. Smith", "Cardiologist", "Cardiology");
    Doctor doc2("Dr. Jones", "Neurologist", "Neurology");

    cardiology.addDoctor(doc1);
    neurology.addDoctor(doc2);

    hospital.addDepartment(cardiology);
    hospital.addDepartment(neurology);

    hospital.displayDepartments();

    cardiology.displayDoctors();
    neurology.displayDoctors();

    return 0;
}
