#include <iostream>
#include <iomanip>
#include <string>

class Car {
public:
    int id = 0;
    std::string make = "";
    int price = 0;
    int year = 0;
    Car *next = NULL;
    Car () {
        this->id = 0;
        this->make = "";
        this->price = 0;
        this->year = 0;
        this->next = NULL;
    }
    ~Car(){}


};

void displayCar(const Car cars) {
    std::cout << cars.id << '\t' << cars.make << '\t';
    std::cout << cars.price << '\t' << cars.year << std::endl;
}

void addCar(Car *cars) {
    int id = 100;
    while (cars->next != NULL) {
        id += 1;
        cars = cars->next;
    }
    cars->id = id;
    std::cout << "Enter make: ";
    std::cin >> cars->make;
    std::cout << "Enter price: ";
    std::cin >> cars->price;
    std::cout << "Enter year: ";
    std::cin >> cars->year;
}

void removeCar(Car *cars) {
    int remove_id = 0;
    std::cout << "Enter id of car to remove: ";
    std::cin >> remove_id;
    Car *prev_node = cars;
    while (cars->id != remove_id) {
        cars = cars->next;
    }
}

int displayMenu(const Car cars) {
    int option = 0;
    std::cout << "CAR MANAGEMENT\n";
    std::cout << "Car List:\n";
    // display cars
    Car temp = cars;
    while (&temp != NULL && temp.id != 0) {
        displayCar(temp);
        if (temp.next == NULL) break;
        else temp = *(temp.next);
    }
    std::cout << std::setw(11) << std::setfill('-') << " " << std::endl;
    std::cout << "Options:\n";
    std::cout << "1. Add car\n2. Remove car\n5. Exit\nEnter: ";
    std::cin >> option;
    return option;
}

int main(){
    int option = 0;
    Car *cars = new Car;
    while (option != 5) {
        option = displayMenu(*cars);
        switch (option) {
            case 1: // Add car
                if (cars->id != 0) {    // atleast one item in list
                	Car *temp = cars;
                    while (temp->next != NULL) {
                    	temp = temp->next;
                    }
                    temp->next = new Car;
                }
                addCar(cars);
                break;
            case 2: // Remove car
                removeCar(cars);
                break;
            case 5:
               	break;
        }
    }
    Car *next_car = cars;
    while (next_car->next != NULL) {	
        while (next_car->next->next != NULL) {
            next_car = next_car->next;
        }
        delete next_car->next;
        next_car->next = NULL;
        next_car = cars;
    }
    delete cars;
    cars = NULL;
}
