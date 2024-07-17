// Create time: 2024-05-12 16:51:19
// Finish time: 2024-05-12 17:39
#include <iostream>

const int SIZE = 6;

int Fill_array(double array[], int size);
void Show_array(const double array[], int size);
void Reverse_array(double array[], int size);

int main(int argc, char *argv[]) {
    double array[SIZE];
    int actual_size = Fill_array(array, SIZE);
    std::cout << actual_size << std::endl;
    Show_array(array, actual_size);
    std::cout << "-----Reverse_array-----" << std::endl;
    Reverse_array(array, actual_size);
    Show_array(array, actual_size);

    return 0;
}

int Fill_array(double array[], int size) {
    std::cout << "Enter a double array:" << std::endl;
    int i = 0;
    while (std::cin >> array[i] && i < size) {
        std::cout << "Next double or q to exit" << std::endl;
        i++;
    }
    if (i == size) {
        std::cout << "Upon the size of array" << std::endl;
        // std::cout << i << std::endl;
    }
    return i;
}
void Show_array(const double array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "array[" << i << "]= " << array[i] << std::endl;
    }
}
void Reverse_array(double array[], int size) {
    double *temp = new double(size);
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    int i, j;
    for (i = 1, j = size - 2; i < size - 1; i++, j--) {
        array[i] = temp[j];
    }
}
