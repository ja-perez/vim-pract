#include <iostream>
#include <string>

using namespace std;

class Student {
	public:
		string name;
		int id;
		double gpa;
};

int main() {
	cout << "Please input the size of the array: ";
	int asize;
	cin >> asize;
	Student *arr = new Student[asize];
	Student *current
	for (int i = 1; i <= asize; i++) {
		current = arr + (i - 1) * sizeof(Student);
		cout << "Enter student " << i << " name:";
		cin >> current->name;
		cout << "Enter student " << i << " id:";
		cin >> current->id;
		cout << "Enter student " << i << " gpa:";
		cin >> current->gpa;
	}
	cout << '\n';
}
