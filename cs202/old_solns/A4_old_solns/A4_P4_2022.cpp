#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

class DArr {
    public:
    double *arr;
    int size;
    void displayElements();
    double* getMax();
    DArr() {
        cout << "Enter the array size: ";
        cin >> this->size;
        this->arr = new double [this->size];
        cout << "Constructor: allocating " << this->size * sizeof(this->arr) << " bytes of memory\n";
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dis(0.0, 1000.0);
        for (int i = 0; i < this->size; i++) {  
        	this->arr[i] = dis(gen);
        }
    }
    ~DArr() {
        cout << "Destructor freeing " << this->size * sizeof(this->arr) << " bytes of memory\n";
        delete [] this->arr;
    }
};

int main() {
    DArr arr;
    arr.displayElements();
    cout << setprecision(2) << fixed << "max element: " << *(arr.getMax()) << " at the address " << arr.getMax() << endl;
}

void DArr::displayElements() {
    cout << "array elements:\n";
    for (int i = 0; i < this->size - 1; i++)
        cout << setprecision(2) << fixed << *(arr + i) << ',';
    cout << *(arr + this->size - 1) << endl;
}
double *DArr::getMax() {
    double *curr_max = arr;
    for (int i = 1; i < this->size; i++) {
        if (*curr_max < *(arr + i))
            curr_max = arr + i;
    }
    return curr_max;
}
