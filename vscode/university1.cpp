#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class for Student
class Student {
private:
    string name;
    vector<int> marks;
    int numSubjects;

public:
    Student(string studentName, int subjects) {
        name = studentName;
        numSubjects = subjects;
    }

    void inputMarks() {
        cout << "Enter marks for " << numSubjects << " subjects:\n";
        for (int i = 0; i < numSubjects; i++) {
            int mark;
            cout << "Subject " << i + 1 << ": ";
            cin >> mark;
            marks.push_back(mark);
        }
    }

    double calculateCGPA() {
        int totalMarks = 0;
        for (int i = 0; i < marks.size(); i++) {
            totalMarks += marks[i];
        }
        return (double)totalMarks / numSubjects;
    }

    void displayCGPA() {
        cout << "CGPA for student " << name << ": " << calculateCGPA() << endl;
    }
};

// Class for Teaching Staff
class Teaching {
private:
    string name;
    double baseSalary;
    double bonus;

public:
    Teaching(string staffName, double salary, double bonusAmount) {
        name = staffName;
        baseSalary = salary;
        bonus = bonusAmount;
    }

    double calculateSalary() {
        return baseSalary + bonus;
    }

    void displaySalary() {
        cout << "Salary for Teaching Staff " << name << ": " << calculateSalary() << endl;
    }
};

// Class for Non-Teaching Staff
class NonTeaching {
private:
    string name;
    double baseSalary;
    double allowances;

public:
    NonTeaching(string staffName, double salary, double allowanceAmount) {
        name = staffName;
        baseSalary = salary;
        allowances = allowanceAmount;
    }

    double calculateSalary() {
        return baseSalary + allowances;
    }

    void displaySalary() {
        cout << "Salary for Non-Teaching Staff " << name << ": " << calculateSalary() << endl;
    }
};

// Class for University, which aggregates the other classes
class University {
private:
    vector<Student> students;
    vector<Teaching> teachingStaff;
    vector<NonTeaching> nonTeachingStaff;

public:
    // Function to add a student
    void addStudent(Student s) {
        students.push_back(s);
    }

    // Function to add teaching staff
    void addTeachingStaff(Teaching t) {
        teachingStaff.push_back(t);
    }

    // Function to add non-teaching staff
    void addNonTeachingStaff(NonTeaching nt) {
        nonTeachingStaff.push_back(nt);
    }

    // Display CGPA for all students
    void displayAllStudentsCGPA() {
        for (int i = 0; i < students.size(); i++) {
            students[i].displayCGPA();
        }
    }

    // Display salary for all teaching staff
    void displayAllTeachingSalaries() {
        for (int i = 0; i < teachingStaff.size(); i++) {
            teachingStaff[i].displaySalary();
        }
    }

    // Display salary for all non-teaching staff
    void displayAllNonTeachingSalaries() {
        for (int i = 0; i < nonTeachingStaff.size(); i++) {
            nonTeachingStaff[i].displaySalary();
        }
    }
};

int main() {
    University university;

    // Adding students
    Student student1("John", 5);
    student1.inputMarks();
    university.addStudent(student1);

    Student student2("Alice", 5);
    student2.inputMarks();
    university.addStudent(student2);

    // Adding teaching staff
    Teaching teacher1("Dr. Smith", 50000, 10000);
    university.addTeachingStaff(teacher1);

    Teaching teacher2("Prof. Adams", 60000, 15000);
    university.addTeachingStaff(teacher2);

    // Adding non-teaching staff
    NonTeaching staff1("Mr. Brown", 30000, 5000);
    university.addNonTeachingStaff(staff1);

    NonTeaching staff2("Ms. Green", 35000, 4000);
    university.addNonTeachingStaff(staff2);

    // Displaying CGPA for all students
    university.displayAllStudentsCGPA();

    // Displaying salaries for all teaching staff
    university.displayAllTeachingSalaries();

    // Displaying salaries for all non-teaching staff
    university.displayAllNonTeachingSalaries();

    return 0;
}