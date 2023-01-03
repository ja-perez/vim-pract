#include <iostream> 
#include <string> 
#include <stdlib.h>
#include <iomanip>

#define DEFAULT_CAPACITY 10

class CoffeeMachine {
    public:
        CoffeeMachine(){
            this->curr_water = 0;
            this->curr_coffee = 0;
            this->water_capacity = DEFAULT_CAPACITY;
            this->coffee_capacity = DEFAULT_CAPACITY;
            this->coffee_spoons_per_cup = 1;
            this->name = "UNTITLED";
            std::cout << "Created Coffee Machine " << this->name << " with empty resources.\n";
        }
        CoffeeMachine(std::string name) {
            this->curr_water = 0;
            this->curr_coffee = 0;
            this->water_capacity = DEFAULT_CAPACITY;
            this->coffee_capacity = DEFAULT_CAPACITY;
            this->coffee_spoons_per_cup = 1;
            this->name = name;
            std::cout << "Starting up Coffee Machine " << this->name << " with empty resources.\n";
        }
        CoffeeMachine(std::string name, int water_capacity, int coffee_capacity) {
            this->curr_water = 0;
            this->curr_coffee = 0;
            this->water_capacity = water_capacity;
            this->coffee_capacity = coffee_capacity;
            this->coffee_spoons_per_cup = 1;
            this->name = name;
            std::cout << "Starting up Coffee Machine " << this->name << " with empty resources and capacities:\n";
            std::cout << "water_capacity=" << this->water_capacity << std::endl;
            std::cout << "coffee_capacity=" << this->coffee_capacity << std::endl;      
        }
        ~CoffeeMachine(){
            std::cout << "Shutting down Coffee Machine " << this->name << " with the following resources:\n";
            std::cout << std::setw(8) << "water: " << this->curr_water << std::endl;
            std::cout << std::setw(8) << "coffee: " << this->curr_coffee << std::endl << std::endl;
        }
        std::string name;
        int makeCups(int);
        void addWater(int);
        void addCoffee(int);
        void setCoffeeSpoonsPerCup(int);
        void displayCM();
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
    CoffeeMachine cm1;
    cm1.addWater(8);
    cm1.addCoffee(8);
    cm1.displayCM();
    cm1.makeCups(5);
    cm1.displayCM();

    CoffeeMachine cm2("DECAF");
    cm2.addWater(DEFAULT_CAPACITY);
    cm2.addCoffee(DEFAULT_CAPACITY);
    cm2.displayCM();
    cm2.makeCups(14);

    CoffeeMachine cm3("BLEND", 15, 20);
    cm3.addWater(14);
    cm3.addCoffee(20);
    cm3.displayCM();
    cm3.makeCups(12);
    cm3.displayCM();
    cm3.makeCups(5);

    return  0;
}

int CoffeeMachine::makeCups(int num_cups){
    std::cout << " ordered " << num_cups << " cups of coffee (" << this->name << ") of strength " << this->coffee_spoons_per_cup << std::endl;
    int water_needed = num_cups;
    int coffee_needed = num_cups * this->coffee_spoons_per_cup;
    if (water_needed > curr_water || coffee_needed > curr_coffee){
        std::cout << "NOT ENOUGH RESOURCES!\n\n";
        return 0;
    }
    else {
        for (int i = 0; i < num_cups; i++)
            this->makeSingleCup();
        std::cout << std::endl;
        return 1;
    }
       
}
void CoffeeMachine::addWater(int new_water){
    new_water = this->curr_water + new_water;
    if (new_water >= this->water_capacity)
        this->curr_water = water_capacity;
    else
        this->curr_water = new_water;
}
void CoffeeMachine::addCoffee(int new_coffee){
    new_coffee += this->curr_coffee;
    if (new_coffee >= this->coffee_capacity)
        this->curr_coffee = coffee_capacity;
    else
        this->curr_coffee = new_coffee;
}
void CoffeeMachine::setCoffeeSpoonsPerCup(int new_spoons){
    this->coffee_spoons_per_cup = new_spoons;
}
void CoffeeMachine::displayCM(){
    std::cout << "Current stat of CM: " << this->name << std::endl;
    std::cout << std::setw(8) << " WATER: " << this->curr_water << " / " << this->water_capacity << " (cups)" << std::endl;
    std::cout << std::setw(8) << " COFFEE: " << this->curr_coffee << " / " << this->coffee_capacity << " (spoons)" << std::endl;
    std::cout << " STRENGTH: " << this->coffee_spoons_per_cup << " coffee spoons per cup" << std::endl << std::endl;
}
void CoffeeMachine::makeSingleCup(){
    std::cout << "...made cup of coffee... (" << this->name << ")\n";
    this->curr_water--;
    this->curr_coffee -= this->coffee_spoons_per_cup;
}
