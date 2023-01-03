#include <iostream> 
#include <string> 
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

const int ARR_SIZE = 5;

class bankAccount {
    private:
        string first;
        string last;
        string initials;
        int accountNum;
        int amount;
    public:
        bankAccount(){
            this->accountNum = rand() % 2000000 + 1000000;
        }
        ~bankAccount(){
        cout << "closing the account: " << this->accountNum << ", " << this->first
        << ", " << this->last << ", with the amount " << this->amount << endl;
        }
        void displayCustomer();
        void readCustomer();
        int getCustomerAmount();
        static double interestRate;
};

double bankAccount::interestRate = 3.5;
int getTotalAmount(bankAccount accounts[]);

int main() {
    bankAccount accounts[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        srand(time(NULL));
        accounts[i].readCustomer();
    }
    cout << "\nCUSTOMERS SUMMARY\n";
    for (int i = 0; i < ARR_SIZE; i++)
        accounts[i].displayCustomer();
    cout << "SUM OF AMOUNTS: ";
    cout << getTotalAmount(accounts) << endl << endl;
    return 0;
}

int getTotalAmount(bankAccount accounts[]) {
    int total = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        total += accounts[i].getCustomerAmount();
    }
    return total;
}

void bankAccount::readCustomer() {
    cout << "Reading data for customer\n";
    cout << "First name: ";
    cin >> this->first;
    cout << "Last name: ";
    cin >> this->last;
    cout << "Amount: ";
    cin >> this->amount;
    string f_initial(1, this->first[0]);
    this->initials = f_initial + this->last[0];
}

void bankAccount::displayCustomer() {
    cout << left << setw(10) << "Customer: " << this->first << " " << this->last
        << " (" << this->initials  << ")\n";
    double est_amount = this->amount * (interestRate / 100.0) + this->amount;
    cout << setw(10) << "account: " << this->accountNum << " at " 
        << interestRate << "% has amount " << this->amount << endl;
    cout << "estimated amount year from now: "<< setprecision(1) << fixed << est_amount << endl;
    cout << setw(33) << setfill('-') << " " << setfill(' ') << endl;
}

int bankAccount::getCustomerAmount() {
    return this->amount;
}