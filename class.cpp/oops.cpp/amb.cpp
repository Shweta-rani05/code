/*
Author: Shweta Rani
Problem: code for demonstrating the ambiguity aries in multi-level inheritance and how to resolve it using the scope resolution operator.

args: declare memeber data
    - name: string: To hold person name
    - age: int :to hold the person age 
methods:
    - info(): contains information of the class.
    
*/

#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int age;
    Student(string n,int a){
        name=n;
        age = a;
    }

    /*
    name: Student 
    args: name,age
    desc: return name and age of student 
    return: information of the student  
    
    */
    void info(){
        cout<<"student information"<<endl;
        cout<<name<<endl;
        cout<<age<<endl;
    }
};

class Faculty {
public:
    string name;
    int age;
    Faculty(string n,int a){
        name=n;
        age = a;
    }
        /*
    name: Faculty
    args: name,age
    desc: return name and age of facuity
    return: information of the faculty
    
    */
    void info() {
        cout << "Faculty information" << endl;
        cout<<name<<endl;
        cout<<age<<endl;
    }
};
        /*
    name: UniversityMember
    args: name,age
    desc: return name and age of student or faculty using information 
    return: information of the University members
    
    */
class UniversityMember : public Faculty, public Student {
    public:
        UniversityMember(string facultyName, int facultyAge, string studentName, int studentAge)
            : Faculty(facultyName, facultyAge), Student(studentName, studentAge) {}
    
        void info() {
            // Explicitly specify which `info()` method to call
            cout << "Resolving ambiguity in UniversityMember:" << endl;
            Faculty::info();
            Student::info();
        }
    };
    
int main() {
    UniversityMember member("a",1,"b",2);
    // member.info(); //conflict arises due to same type of method
    member.Faculty::info();  // Resolving ambiguity using scope resolution
    member.Student::info();  // Resolving ambiguity using scope resolution

    return 0;
}