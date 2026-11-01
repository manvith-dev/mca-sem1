#include <iostream>

int LinSearchItr(int arr[], int target, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
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

  int index = LinSearchItr(arr, target, size);

  if (index != -1) {
    std::cout << "The element: " << target << " is present at index: " << index
              << std::endl;
  } else {
    std::cout << "Element not present in array." << std::endl;
  }

  return 0;
}
