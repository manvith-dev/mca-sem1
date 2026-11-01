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

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivotIdx = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {

        while (arr[i] <= arr[pivotIdx]) {
            i++;
        }
        while (arr[j] > arr[pivotIdx]) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[pivotIdx]);

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);

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

    quickSort(arr, 0, size - 1);

    std::cout << "\nSorted Array :";
    displayArr(arr, size);

    return 0;
}