/*
Author - Shweta
Program (11)-A banking system needs to handle different types of accounts: savings accounts and
current accounts. Both account types have a balance and support operations like
deposit and withdrawal. However, savings accounts accrue interest, while current
accounts might have overdraft facilities.
Design an abstract class Account with abstract methods for calculating interest
(which might return 0 for some accounts) and displaying account details. Create
concrete classes SavingsAccount and CurrentAccount that inherit from Account.
Implement the interest calculation for SavingsAccount and add an attribute for
overdraft limit in CurrentAccount.
args- name,accountno
method- SavingAccount:deposit(),withdraw(),calculateInterest(),display();
        currentAccount : deposit(),withdraw(),overdraft(),display();

*/

//mindmap required

#include <iostream>
#include <string>
using namespace std;

// Abstract class Account
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string accNo, double bal) : accountNumber(accNo), balance(bal) {} //constructor

    virtual void calculateInterest() = 0; // Abstract method
    virtual void displayDetails() = 0;   // Abstract method

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }
};

// Concrete class SavingAccount
class SavingAccount : public Account {
    double interestRate; // Interest rate in percentage

public:
    SavingAccount(string accNo, double bal, double rate)
        : Account(accNo, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest accrued: " << interest << "\n";
    }

    void displayDetails() override {
        cout << "Saving Account\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

// Concrete class CurrentAccount
class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(string accNo, double bal, double limit)
        : Account(accNo, bal), overdraftLimit(limit) {}

    void calculateInterest() override {
        // No interest for current accounts
        cout << "No interest for current account.\n";
    }

    void  withdraw(double amount) {
        if (amount > 0 && (balance - amount >= -overdraftLimit)) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Withdrawal exceeds overdraft limit.\n";
        }
    }

    void displayDetails() override {
        cout << "Current Account\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
        cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};

// Main function to demonstrate functionality
int main() {
    SavingAccount savAcc("SA123", 1000.0, 5.0);
    CurrentAccount curAcc("CA456", 500.0, 200.0);

    cout << "Performing operations on Saving Account:\n";
    savAcc.deposit(200.0);
    savAcc.calculateInterest();
    savAcc.withdraw(100.0);
    savAcc.displayDetails();

    cout << "\nPerforming operations on Current Account:\n";
    curAcc.deposit(300.0);
    curAcc.calculateInterest();
    curAcc.withdraw(1000.0);
    curAcc.displayDetails();

    return 0;
}