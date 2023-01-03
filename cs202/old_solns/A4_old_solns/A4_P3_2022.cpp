#include <iostream>

using namespace std;

int main() {
    int asize;
    cout << "enter array size: ";
    cin >> asize;
    int *DArr = new int [asize];
    for (int i = 0; i < asize; i++)
        DArr[i] = i * (i + 1);
    for (int i = 0; i < asize; i++)
        cout << DArr[i] << ',';
    int *current = &DArr[0];
    cout << endl;
    while (true) {
        int pos;
        cout << "enter relative pos: ";
        cin >> pos;
        if (pos == -1111)
            return 0;
        else if (current + pos >= &DArr[asize] || current + pos < &DArr[0]) {
            current = &DArr[0];
            cout << "Position set to 0.\n";
        } else {
            current += pos;
            cout << "DArr=" << DArr << " current=" << current << " last=" << current - pos << endl;
            cout << "current value=" << *current << ", current position=" << current - DArr << "/" << asize - 1 << endl;
        }
    }

    delete [] DArr;
}