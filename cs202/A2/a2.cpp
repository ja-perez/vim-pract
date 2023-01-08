#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

const int ARR_SIZE = 5;

class bankAccount {
	private:
		string first;
		string last;
		string initials;
		int acc_num;
		int amount;
	public:
		void displayCustomer();
		void readCustomer();
		int getCustomerAmount();
		bankAccount();
		~bankAccount();
		static double interest_rate;
};
double bankAccount::interest_rate = 3.5;

int getTotalAmount();

int main() {
	srand(time(NULL));
	bankAccount customers[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++) {
		customers[i].readCustomer();
	}
	cout << "\nCUSTOMERS SUMMARY\n";
	for (int i = 0; i < ARR_SIZE; i++) {
		customers[i].displayCustomer();
	}
	int total = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		total += customers[i].getCustomerAmount();
	}
	cout << "SUM OF AMOUNTS: " << total << endl << endl;
}

bankAccount::bankAccount() {
		this->first = "";
		this->last = "";
		this->initials = "";
		// account number randomly generated between 100000 - 300000
		this->acc_num = rand() % 300000 + 100000;
		this->amount = 0;
	    }

bankAccount::~bankAccount() {
		    cout << "closing the account: " << this->acc_num;
		    cout << ", " << this->first << ", " << this->last;
		    cout << ", with the amount " << this->amount << endl;
	    }

void bankAccount::displayCustomer() {
		    cout << "Customer: " << this->first << ' ' << this->last;
		    cout << " (" << this->initials << ")\n";
		    cout << "account: " << this->acc_num << " at " << this->interest_rate;
		    cout << "\% has amount " << this-> amount << endl;
		    cout << "estimated amount year from now: ";
		    double est_amnt = this->amount + this->amount * this->interest_rate / 100.0;
		    cout << fixed << setprecision(1) << est_amnt << endl;
		    cout << setw(33) << setfill('-') << ' ' << endl;
	    }
void bankAccount::readCustomer() {
		    cout << "Reading data for customer\n";
		    cout << "First name: "; cin >> this->first;
		    cout << "Last name: "; cin >> this->last;
		    cout << "Amount: "; cin >> this->amount;
		    this->initials += this->first[0];
		    this->initials += this->last[0];
	    }
int bankAccount::getCustomerAmount() {
		return this->amount;
	    }
