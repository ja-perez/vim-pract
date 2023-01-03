#include <iostream> 

int main(){
    int asize = 0;
    int *p_min, *p_max;
    std::cout << "How many numbers into array: ";
    std::cin >> asize;
    int *arr = NULL;
    arr = new int[asize];
    for (int i = 0; i < asize; i++) {
        std::cout << "iteration number: " << i << std::endl;
        std::cout << "Please enter element number " << i << ": ";
        std::cin >> arr[i];
        
        if (i == 0) {
            p_min = &arr[i];
            p_max = &arr[i];
        }
        else if (arr[i] > *p_max) {
            p_max = &arr[i];
            std::cout << "Updating p_max to address " << p_max << ", now pointing to value: " << *p_max << std::endl;
        }
        else if (arr[i] < *p_min) {
            p_min = &arr[i];
            std::cout << "Updating p_max to address " << p_min << ", now pointing to value: " << *p_min << std::endl;
        }
        std::cout << "Read number: " << arr[i] << std::endl;
        std::cout << "Current array elements: ";
        for (int j = 0; j < i; j++)
            std::cout << arr[j] << ',';
        std::cout << arr[i] << std::endl;
        std::cout << "Current minimum = " << *p_min << " at address " << p_min << std::endl;
        std::cout << "Current maximum = " << *p_max << " at address " << p_max << std::endl;
    }
    delete [] arr;
}