#include <iostream>

class Queue {
  public:
    int frontIdx = -1;
    int rearIdx = -1;

    const static int total_size = 5;
    int queue[total_size];

    void enqueue(int value) {
        if (rearIdx == total_size - 1) {
            std::cout << "Overflow Condition.";
            return;
        }
        if (frontIdx == -1) {
            frontIdx++;
        }
        rearIdx++;
        queue[rearIdx] = value;
        std::cout << "The element was " << value << " enqueued.";
        return;
    }

    void dequeue() {
        if (frontIdx > rearIdx || frontIdx == -1) {
            std::cout << "Underflow Condition";
            return;
        }
        std::cout << "The element was " << queue[frontIdx++] << " removed.";
        if (frontIdx > rearIdx) {
            frontIdx = -1;
            rearIdx = -1;
        }
        return;
    }

    bool isEmpty() {
        if ((rearIdx == -1 && frontIdx == -1) || frontIdx > rearIdx) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (rearIdx = total_size) {
            return true;
        }
        return false;
    }

    int front() { return queue[frontIdx]; }

    int rear() { return queue[rearIdx]; }

    void display() {
        if (isEmpty()) {
            std::cout << "Underflow condition. No element present in queue";
            return;
        }

        std::cout << "front ->";
        for (int i = frontIdx; i <= rearIdx; i++) {
            std::cout << "[ " << queue[i] << " ]";
        }
        std::cout << "<- rear";
    }

    int size() {
        if (frontIdx == -1 && rearIdx == -1) {
            return 0;
        }
        return rearIdx - frontIdx + 1;
    }
};

int main() {
    Queue q;
    int choice, value;

    std::cout << "\n\n===== QUEUE MENU =====\n";
    std::cout << "1. Enqueue\n";
    std::cout << "2. Dequeue\n";
    std::cout << "3. Display Front Element\n";
    std::cout << "4. Display Rear Element\n";
    std::cout << "5. Display Queue\n";
    std::cout << "6. Check if Queue is Empty\n";
    std::cout << "7. Check if Queue is Full\n";
    std::cout << "8. Display Queue Size\n";
    std::cout << "9. Exit\n";

    while (choice != 9) {
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the value to enqueue: ";
            std::cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if (!q.isEmpty()) {
                std::cout << "Front element: " << q.front();
            } else {
                q.front();
            }
            break;

        case 4:
            if (!q.isEmpty()) {
                std::cout << "Rear element: " << q.rear();
            } else {
                q.rear();
            }
            break;

        case 5:
            q.display();
            break;

        case 6:
            if (q.isEmpty()) {
                std::cout << "Queue is empty.";
            } else {
                std::cout << "Queue is not empty.";
            }
            break;

        case 7:
            if (q.isFull()) {
                std::cout << "Queue is full.";
            } else {
                std::cout << "Queue is not full.";
            }
            break;

        case 8:
            std::cout << "Queue size: " << q.size();
            break;

        case 9:
            std::cout << "Exiting program...";
            break;

        default:
            std::cout << "Invalid choice. Please try again.";
        }
    }

    return 0;
}