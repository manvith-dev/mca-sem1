#include <iostream>

class Queue {
  public:
    int frontIdx = -1;
    int rearIdx = -1;
    int dq_size = 0;

    const static int total_size = 5;
    int queue[total_size];

    void insertRear(int value) {
        if (isFull()) {
            std::cout << "Overflow Condition.";
            return;
        }
        if (frontIdx == -1) {
            frontIdx++;
        }
        rearIdx++;
        queue[rearIdx % total_size] = value;
        std::cout << "The element was " << value << " enqueued.";
        dq_size++;
        return;
    }
    void insertFront(int value) {
        if (isFull()) {
            std::cout << "Overflow Condition.";
            return;
        }
        if (frontIdx == -1) {
            frontIdx++;
        } else if (frontIdx == 0) {
            frontIdx = total_size - 1;
        } else {
            frontIdx--;
        }
        queue[frontIdx % total_size] = value;
        std::cout << "The element was " << value << " enqueued.";
        dq_size++;
        return;
    }

    void removeFront() {
        if (isEmpty()) {
            std::cout << "Underflow Condition";
            return;
        }
        std::cout << "The element was " << queue[frontIdx++ % total_size]
                  << " removed.";
        dq_size--;
        if (isEmpty()) {
            frontIdx = -1;
            rearIdx = -1;
        }
        return;
    }

    void removeRear() {
        if (isEmpty()) {
            std::cout << "Underflow Condition";
            return;
        }
        std::cout << "The element was " << queue[rearIdx % total_size]
                  << " removed.";

        if (rearIdx == 0) {
            rearIdx = total_size - 1;
        } else {
            rearIdx--;
        }

        dq_size--;
        if (isEmpty()) {
            frontIdx = -1;
            rearIdx = -1;
        }
        return;
    }

    bool isEmpty() { return dq_size == 0; }

    bool isFull() { return dq_size == total_size; }

    int front() { return queue[frontIdx % total_size]; }

    int rear() { return queue[rearIdx % total_size]; }

    void display() {
        if (isEmpty()) {
            std::cout << "Underflow condition. No element present in queue";
            return;
        }

        std::cout << "front ->";
        for (int i = frontIdx; i < frontIdx + dq_size; i++) {
            std::cout << "[ " << queue[i % total_size] << " ]";
        }
        std::cout << "<- rear";
    }

    int size() { return dq_size; }

    void showMenu() {
        std::cout << "\n\n===== DEQUE MENU =====\n";
        std::cout << "1. Insert at Front\n";
        std::cout << "2. Insert at Rear\n";
        std::cout << "3. Remove from Front\n";
        std::cout << "4. Remove from Rear\n";
        std::cout << "5. Get Front Element\n";
        std::cout << "6. Get Rear Element\n";
        std::cout << "7. Display Deque\n";
        std::cout << "8. Get Size\n";
        std::cout << "9. Check if Empty\n";
        std::cout << "10. Check if Full\n";
        std::cout << "0. Exit\n";
    }
};

int main() {
    Queue q;
    int choice, value;
    q.showMenu();

    while (choice != 0) {

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            q.insertFront(value);
            break;

        case 2:
            std::cout << "Enter value: ";
            std::cin >> value;
            q.insertRear(value);
            break;

        case 3:
            q.removeFront();
            break;

        case 4:
            q.removeRear();
            break;

        case 5:
            if (!q.isEmpty())
                std::cout << "Front element: " << q.front();
            else
                std::cout << "Deque is empty.";
            break;

        case 6:
            if (!q.isEmpty())
                std::cout << "Rear element: " << q.rear();
            else
                std::cout << "Deque is empty.";
            break;

        case 7:
            q.display();
            break;

        case 8:
            std::cout << "Deque size: " << q.size();
            break;

        case 9:
            std::cout << (q.isEmpty() ? "Deque is empty."
                                      : "Deque is not empty.");
            break;

        case 10:
            std::cout << (q.isFull() ? "Deque is full." : "Deque is not full.");
            break;

        case 0:
            std::cout << "Exiting...";
            break;

        default:
            std::cout << "Invalid choice. Try again.";
        }
    }

    return 0;
}
