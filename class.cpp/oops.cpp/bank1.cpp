#include <iostream>
#include <vector>
using namespace std;

// Base class
class Bank {
protected:
    string name;
    string location;

public:
    Bank(string n, string loc) : name(n), location(loc) {}

    void displayBankInfo() {
        cout << "Bank Name: " << name << ", Location: " << location << endl;
    }
};

// Inherits from Bank
class AccountHolder : public Bank {
protected:
    string holderName;
    string address;
    string phone;

public:
    AccountHolder(string bname, string loc, string hname, string addr, string ph)
        : Bank(bname, loc), holderName(hname), address(addr), phone(ph) {}

    void displayHolderInfo() {
        cout << "Account Holder: " << holderName << ", Address: " << address 
             << ", Phone: " << phone << endl;
    }
};

// Inherits from AccountHolder
class Account : public AccountHolder {
    protected:
        int accountNumber;
        double balance;
    
    public:
        Account(string bname, string loc, string hname, string addr, string ph,
                int accNum, double bal)
            : AccountHolder(bname, loc, hname, addr, ph), accountNumber(accNum), balance(bal) {}
    
        void deposit(double amount) {
            balance += amount;
        }
    
        void withdraw(double amount) {
            if (amount <= balance)
                balance -= amount;
            else
                cout << "Insufficient balance!" << endl;
        }
    
        void displayAccountDetails() {
            displayBankInfo();
            displayHolderInfo();
            cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
        }
    };
    
// Inherits from Account
class Transaction : public Account {
    private:
        int transactionID;
        string type;
        string date;
        double amount;
    
    public:
        Transaction(string bname, string loc, string hname, string addr, string ph,
                    int accNum, double bal, int tid, string ttype, string tdate, double amt)
            : Account(bname, loc, hname, addr, ph, accNum, bal), 
              transactionID(tid), type(ttype), date(tdate), amount(amt) {}
    
        void displayTransaction() {
            cout << "Transaction ID: " << transactionID << ", Type: " << type 
                 << ", Date: " << date << ", Amount: " << amount << endl;
        }
    };
    
    int main() {
        Transaction t("State Bank", "Delhi", "Alice", "Sector 10", "9999999999", 
                      12345, 5000.0, 1001, "Deposit", "2025-04-07", 2000.0);
        
        t.displayAccountDetails();
        t.displayTransaction();
    
        return 0;
       }