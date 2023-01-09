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

int main() {
	coffeeMachine cm1;
	cm1.addWater(8);
	cm1.addCoffee(8);
	cm1.displayCM();
	cm1.makeCups(5);
	cm1.displayCM();

	coffeeMachine cm2("DECAF");
	cm2.addWater(DEFAULT_CAPACITY);	
	cm2.addCoffee(DEFAULT_CAPACITY);	
	cm2.displayCM();
	cm2.makeCups(14);

	coffeeMachine cm3("BLEND", 15, 20);
	cm3.addWater(14);
	cm3.addCoffee(20);
	cm3.displayCM();
	cm3.makeCups(12);
	cm3.displayCM();
	cm3.makeCups(5);
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
	cout << " STRENGTH: " << this->coffee_spoons_per_cup << " coffee spoons per cup\n\n";
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
	cout << "\tcoffee_capacity=" << this->coffee_capacity << endl << endl;
}
coffeeMachine::~coffeeMachine() {
	cout << "shutting down Coffee Machine " << this->name << " with the following ";
	cout << "resources left:\n";
	cout << " water: " << this->curr_water << endl;
	cout << " coffee: " << this->curr_coffee << endl << endl;
}
