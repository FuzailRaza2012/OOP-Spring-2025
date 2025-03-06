#include <iostream>
#include <string>

using namespace std;

class Account{
	public:
		int accountNumber;
		float balance;
		
		Account(int an, float b) : accountNumber(an), balance(b) {}
		
		virtual void displayDetails(){
			cout << "Account Number: " << accountNumber << endl << "Balance: " << balance << endl;
		}
};

class SavingsAccount: virtual public Account{
	public:
		float interestRate;
		
		SavingsAccount(int an, float b, float ir) : Account(an, b), interestRate(ir){}
		
		void displayDetails() override{
			Account::displayDetails();
			cout << "Interest Rate: " << interestRate << endl;
		}
};

class CheckingAccount: virtual public Account{
	public:
		float overdraftLimit;
		
		CheckingAccount(int an, float b, float ol) : Account(an, b), overdraftLimit(ol){}
		
		void displayDetails() override{
			Account::displayDetails();
			cout << "Overdraft Limit: " << overdraftLimit << endl;
		}
};

int main(){
	SavingsAccount saving(1, 4000, 0.2);
	CheckingAccount checking(2, 100, 200);
	
	cout << "For Savings Account..." << endl;
	saving.displayDetails();
	
	cout << "For Checking Account..." << endl;
	checking.displayDetails();
}
