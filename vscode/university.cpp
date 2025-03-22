#include <iostream>
#include <string>
#include <vector>

// Base class for all staff members
class Staff {
protected:
    std::string name;
    int age;
    double baseSalary;

public:
    Staff(const std::string& name, int age, double baseSalary)
        : name(name), age(age), baseSalary(baseSalary) {}

    virtual double calculateSalary() const {
        return baseSalary;
    }

    virtual void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nBase Salary: " << baseSalary << std::endl;
    }
};

// Derived class for teaching staff
class TeachingStaff : public Staff {
private:
    double teachingAllowance;

public:
    TeachingStaff(const std::string& name, int age, double baseSalary, double teachingAllowance)
        : Staff(name, age, baseSalary), teachingAllowance(teachingAllowance) {}

    double calculateSalary() const override {
        return baseSalary + teachingAllowance;
    }

    void display() const override {
        Staff::display();
        std::cout << "Teaching Allowance: " << teachingAllowance << "\nTotal Salary: " << calculateSalary() << std::endl;
    }
};

// Derived class for non-teaching staff
class NonTeachingStaff : public Staff {
private:
    double bonus;

public:
    NonTeachingStaff(const std::string& name, int age, double baseSalary, double bonus)
        : Staff(name, age, baseSalary), bonus(bonus) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void display() const override {
        Staff::display();
        std::cout << "Bonus: " << bonus << "\nTotal Salary: " << calculateSalary() << std::endl;
    }
};

// Class for students
class Student {
private:
    std::string name;
    int age;
    std::vector<double> grades;

public:
    Student(const std::string& name, int age)
        : name(name), age(age) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double calculateCGPA() const {
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return grades.empty() ? 0.0 : sum / grades.size();
    }

    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nCGPA: " << calculateCGPA() << std::endl;
    }
};

int main() {
    // Create instances of teaching and non-teaching staff
    TeachingStaff tStaff("Dr. Smith", 45, 50000, 15000);
    NonTeachingStaff ntStaff("Mr. Brown", 40, 40000, 5000);

    // Create an instance of a student
    Student student("Alice", 20);
    student.addGrade(8.5);
    student.addGrade(9.0);
    student.addGrade(7.5);

    // Display information
    tStaff.display();
    std::cout << std::endl;
    ntStaff.display();
    std::cout << std::endl;
    student.display();

    return 0;
}
