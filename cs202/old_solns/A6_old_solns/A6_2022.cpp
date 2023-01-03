#include <iostream> 
#include <random>
#include <iomanip>
#include <ctime>

using namespace std; 
 
const int ARR_SIZE=10;
const int ID_MIN=10000;
const int ID_MAX=99999;
 
class Student { 
public:
    int id = 0;
    double gpa = 0;
};
 
void display(const Student obj[]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        cout << obj[i].id << ':' << setprecision(3) << obj[i].gpa << ' '; 
    }
    cout << endl;
}

void sortBubble(Student obj[]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            if (obj[i].gpa < obj[j].gpa) {
                int temp_id = obj[i].id;
                double temp_gpa = obj[i].gpa;
                obj[i].gpa = obj[j].gpa;
                obj[j].gpa = temp_gpa;
                obj[i].id = obj[j].id;
                obj[j].id = temp_id;
            }
        }
    }
}

int cmpr_dbl_gpa(const void* obj1, const void* obj2) {
    if (((Student*)obj1)->gpa < ((Student*)obj2)->gpa) return -1;
    else if (((Student*)obj1)->gpa == ((Student*)obj2)->gpa) return 0;
    else return 1;
}

int main() {
    // create an array of 1M elements 
    Student s1[ARR_SIZE];

    // fill with random values: id=(ID_MIN-ID_MAX);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> unif(0.0, 4.0);
    default_random_engine re;
    for (int i = 0; i < ARR_SIZE; i++) {
        s1[i].id = ID_MIN + (rand() % (ID_MAX - ID_MIN));

        s1[i].gpa = unif(re);
    }
    
    // display unsorted (only for small set phase) 
    display(s1);
    // ask user whether to sort by bubbleSort or quicksort 
    cout << "options\n1=bubble sort\n2=qsort\n3=quit\nyour option= ";
    int option = 0;
    cin >> option;
    // start measuring time
    time_t start_time;
    time(&start_time);
    // sort by selected algorithm 
    if (option == 1) {
        sortBubble(s1);
    } else if (option == 2) {
        qsort(s1, ARR_SIZE, sizeof(Student), cmpr_dbl_gpa);
    } else {
        return 0;
    }
    // stop measuring time 
    time_t end_time;
    time(&end_time);
    // display sorted (only for small set phase) 
    display(s1);
    // display measured time 
    time_t measured_time = difftime(end_time, start_time);
    cout << "elapsed time: " << measured_time << endl;
}
 
 