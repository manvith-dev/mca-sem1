#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

struct Score {
    std::string name;
    int marks;
};

std::vector<Score> data(1000);

void head(std::vector<Score> &arr, int n) {
    std::cout << std::left << std::setw(15) << "Name" << std::setw(15)
              << "Marks" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << std::left << std::setw(15) << arr[i].name << std::setw(15)
                  << arr[i].marks << std::endl;
    }
}

template <typename SortFunction>
double measureTime(const std::vector<Score> &original,
                   SortFunction sortFunction) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 500; i++) {
        std::vector<Score> arr = original;
        sortFunction(arr);
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::micro>(end - start).count() /
           500.0;
}

void quickSort(std::vector<Score> &arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivotIdx = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {

        while (i <= end && arr[i].marks <= arr[pivotIdx].marks) {
            i++;
        }

        while (j > start && arr[j].marks > arr[pivotIdx].marks) {
            j--;
        }

        if (i < j) {
            Score temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    Score temp = arr[pivotIdx];
    arr[pivotIdx] = arr[j];
    arr[j] = temp;

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);

    return;
}

void mergeSort(std::vector<Score> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = 0;

    std::vector<Score> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i].marks < arr[j].marks) {
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

    for (int idx = 0; idx < k; idx++) {
        arr[left + idx] = temp[idx];
    }

    return;
}

void initializeMarks() {

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> marks(0, 100), len(3, 4), ch('a', 'z');

    for (auto &s : data) {
        s.name = "";
        for (int i = 0; i < len(gen); i++) s.name += ch(gen);
        s.marks = marks(gen);
    }
}

void rankStudents() {
    std::vector<Score> sortedScores = data;
    quickSort(sortedScores, 0, data.size() - 1);
    std::cout << std::left << std::setw(15) << "Rank" << std::setw(15) << "Name"
              << std::setw(15) << "Marks" << std::endl;
    std::cout << "------------------------------" << std::endl;

    int i = sortedScores.size() - 1;
    int count = 10;
    while (count-- > 0) {
        std::cout << std::left << std::setw(15) << 10 - count << std::setw(15)
                  << sortedScores[i].name << std::setw(15)
                  << sortedScores[i].marks << std::endl;
        i--;
    }
}

void comparison() {
    std::vector<Score> random = data;
    std::vector<Score> sorted = data;
    std::vector<Score> reverse = data;

    // Prepare sorted and reverse-sorted data
    sort(sorted.begin(), sorted.end(),
         [](Score a, Score b) { return a.marks < b.marks; });

    reverse = sorted;
    std::reverse(reverse.begin(), reverse.end());

    std::cout << std::left << std::setw(20) << "Data" << std::setw(15)
              << "Quick Sort" << std::setw(15) << "Merge Sort" << '\n';

    std::cout << std::string(50, '-') << '\n';

    auto show = [&](std::string type, std::vector<Score> &arr) {
        std::vector<Score> q = arr;
        std::vector<Score> m = arr;

        double quickTime = measureTime(
            arr, [](std::vector<Score> &v) { quickSort(v, 0, v.size() - 1); });

        double mergeTime = measureTime(
            arr, [](std::vector<Score> &v) { mergeSort(v, 0, v.size() - 1); });

        std::cout << std::left << std::setw(20) << type << std::setw(15)
                  << quickTime << std::setw(15) << mergeTime << '\n';
    };

    show("Random", random);
    show("Sorted", sorted);
    show("Reverse Sorted", reverse);
}

int main() {
    initializeMarks();

    int choice;
    do {
        std::cout << std::endl;
        std::cout << "===== ONLINE EXAMINATION RESULT PROCESSING ====="
                  << std::endl
                  << std::endl;
        std::cout << "Enter your choice" << std::endl;
        std::cout << "1. To display first 5 student records" << std::endl;
        std::cout << "2. Rank students based on marks" << std::endl;
        std::cout << "3. To view comparison table (Merge sort and Quick sort)"
                  << std::endl;
        std::cout << "->";
        std::cin >> choice;

        switch (choice) {
        case 1:
            head(data, 5);
            break;
        case 2:
            rankStudents();
            break;
        case 3:
            comparison();
            break;
        case 4:
            std::cout << "You choose exit.";
            break;
        default:
            std::cout << "Choose a valid number.";
        }
    } while (choice != 4);

    return 0;
}