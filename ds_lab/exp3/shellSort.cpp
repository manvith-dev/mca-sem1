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

void insertionSort(int arr[], int gap, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j >= gap && arr[j] < arr[j - gap]) {
            swap(&arr[j], &arr[j - gap]);
            j -= gap;
        }
    }
    return;
}

void shellSort(int arr[], int size) {
    int interval = size / 2;
    while (interval > 0) {
        insertionSort(arr, interval, size);
        interval /= 2;
    }
    return;
}

void displayArr(const int arr[], int size) {
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

    shellSort(arr, size);

    std::cout << "\nSorted Array :";
    displayArr(arr, size);

    return 0;
}