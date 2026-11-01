#include <iostream>

void swap(int *num1, int *num2) {
    if (num1 == num2) {
        return;
    }
    *num2 = *num1 + *num2;
    *num1 = *num2 - *num1;
    *num2 = *num2 - *num1;
    return;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return;
}

void displayArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << " [" << arr[i] << "] ";
    }
    std::cout << "\n";
}

int main() {
    int size;
    std::cout << "Enter size of array :";
    std::cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        std::cout << "\nEnter element " << i + 1 << " :";
        std::cin >> arr[i];
    }

    std::cout << "\nUnsorted Array :";
    displayArr(arr, size);

    bubbleSort(arr, size);

    std::cout << "\nSorted Array :";
    displayArr(arr, size);

    return 0;
}