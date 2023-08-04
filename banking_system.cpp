#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a bank account
class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accountNumber, string accountHolderName, double initialBalance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of " << amount << " successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds. Current balance: " << balance << endl;
        }
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Function to find a bank account based on account number
BankAccount* findAccount(const vector<BankAccount>& accounts, string accountNumber) {
    for (BankAccount& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> accounts;

    // Sample accounts
    accounts.push_back(BankAccount("12345", "John Doe", 1000.0));
    accounts.push_back(BankAccount("67890", "Jane Smith", 500.0));

    int choice;
    string accountNumber;
    double amount;

    cout << "Welcome to our Banking System!" << endl;

    do {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Account Info" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account != nullptr) {
                    account->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account != nullptr) {
                    account->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account != nullptr) {
                    account->displayAccountInfo();
                } else {
                    cout << "Account not found." << endl;
                }
                break;

            case 4:
                cout << "Exiting the Banking System." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
