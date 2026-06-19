//program to understand inheritance and containership 
//inheritance - "is-a" containership -"has-a"
/*
program (10):Create a program where the base class 'Person' contains general information like
name and age. A derived class 'Employee' includes employee-specific attributes like
employee ID and department. A further derived class 'Manager' includes additional
details like the team size and budget. Write a program to display complete
information for the Manager.
args: name,age,employeeId,department ,teamsize,budget
method: display()
*/

#include<iostream>
using namespace std;

class person{ //base class
    public:
    string name;
    int age;
    person(string n,int a){
        name=n;
        age = a;
    }
};

class employee : public person{ //derived class 
    public:
    int eid;
    string department;
    employee(string n,int a,int e_id,string dept) : person( n , a){
        eid=e_id;
        department = dept;
    }
};

class Manager : public employee{
    public :
    int budget;
    int team_size;
    Manager(string n, int a, int e_id, string dept, int bgt, int t_size) : employee(n, a, e_id, dept){
        budget = bgt;
        team_size =t_size;
    }
    void display() {
        cout << "Information of the system:" << endl;
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Employee ID: " << eid << ", Department: " << department << endl;
        cout << "Budget: " << budget << ", Team Size: " << team_size << endl;
    }
};

int main() {
    Manager mgr("A", 41, 101, "HR", 50000, 10);
    mgr.display();
    return 0;
}