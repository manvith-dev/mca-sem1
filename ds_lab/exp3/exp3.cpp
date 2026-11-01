#include <iostream>
#include <vector>

void swap(int *num1, int *num2) {
    if (num1 == num2) {
        return;
    }
    *num2 = *num1 + *num2;
    *num1 = *num2 - *num1;
    *num2 = *num2 - *num1;
}

void insertionSort(std::vector<int> &arr, int gap, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j >= gap && arr[j] < arr[j - gap]) {
            swap(&arr[j], &arr[j - gap]);
            j -= gap;
        }
    }
}

void shellSort(std::vector<int> &arr, int size) {
    int interval = size / 2;
    while (interval > 0) {
        insertionSort(arr, interval, size);
        interval /= 2;
    }
}

void bubbleSort(std::vector<int> &arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    int i = left;
    int j = mid + 1;
    std::vector<int> temp;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[left + idx] = temp[idx];
    }
}

void quickSort(std::vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivotIdx = start;
    int i = start + 1;
    int j = end;
    while (i <= j) {
        while (i <= end && arr[i] <= arr[pivotIdx]) {
            i++;
        }
        while (j > start && arr[j] > arr[pivotIdx]) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[pivotIdx]);
    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}

void selectionSort(std::vector<int> &arr, int size) {
    for (int i = 0; i < size; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int getDigitCount(int num) {
    if (num == 0) {
        return 1;
    }
    int res = 0;
    while (num > 0) {
        num /= 10;
        res++;
    }
    return res;
}

std::vector<int> radixSortHelper(std::vector<int> nums) {
    int maxDigit = 0;
    int divisor = 1;
    for (const int num : nums) {
        int count = getDigitCount(num);
        if (count > maxDigit) {
            maxDigit = count;
        }
    }
    std::vector<std::vector<int>> count;
    for (int i = 0; i < 10; i++) {
        count.emplace_back();
    }
    int itr = maxDigit;
    while (itr > 0) {
        for (const int num : nums) {
            count[(num / divisor) % 10].push_back(num);
        }
        int k = 0;
        for (int i = 0; i < 10; i++) {
            for (const int elem : count[i]) {
                nums[k++] = elem;
            }
        }
        for (int i = 0; i < 10; i++) {
            count[i].clear();
        }
        divisor *= 10;
        itr--;
    }
    return nums;
}

void radixSort(std::vector<int> &arr, int size) {
    std::vector<int> positives;
    std::vector<int> negatives;
    for (const int num : arr) {
        if (num >= 0) {
            positives.push_back(num);
        } else {
            negatives.push_back(-1 * num);
        }
    }
    std::vector<int> sortedPositives = radixSortHelper(positives);
    std::vector<int> sortedNegatives = radixSortHelper(negatives);
    int n = negatives.size() - 1;
    int p = 0;
    for (int k = 0; k < size; k++) {
        if (n >= 0) {
            arr[k] = -1 * sortedNegatives[n--];
        } else {
            arr[k] = sortedPositives[p++];
        }
    }
}

void displayArr(const std::vector<int> &arr, int size) {
    if (size <= 0) {
        std::cout << "No element present in array.";
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << " [" << arr[i] << "] ";
    }
    std::cout << "\n";
}

int main() {
    int size;
    std::cout << "Enter size of array :";
    std::cin >> size;
    std::vector<int> arr(size);
    std::cout << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Enter element " << i + 1 << " :";
        std::cin >> arr[i];
    }
    std::cout << "\nUnsorted Array :";
    displayArr(arr, size);
    int choice;
    std::cout << "\nEnter your choice of sorting:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Quick Sort\n";
    std::cout << "3. Selection Sort\n";
    std::cout << "4. Radix Sort\n";
    std::cout << "5. Insertion Sort\n";
    std::cout << "6. Shell Sort\n";
    std::cout << "7. Merge Sort\n";
    std::cout << "8. Exit\n";
    std::cout << "->";
    std::cin >> choice;
    switch (choice) {
    case 1:
        bubbleSort(arr, size);
        break;
    case 2:
        quickSort(arr, 0, size - 1);
        break;
    case 3:
        selectionSort(arr, size);
        break;
    case 4:
        radixSort(arr, size);
        break;
    case 5:
        insertionSort(arr, 1, size);
        break;
    case 6:
        shellSort(arr, size);
        break;
    case 7:
        mergeSort(arr, 0, size - 1);
        break;
    case 8:
        std::cout << "You choose exit!";
        return 0;
    default:
        std::cout << "Please choose a valid choice";
    }
    std::cout << "\nSorted Array :";
    displayArr(arr, size);
    return 0;
}