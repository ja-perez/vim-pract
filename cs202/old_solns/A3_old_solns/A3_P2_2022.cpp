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

class MilkCoffeeMachine : public CoffeeMachine {
    private:
        int milk_capacity;
        int curr_milk;
    protected:
        int milk_spoons_per_cup;
    public:
        void addMilk(int);
        void setMilkSpoonsPerCup(int);
        MilkCoffeeMachine(){}
        MilkCoffeeMachine(std::string name, int water_capacity, int coffee_capacity, int milk_capacity) :
        CoffeeMachine(name, water_capacity, coffee_capacity){
            this->milk_capacity = milk_capacity;
            this->milk_spoons_per_cup = 1;
        }
        void makeCups(int);
        void displayCM();
};

int main() {
    /*
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
    
    
    MilkCoffeeMachine cm1("DECAF", 8, 8, 8);
    cm1.addWater(8);
    cm1.addCoffee(8);
    cm1.addMilk(8);
    cm1.makeCups(8);
    */
    MilkCoffeeMachine cm2("BLEND", 15, 30, 26);
    cm2.setMilkSpoonsPerCup(2);
    cm2.displayCM();
    cm2.makeCups(10);
    cm2.displayCM();
    cm2.makeCups(5);
    cm2.displayCM();
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
    new_water += this->curr_water;
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

void MilkCoffeeMachine::setMilkSpoonsPerCup(int new_spoons){
    this->milk_spoons_per_cup = new_spoons;
}
void MilkCoffeeMachine::addMilk(int new_milk){
    new_milk += this->curr_milk;
    if (new_milk >= milk_capacity)
        curr_milk = milk_capacity;
    else
        curr_milk = new_milk;
}
void MilkCoffeeMachine::makeCups(int num_cups){
    if (CoffeeMachine::makeCups(num_cups)){
        for (int i = 0; i < num_cups; i++) {
            if (curr_milk > 0) {
                curr_milk -= this->milk_spoons_per_cup;
                std::cout << "Adding " << this->milk_spoons_per_cup << " spoons of milk per cup\n";
            } else {
                std::cout << i - 1 << " of " << num_cups << " cups have milk added. Insufficient milk for " << num_cups - i << " cups.\n";
            }
        }
    }
}
void MilkCoffeeMachine::displayCM(){
    CoffeeMachine::displayCM();
    std::cout << std::setw(10) << "MILK: " << this->curr_milk << " / " << this->milk_capacity << " (spoons)\n";
    std::cout << std::setw(10) << "MILK PART: " << this->milk_spoons_per_cup << " milk spoons per cup\n";
}