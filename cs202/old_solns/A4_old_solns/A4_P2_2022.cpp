#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
    public:
        string name;
        int id;
        double gpa;
};

void copy_data(Student* to, Student* from) {
    to->name = from->name;
    to->id = from->id;
    to->gpa = from->gpa;
}

int main() {
    int arr_size;
    Student *sArr;
    cout << "Please input the size of the array: ";
    cin >> arr_size;
    sArr = new Student[arr_size];
    Student *current;
    for (int i = 1; i <= arr_size; i++) {
        current = &sArr[i - 1];
        cout << "Enter student " << i << " name: ";
        cin.ignore(1, '\n');
        getline(cin, current->name);
        cout << "Enter student " << i << " id: ";
        cin >> current->id;
        cout << "Enter student " << i << " gpa: ";
        cin >> current->gpa;
    }
    Student *BestGpaOfSemester = new Student;
    Student *LowestGpaOfSemester = new Student;
    for (int i = 0; i < arr_size; i++) {
        current = &sArr[i];
        if (i == 0) {
            copy_data(BestGpaOfSemester, current);
            copy_data(LowestGpaOfSemester, current);
        } else if (BestGpaOfSemester->gpa < current->gpa) {
            copy_data(BestGpaOfSemester, current);
        } else if (LowestGpaOfSemester->gpa > current->gpa) {
            copy_data(LowestGpaOfSemester, current);
        }
    }
    cout << "\nStudent list: (array address: " << sArr << ")\n";
    for (int i = 1; i <= arr_size; i++) {
        current = &sArr[i - 1];
        cout << "Student " << i << ": " << current->name << ", " << current->id 
        << ", " << fixed << setprecision(2) << current->gpa << " (at address " << current << ")\n";
    }

    delete [] sArr;
    cout << "Array deleted.\n";
    cout << "\nStudent with highest GPA:\n";
    cout << BestGpaOfSemester->name << ", " << BestGpaOfSemester->id << ", " << BestGpaOfSemester->gpa << "\t(at address " << BestGpaOfSemester << ")\n";
    cout << "\nStudent with lowest GPA:\n";
    cout << LowestGpaOfSemester->name << ", " << LowestGpaOfSemester->id << ", " << LowestGpaOfSemester->gpa << "\t(at address " << LowestGpaOfSemester << ")\n";
    delete BestGpaOfSemester;
    delete LowestGpaOfSemester;
}