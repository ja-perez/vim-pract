#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DEFAULT_CAPACITY = 10;

class coffeeMachine {
	public:
		string name;
		int makeCups(int cups);
		void addWater(int cups);
		void addCoffee(int cups);
		void setCoffeeSpoonsPerCup(int val);
		void displayCM();
		coffeeMachine();
		coffeeMachine(string new_name);
		coffeeMachine(string new_name, int w_cap, int c_cap);
		~coffeeMachine();
	private:
		void makeSingleCup();
		int water_capacity;
		int coffee_capacity;
		int curr_water;
		int curr_coffee;
	protected:
		int coffee_spoons_per_cup;
};

class milkcoffeeMachine : public coffeeMachine {
	private:
		int milk_capacity;
		int curr_milk;
	protected:
		int milk_spoons_per_cup;
	public:
		void addMilk(int);
		void setMilkSpoonsPerCup(int);
		milkcoffeeMachine(string name, int w_cap, int c_cap, int m_cap);
		int makeCups(int);
		void displayCM();
};

int main() {
	milkcoffeeMachine cm1("DECAF", 8, 8, 8);
	cm1.addWater(8);
	cm1.addCoffee(8);
	cm1.addMilk(8);
	cm1.displayCM();
	cm1.makeCups(8);
	cm1.displayCM();

	milkcoffeeMachine cm2("BLEND", 15, 30, 26);
	cm2.setMilkSpoonsPerCup(2);
	cm2.displayCM();
	cm2.makeCups(10);
	cm2.displayCM();
	cm2.makeCups(5);
	cm2.displayCM();
}

int coffeeMachine::makeCups(int cups) {
	cout << " ordered " << cups << " cups of coffee of strength ";
	cout << this->coffee_spoons_per_cup << endl;
	if (cups <= this->curr_water && cups*this->coffee_spoons_per_cup <= this->curr_coffee) {
		for (int i = 0; i < cups; i++) {
			this->makeSingleCup();
		}
		cout << endl;
		return 1;
	} else {
		cout << "NOT ENOUGH RESOURCES!\n\n";
		return 0;
	}
}
void coffeeMachine::addWater(int cups) {
	int w_total = cups + this->curr_water;
	this->curr_water = w_total >= this->water_capacity ? this->water_capacity : w_total;
}
void coffeeMachine::addCoffee(int cups) {
	int c_total = cups + this->curr_coffee;
	this->curr_coffee= c_total >= this->coffee_capacity ? this->coffee_capacity : c_total;
}
void coffeeMachine::setCoffeeSpoonsPerCup(int val) {
	this->coffee_spoons_per_cup = val;
}
void coffeeMachine::displayCM() {
	cout << "Current state of CM: " << this->name << endl;
	cout << " WATER:\t" << this->curr_water << " / " << this->water_capacity << " (cups)\n";
	cout << " COFFEE:\t" << this->curr_coffee << " / ";
        cout << this->coffee_capacity << " (spoons)\n";
	cout << " STRENGTH: " << this->coffee_spoons_per_cup << " coffee spoons per cup\n";
}
void coffeeMachine::makeSingleCup() {
	this->curr_water--;
	this->curr_coffee--;
	cout << "...made cup of coffee " << this->name << "...\n";
}
coffeeMachine::coffeeMachine() {
	this->curr_water = 0;
	this->curr_coffee= 0;
	this->water_capacity = DEFAULT_CAPACITY;
	this->coffee_capacity = DEFAULT_CAPACITY;
	this->coffee_spoons_per_cup = 1;
	this->name = "UNTITILED";
	cout << "created coffee machine " << this->name << " with empty resources\n";
}
coffeeMachine::coffeeMachine(string new_name) {
	this->curr_water = 0;
	this->curr_coffee= 0;
	this->water_capacity = DEFAULT_CAPACITY;
	this->coffee_capacity = DEFAULT_CAPACITY;
	this->coffee_spoons_per_cup = 1;
	this->name = new_name; 
	cout << "created coffee machine " << this->name << " with empty resources\n";
}
coffeeMachine::coffeeMachine(string new_name, int w_cap, int c_cap) {
	this->curr_water = 0;
	this->curr_coffee= 0;
	this->water_capacity = w_cap;
	this->coffee_capacity = c_cap;
	this->coffee_spoons_per_cup = 1;
	this->name = new_name; 
	cout << "Starting up Coffee Machine " << this->name << " with empty resources ";
	cout << "and capacities:\n";
	cout << "\twater_capacity=" << this->water_capacity << endl;
	cout << "\tcoffee_capacity=" << this->coffee_capacity << endl;
}
coffeeMachine::~coffeeMachine() {
	cout << "shutting down Coffee Machine " << this->name << " with the following ";
	cout << "resources left:\n";
	cout << " water: " << this->curr_water << endl;
	cout << " coffee: " << this->curr_coffee << endl << endl;
}
void milkcoffeeMachine::addMilk(int val) {
	int new_milk = this->curr_milk + val;
	this->curr_milk = new_milk >= this->milk_capacity ? this->milk_capacity : new_milk;
}
void milkcoffeeMachine::setMilkSpoonsPerCup(int val) {
	this->milk_spoons_per_cup = val;
}
int milkcoffeeMachine::makeCups(int cups) {
	int plain_cups = coffeeMachine::makeCups(cups);
	if (plain_cups == 1) {
		int cups_left = cups;
		while (cups_left != 0) {
			if (this->curr_milk == 0) {
				int cups_filled = cups - cups_left;
				cout << cups_filled << " of " << cups << " cups of milk added.";
				cout << " Insufficient milk for " << cups_left <<  " cups.\n\n";
				return 0;	
			}	
			this->curr_milk -= this->milk_spoons_per_cup;
			cups_left--;
			cout << "Adding " << this->milk_spoons_per_cup;
			cout << " spoons of milk per cup\n";
		}	
		cout << ' ' <<  endl;
	}
	return 1;
}
void milkcoffeeMachine::displayCM() {
	coffeeMachine::displayCM();
	cout << " MILK:\t" << this->curr_milk << " / " << this->milk_capacity << " (spoons)\n";
	cout << " MILK PART:\t" << this->milk_spoons_per_cup << " milk spoons per cup\n\n";
}
milkcoffeeMachine::milkcoffeeMachine(string name, int w_cap, int c_cap, int m_cap)
	: coffeeMachine(name, w_cap, c_cap) {
		this->milk_capacity = m_cap;
		this->milk_spoons_per_cup = 1;
		cout << "\tmilk_capacity=" << this->milk_capacity << endl << endl;
	}
