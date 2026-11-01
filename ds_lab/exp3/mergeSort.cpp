#include <iostream>

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
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

    mergeSort(arr, 0, size - 1);

    std::cout << "\nSorted Array :";
    displayArr(arr, size);

    return 0;
}