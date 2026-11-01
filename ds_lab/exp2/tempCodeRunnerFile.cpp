#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class LibraryManagement {
  public:
    static const int TABLE_SIZE = 100;
    struct Book {
        long long unsigned int ISBN = 0;
        std::string name;
        std::string author;
        unsigned int collision = 0;
    };
    Book hashTable[TABLE_SIZE];
    int collisionCount = 0;

    void showMenu() {
        std::cout << "--------------------------------------\n";
        std::cout << "==========LIBRARY MANAGEMENT==========\n";
        std::cout << "--------------------------------------\n";
        std::cout << "1. Find a book using ISBN\n";
        std::cout << "2. Add a book using ISBN\n";
        std::cout << "3. Total collisions\n";
        std::cout << "--------------------------------------\n";
        std::cout << "Enter Choice:";
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

    int putBook(const long long unsigned int ISBN, std::string bookName,
                std::string bookAuthor) {

        Book book = {ISBN, bookName, bookAuthor};

        int groupSize = countDigits(TABLE_SIZE - 1);

        std::vector<std::string> digitGroups;
        std::string ISBNString = std::to_string(ISBN);

        for (int i = ISBNString.length(); i > 0; i -= groupSize) {
            int start = std::max(0, i - groupSize);

            std::string group = ISBNString.substr(start, i - start);

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

        if (hashTable[address % TABLE_SIZE].ISBN == 0) {
            hashTable[address % TABLE_SIZE] = book;
        } else {
            int probeCount = 0;

            while (probeCount < TABLE_SIZE &&
                   hashTable[address % TABLE_SIZE].ISBN != 0) {
                address++;
                localCollisions++;
                probeCount++;
            }

            if (probeCount >= TABLE_SIZE) {
                return -1;
            }
        }
        book.collision = localCollisions;
        hashTable[address % TABLE_SIZE] = book;
        collisionCount += localCollisions;

        return 0;
    }

    int getBook(const long long unsigned int ISBN) {
        int groupSize = countDigits(TABLE_SIZE - 1);

        std::vector<std::string> digitGroups;
        std::string ISBNString = std::to_string(ISBN);

        for (int i = ISBNString.length(); i > 0; i -= groupSize) {
            int start = std::max(0, i - groupSize);

            std::string group = ISBNString.substr(start, i - start);

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

        if (hashTable[address % TABLE_SIZE].ISBN == ISBN &&
            hashTable[address % TABLE_SIZE].collision == 0) {
            return address % TABLE_SIZE;
        } else {
            int probeCount = 0;

            while (probeCount < TABLE_SIZE &&
                   hashTable[address % TABLE_SIZE].collision != probeCount) {
                address++;
                probeCount++;
            }

            if (hashTable[address % TABLE_SIZE].ISBN == ISBN &&
                hashTable[address % TABLE_SIZE].collision == 0) {
                return address % TABLE_SIZE;
            }
        }

        return -1;
    }

    void displayBook(int idx) {
        if (idx < 0 || idx >= TABLE_SIZE) {
            std::cout << "\nNo books found\n";
            return;
        }
        std::cout << "\nBook ISBN :" << hashTable[idx].ISBN << std::endl;
        std::cout << "Book Name :" << hashTable[idx].name << std::endl;
        std::cout << "Book Author :" << hashTable[idx].author << std::endl;
    }
};

int main() {
    LibraryManagement library;
    int choice;
    long long unsigned int ISBN;
    std::string bookName, bookAuthor;

    while (true) {
        library.showMenu();

        if (!(std::cin >> choice)) {
            std::cout << "\nInvalid input. Exiting.\n";
            break;
        }

        switch (choice) {
        case 1: {
            std::cout << "Enter ISBN to search: ";
            std::cin >> ISBN;

            int idx = library.getBook(ISBN);
            library.displayBook(idx);
            break;
        }

        case 2: {
            std::cout << "Enter ISBN: ";
            std::cin >> ISBN;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter book name: ";
            std::getline(std::cin, bookName);

            std::cout << "Enter author name: ";
            std::getline(std::cin, bookAuthor);

            int result = library.putBook(ISBN, bookName, bookAuthor);

            if (result == 0)
                std::cout << "\nBook added successfully!\n";
            else
                std::cout << "\nHash table is full!\n";

            break;
        }

        case 3:
            std::cout << "Total collisions: " << library.collisionCount << '\n';
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}