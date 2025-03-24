#include<iostream>
#include<string>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, float bal, string holder, string type)
        : accountNumber(accNum), balance(bal), accountHolderName(holder), accountType(type) {}

    virtual void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". Remaining Balance: " << balance << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
        }
    }

    virtual float calculateInterest() = 0;

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << " | Holder: " << accountHolderName
             << " | Type: " << accountType << " | Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(int accNum, float bal, string holder, float rate, float minBal)
        : Account(accNum, bal, holder, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    float calculateInterest() override {
        return balance * (interestRate / 100);
    }

    void withdraw(float amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, float bal, string holder)
        : Account(accNum, bal, holder, "Checking") {}

    float calculateInterest() override {
        return 0; // No interest for checking accounts
    }
};

class FixedDepositAccount : public Account {
private:
    float fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNum, float bal, string holder, float rate, int maturity)
        : Account(accNum, bal, holder, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    float calculateInterest() override {
        return balance * (fixedInterestRate / 100);
    }
};

int main() {
    SavingsAccount savings(1001, 5000.0f, "Alice", 2.5f, 1000.0f);
    CheckingAccount checking(1002, 3000.0f, "Bob");
    FixedDepositAccount fixedDeposit(1003, 10000.0f, "Charlie", 5.0f, 2027);

    savings.printStatement();
    checking.printStatement();
    fixedDeposit.printStatement();

    savings.deposit(1000);
    savings.withdraw(4500);
    savings.printStatement();

    checking.withdraw(2000);
    checking.printStatement();

    fixedDeposit.printStatement();
    cout << "Fixed Deposit Interest: " << fixedDeposit.calculateInterest() << endl;

    return 0;
}
