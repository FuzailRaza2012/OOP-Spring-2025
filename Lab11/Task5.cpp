#include <iostream>
#include <string>
using namespace std;

class LowBalanceError : public exception {
private:
    double shortfall;
    string errorMsg;
public:
    LowBalanceError(double shortage) : shortfall(shortage) {
        errorMsg = "LowBalanceError - Short by: $" + to_string(shortfall);
    }
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

template <typename T>
class Account {
private:
    T currentBalance;
public:
    Account(T initialAmount = 1000) : currentBalance(initialAmount) {
        cout << "Current Balance: $" << currentBalance << endl;
    }

    void takeOutMoney(T cash) {
        if (cash > currentBalance) {
            throw LowBalanceError(cash - currentBalance);
        } else {
            currentBalance -= cash;
            cout << "$" << cash << " successfully withdrawn." << endl;
        }
    }
};

int main() {
    Account<double> userAccount(509.90);

    try {
        cout << "Trying to withdraw: $800" << endl;
        userAccount.takeOutMoney(800);
    } catch (LowBalanceError& err) {
        cout << err.what() << endl;
    }

    return 0;
}
