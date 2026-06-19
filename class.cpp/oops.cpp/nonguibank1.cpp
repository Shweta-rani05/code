#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// Base class representing a generic bank account.
class BankAccount {
protected:
    int accountNumber;      // Unique account identification.
    string accountHolder;   // Name of the account holder.
    double balance;         // Current balance in the account.
public:
    /// Constructor using an initializer list.
    BankAccount(int accNum, const string& holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    /// Virtual destructor to ensure proper cleanup of derived objects.
    virtual ~BankAccount() {}

    /// Deposits a positive amount into the account.
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    /// Withdraws an amount if it's positive and sufficient funds are available.
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    /// Displays the account details.
    virtual void displayAccount() const {
        cout << "Account Holder: " << accountHolder
             << " | Account Number: " << accountNumber
             << " | Balance: $" << balance;
    }

    /// Getter for the account number.
    int getAccountNumber() const { return accountNumber; }
};

/// Derived class representing a savings account.
/// Adds an interest rate and a function to apply interest.
class SavingsAccount : public BankAccount {
private:
    double interestRate;    // Annual interest rate in percentage.
public:
    /// Constructor initializes both the base account details and the interest rate.
    SavingsAccount(int accNum, const string& holder, double initialBalance, double rate)
        : BankAccount(accNum, holder, initialBalance), interestRate(rate) {}

    /// Applies interest to the current balance.
    void applyInterest() {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        cout << "Interest applied: $" << interest
             << " | New Balance: $" << balance << endl;
    }

    /// Overrides the display function to include the interest rate.
    void displayAccount() const override {
        BankAccount::displayAccount();
        cout << " | Interest Rate: " << interestRate << "%" << endl;
    }
};

/// Derived class representing a checking account.
/// Adds an overdraft limit and overrides the withdraw function to allow overdrawing.
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;  // Maximum overdraft allowed.
public:
    /// Constructor initializes the base account details along with the overdraft limit.
    CheckingAccount(int accNum, const string& holder, double initialBalance, double overdraft)
        : BankAccount(accNum, holder, initialBalance), overdraftLimit(overdraft) {}

    /// Overrides the withdraw function to support overdraft.
    void withdraw(double amount) override {
        if (amount > 0 && amount <= (balance + overdraftLimit)) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or exceeds overdraft limit." << endl;
        }
    }

    /// Overrides the display function to include the overdraft limit.
    void displayAccount() const override {
        BankAccount::displayAccount();
        cout << " | Overdraft Limit: $" << overdraftLimit << endl;
    }
};

/// Class representing the Bank, which manages multiple bank accounts.
class Bank {
private:
    // Stores pointers to BankAccount objects to allow for polymorphism.
    vector<BankAccount*> accounts;
public:
    /// Destructor to free dynamically allocated memory for all accounts.
    ~Bank() {
        for (BankAccount* account : accounts) {
            delete account;
        }
    }

    /// Adds a new bank account to the bank.
    void addAccount(BankAccount* account) {
        accounts.push_back(account);
        cout << "Account added successfully!" << endl;
    }

    /// Searches for an account by its account number.
    /// @return Pointer to the account if found; otherwise, returns nullptr.
    BankAccount* findAccount(int accNum) {
        for (BankAccount* account : accounts)
            if (account->getAccountNumber() == accNum)
                return account;
        return nullptr;
    }

    /// Displays details for all bank accounts.
    void displayAllAccounts() const {
        for (const BankAccount* account : accounts) {
            account->displayAccount();
            cout << endl;
        }
    }
};

/// Function to process user's choices in the bank application.
/// This function displays a menu, gets user input, and performs operations
/// such as creating accounts, depositing, withdrawing, applying interest, and
/// displaying account details.
void processBankOperations(Bank &bank) {
    int choice;  // User's menu choice.

    while (true) {
        // Display the menu options.
        cout << "\nBank Application Menu:\n"
             << "1. Create Savings Account\n"
             << "2. Create Checking Account\n"
             << "3. Deposit\n"
             << "4. Withdraw\n"
             << "5. Apply Interest (Savings Only)\n"
             << "6. Check Account Details\n"
             << "7. Display All Accounts\n"
             << "8. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Create a Savings Account.
            int accNum;
            string holder;
            double initialBalance, interestRate;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            cin.ignore(); // Clear newline from the input buffer.
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            cout << "Enter interest rate (%): ";
            cin >> interestRate;

            // Dynamically create a SavingsAccount and add it to the bank.
            bank.addAccount(new SavingsAccount(accNum, holder, initialBalance, interestRate));

        } else if (choice == 2) {
            // Create a Checking Account.
            int accNum;
            string holder;
            double initialBalance, overdraftLimit;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, holder);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            cout << "Enter overdraft limit: ";
            cin >> overdraftLimit;

            // Dynamically create a CheckingAccount and add it to the bank.
            bank.addAccount(new CheckingAccount(accNum, holder, initialBalance, overdraftLimit));

        } else if (choice == 3) {
            // Deposit money into an account.
            int accNum;
            double depositAmount;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;

            BankAccount* account = bank.findAccount(accNum);
            if (account) {
                account->deposit(depositAmount);
            } else {
                cout << "Account not found!" << endl;
            }

        } else if (choice == 4) {
            // Withdraw money from an account.
            int accNum;
            double withdrawalAmount;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawalAmount;

            BankAccount* account = bank.findAccount(accNum);
            if (account) {
                account->withdraw(withdrawalAmount);
            } else {
                cout << "Account not found!" << endl;
            }

        } else if (choice == 5) {
            // Apply interest to a Savings Account.
            int accNum;
            cout << "Enter account number: ";
            cin >> accNum;

            BankAccount* account = bank.findAccount(accNum);
            if (account) {
                // Use dynamic_cast to check if the account is a SavingsAccount.
                SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(account);
                if (savingsAccount) {
                    savingsAccount->applyInterest();
                } else {
                    cout << "Interest can only be applied to Savings Accounts!" << endl;
                }
            } else {
                cout << "Account not found!" << endl;
            }

        } else if (choice == 6) {
            // Display details for a specific account.
            int accNum;
            cout << "Enter account number: ";
            cin >> accNum;

            BankAccount* account = bank.findAccount(accNum);
            if (account) {
                account->displayAccount();
                cout << endl;
            } else {
                cout << "Account not found!" << endl;
            }

        } else if (choice == 7) {
            // Display all accounts in the bank.
            bank.displayAllAccounts();

        } else if (choice == 8) {
            // Exit the application.
            cout << "Exiting the application. Thank you for using the bank app!" << endl;
            break;
        } else {
            // Handle invalid menu choices.
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

/// Main function: Entry point of the bank application.
int main() {
    Bank bank;  // Instantiate the Bank object.
    processBankOperations(bank);  // Handle user operations.
    return 0;
}