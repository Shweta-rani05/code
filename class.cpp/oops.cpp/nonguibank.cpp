#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << " | Account Number: " << accountNumber 
             << " | Balance: " << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    while (true) {
        cout << "\nBank Application\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNum;
            string holder;
            double initialBalance;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            accounts.push_back(BankAccount(accNum, holder, initialBalance));
            cout << "Account created successfully!" << endl;
        } else if (choice == 2) {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter deposit amount: ";
            cin >> amount;

            for (auto &account : accounts) {
                if (account.accountNumber == accNum) {
                    account.deposit(amount);
                    break;
                }
            }
        } else if (choice == 3) {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            for (auto &account : accounts) {
                if (account.accountNumber == accNum) {
                    account.withdraw(amount);
                    break;
                }
            }
        } else if (choice == 4) {
            int accNum;
            cout << "Enter account number: ";
            cin >> accNum;

            for (const auto &account : accounts) {
                if (account.accountNumber == accNum) {
                    account.displayBalance();
                    break;
                }
            }
        } else if (choice == 5) {
            cout << "Exiting the program. Thank you for using the bank application!" << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}