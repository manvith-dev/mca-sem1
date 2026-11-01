#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class HashMap {
  public:
    static const int TABLE_SIZE = 10;

    int hashTable[TABLE_SIZE];
    int collisionCount = 0;

    void displayMenu() {
        std::cout << "\n";
        std::cout << "-------------------------\n";
        std::cout << " Hashmap Operations \n";
        std::cout << "-------------------------\n";
        std::cout << "1. Modulo Division Hashing\n";
        std::cout << "2. Digit Extraction Hashing\n";
        std::cout << "3. Fold Boundary Hashing\n";
        std::cout << "4. Mid Square Hashing\n";
        std::cout << "5. Direct Hashing\n";
        std::cout << "0. Exit\n";
        std::cout << "-------------------------\n";
        std::cout << "Enter your choice: \n";
    }

    void initializeHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = -1;
        }
    }

    int linearProbing(int address, int &localCollisions) {
        int probeCount = 0;

        while (probeCount < TABLE_SIZE &&
               hashTable[(address + probeCount) % TABLE_SIZE] != -1) {
            localCollisions++;
            probeCount++;
        }

        if (probeCount >= TABLE_SIZE) {
            return -1;
        }
        return address + probeCount;
    }

    int moduloDivisionHashing(int key) {
        int address = key % TABLE_SIZE;
        int localCollisions = 0;

        address = linearProbing(address, localCollisions);
        if (address == -1) {
            return address;
        }

        hashTable[address % TABLE_SIZE] = key;
        collisionCount += localCollisions;

        return 0;
    }

    int getDigitAtPosition(int number, int position) {
        int divisor = 1;

        while (position-- > 1) {
            divisor *= 10;
        }

        return (number / divisor) % 10;
    }

    int countDigits(int number) {
        if (number == 0) {
            return 1;
        }

        int digitCount = 0;

        while (number > 0) {
            number /= 10;
            digitCount++;
        }

        return digitCount;
    }

    int digitExtractionHashing(std::vector<int> &digitPositions, int key) {
        int address = 0;

        std::sort(digitPositions.begin(), digitPositions.end(),
                  std::greater<int>());

        for (const int position : digitPositions) {
            address = (address * 10) + getDigitAtPosition(key, position);
        }

        int localCollisions = 0;

        address = linearProbing(address, localCollisions);
        if (address == -1) {
            return address;
        }

        hashTable[address % TABLE_SIZE] = key;
        collisionCount += localCollisions;

        return 0;
    }

    int midSquareHashing(int key) {
        int address = 0;
        int localCollisions = 0;

        int squaredKey = key * key;
        int digitCount = countDigits(squaredKey);

        if (digitCount % 2 == 0) {
            address =
                (getDigitAtPosition(squaredKey, digitCount / 2 + 1) * 10) +
                getDigitAtPosition(squaredKey, digitCount / 2);
        } else {
            address = getDigitAtPosition(squaredKey, digitCount / 2 + 1);
        }

        std::cout << "Square: " << squaredKey << " address: " << address
                  << std::endl;

        address = linearProbing(address, localCollisions);
        if (address == -1) {
            return address;
        }

        hashTable[address % TABLE_SIZE] = key;
        collisionCount += localCollisions;

        return 0;
    }

    int foldBoundaryHashing(int key) {
        int groupSize = countDigits(TABLE_SIZE - 1);

        std::vector<std::string> digitGroups;
        std::string keyString = std::to_string(key);

        for (int i = keyString.length(); i > 0; i -= groupSize) {
            int start = std::max(0, i - groupSize);

            std::string group = keyString.substr(start, i - start);

            if (group.length() < groupSize) {
                group = std::string(groupSize - group.length(), '0') + group;
            }

            digitGroups.push_back(group);
        }

        std::reverse(digitGroups[0].begin(), digitGroups[0].end());

        if (digitGroups.size() > 1) {
            std::reverse(digitGroups[digitGroups.size() - 1].begin(),
                         digitGroups[digitGroups.size() - 1].end());
        }

        int sum = 0;

        for (const std::string group : digitGroups) {
            sum += std::stoi(group);
        }

        std::string sumString = std::to_string(sum);

        int address = std::stoi(
            sumString.substr(sumString.length() - groupSize, groupSize));

        int localCollisions = 0;

        address = linearProbing(address, localCollisions);
        if (address == -1) {
            return address;
        }

        hashTable[address % TABLE_SIZE] = key;
        collisionCount += localCollisions;

        return 0;
    }

    int directHashing(int key) {
        int address = key % TABLE_SIZE;
        int localCollisions = 0;

        address = linearProbing(address, localCollisions);
        if (address == -1) {
            return address;
        }

        hashTable[address % TABLE_SIZE] = key;
        collisionCount += localCollisions;

        return 0;
    }

    void displayHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i] != -1) {
                std::cout << "\nIndex: " << i << " Value: " << hashTable[i];
            }
        }

        std::cout << "\nCollisions: " << collisionCount;
    }
};

int main() {
    HashMap hashMap;
    hashMap.initializeHashTable();

    int choice;
    int key;
    int digitCount;

    hashMap.displayMenu();
    std::cin >> choice;

    std::cout << "\nEnter -1 to exit:\n";

    std::vector<int> digitPositions;

    switch (choice) {
    case 1:
        while (std::cin >> key && key != -1) {
            int result = hashMap.moduloDivisionHashing(key);

            if (result == -1) {
                std::cout << "\nHashmap is full.\n";
                break;
            }
        }

        hashMap.displayHashTable();
        break;

    case 2:
        std::cout << "How many digits do you want to extract? ";
        std::cin >> digitCount;

        for (int i = 0; i < digitCount; i++) {
            int position;
            std::cin >> position;
            digitPositions.push_back(position);
        }

        while (std::cin >> key && key != -1) {
            int result = hashMap.digitExtractionHashing(digitPositions, key);

            if (result == -1) {
                std::cout << "\nHashmap is full.\n";
                break;
            }
        }

        hashMap.displayHashTable();
        break;

    case 3:
        while (std::cin >> key && key != -1) {
            int result = hashMap.foldBoundaryHashing(key);

            if (result == -1) {
                std::cout << "\nHashmap is full.\n";
                break;
            }
        }

        hashMap.displayHashTable();
        break;

    case 4:
        while (std::cin >> key && key != -1) {
            int result = hashMap.midSquareHashing(key);

            if (result == -1) {
                std::cout << "\nHashmap is full.\n";
                break;
            }
        }

        hashMap.displayHashTable();
        break;

    case 5:
        while (std::cin >> key && key != -1) {
            int result = hashMap.directHashing(key);

            if (result == -1) {
                std::cout << "\nHashmap is full.\n";
                break;
            }
        }

        hashMap.displayHashTable();
        break;

    case 0:
        return 0;

    default:
        std::cout << "Please choose a valid value." << std::endl;
        break;
    }

    return 0;
}