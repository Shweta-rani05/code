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



#include<iostream>
using namespace std;
// ager ek hi naam k do function base or derived class dono m ho to jis class ka pointer hoga us class ka function call hoga.
// lekin ager hmm virtual likh dege function k agee to fer pointer m jis object ka address hoga vo object vale class ka function call hoga.
// pointer compile time per bnta h or object run time.or pointer m konsa object ka address ayega ye run time pe pta chlega.
// to compiler by default compile time binding kar lega or vo pointer vle class ka ke function ko call krega ager ek hi naam k do function do class m ho.
// Ager hmm function k age virtual likh dege to run time binding hogi or function call object k hisab hogi kyuki object run time per bnta h.
class Base{
    public:
    virtual void basefunction(){
        cout<<"Base function called"<<endl;
    }
};

class Derived: public Base{
    public:
    void basefunction(){   // this is function overridding(help in modifying the function).
        cout<<"Modified base function called"<<endl;
    }
    void derivedfunction(){
        cout<<"Derived function called"<<endl;
    }
};

int main(){
    Base *b;
    Derived *d;
    Base obj1;
    Derived obj2;

    b = &obj1; 
    b->basefunction();   // base vala

    d = &obj2;  
    d->basefunction();  // modified base vla
    d->derivedfunction(); 

    b = &obj2; 
    b->basefunction();   // modified base vla kyuki base pointer m derived ka object h isliye derived vla function chlege.ager virtual nhi hota to pointer k type per depend karta.

    // d = &obj1;       this caanot happen becuse derived pointer cannot point to base class 
    return 0;
}