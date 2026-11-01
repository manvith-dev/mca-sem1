#include <iostream>
#include <vector>

void displayVector(const std::vector<int> &nums) {
    for (const int num : nums) {
        std::cout << " [" << num << "] ";
    }
    std::cout << "\n";
}

void swap(int *num1, int *num2) {
    if (num1 == num2) {
        return;
    }
    *num2 = *num1 + *num2;
    *num1 = *num2 - *num1;
    *num2 = *num2 - *num1;
    return;
}

int getDigitCount(int num) {
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
        int count = 0;
        if (num != 0) {
            count = getDigitCount(num);
            if (count > maxDigit) {
                maxDigit = count;
            }
        }
    }

    std::vector<std::vector<int>> count;

    for (int i = 0; i < 10; i++) {
        count.emplace_back();
    }

    int itr = maxDigit;
    while (itr > 0) {
        int digit = 0;
        for (const int num : nums) {
            digit = (num / divisor) % 10;
            count[digit].push_back(num);
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

void radixSort(int arr[], int size) {

    std::vector<int> positives;
    std::vector<int> negatives;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) {
            positives.push_back(arr[i]);
        } else {
            negatives.push_back(-1 * arr[i]);
        }
    }
    std::cout << "Unsorted positives";
    displayVector(positives);

    std::cout << "Unsorted negatives";
    displayVector(negatives);

    std::vector<int> sortedPositives = radixSortHelper(positives);
    std::vector<int> sortedNegatives = radixSortHelper(negatives);

    std::cout << "Sorted positives";
    displayVector(sortedPositives);

    std::cout << "Sorted negatives";
    displayVector(sortedNegatives);

    int n = negatives.size() - 1;
    int p = 0;
    for (int k = 0; k < size; k++) {
        if (n >= 0) {
            arr[k] = -1 * sortedNegatives[n--];
        } else {
            arr[k] = sortedPositives[p++];
        }
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

    radixSort(arr, size);

    std::cout << "\nSorted Array :";
    displayArr(arr, size);

    return 0;
}