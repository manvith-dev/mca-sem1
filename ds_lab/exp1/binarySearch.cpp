#include <iostream>

int BinSearchRec(int arr[], int low, int high, int target) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;

  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] > target) {
    return BinSearchRec(arr, low, mid - 1, target);
  } else {
    return BinSearchRec(arr, mid + 1, high, target);
  }
}

void displayArr(int arr[], int size) {
  std::cout << "\nArray :";
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

  displayArr(arr, size);

  int target;
  std::cout << "Enter the element value to search: ";
  std::cin >> target;
  std::cout << "\n";

  int index = BinSearchRec(arr, 0, size - 1, target);

  if (index != -1) {
    std::cout << "The element: " << target << " is present at index: " << index
              << std::endl;
  } else {
    std::cout << "Element not present in array." << std::endl;
  }

  return 0;
}
