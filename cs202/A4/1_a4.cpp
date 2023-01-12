#include <iostream>

using namespace std;

void display_val(double* p) {
	cout << *p << " at address " << p << endl;
}

void update_max(double* max) {
	cout << "Updating p_max to address " << max;
	cout << ", now pointing to value: " << *max << endl;
}

void update_min(double* min) {
	cout << "Updating p_min to address " << min;
	cout << ", now pointing to value: " << *min<< endl;
}

int main() {
	cout << "How many numbers to store: ";
	int asize;
	cin >> asize;
	double *p_min, *p_max;
	double *arr = new double[asize];
	for (int i = 0; i < asize; i++) {
		cout << "Iteration number: " << i << endl;
		cout << "Please enter element number " << i << ": ";
		double num;
		cin >> num;
		arr[i] = num;
		if (i == 0) {
			p_min = arr;
			p_max = arr;
			update_max(p_max);
			update_min(p_min);
		} else if (*p_min > arr[i]) {
			p_min = &arr[i];
			update_min(p_min);
		} else if (*p_max < arr[i]) {
			p_max = &arr[i];
			update_max(p_max);
		}

		cout << "Read number: " << arr[i] << endl;
		cout << "Current array elements: ";
		for (int j = 0; j <= i; j++) {
			if (j != i) {
				cout << arr[j] << ',';
			} else {
				cout << arr[j] << endl;
			}
		}
		cout << "Current minimum = " << *p_min << " at address " << p_min << endl;
		cout << "Current maximum = " << *p_max << " at address " << p_max << endl;
		cout << endl;
	}
	delete [] arr;
}
