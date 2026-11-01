#include <iostream>

class Queue {
  public:
    int frontIdx = -1;
    int rearIdx = -1;
    int dq_size = 0;

    const static int total_size = 5;
    int queue[total_size];

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Overflow Condition.";
            return;
        }
        if (frontIdx == -1) {
            frontIdx = 0;
        }
        rearIdx = (rearIdx + 1) % total_size;
        queue[rearIdx] = value;
        std::cout << "The element was " << value << " enqueued.";
        dq_size++;
        return;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Underflow Condition";
            return;
        }
        std::cout << "The element was " << queue[frontIdx] << " removed.";
        frontIdx = (frontIdx + 1) % total_size;
        dq_size--;
        if (isEmpty()) {
            frontIdx = -1;
            rearIdx = -1;
        }
        return;
    }

    bool isEmpty() { return dq_size == 0; }

    bool isFull() { return dq_size == total_size; }

    int front() {
        if (isEmpty()) {
            std::cout << "Queue is empty.";
            return -1;
        }
        return queue[frontIdx];
    }

    int rear() {
        if (isEmpty()) {
            std::cout << "Queue is empty.";
            return -1;
        }
        return queue[rearIdx];
    }

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
        std::cout << "\n\n===== CIRCULAR QUEUE MENU =====\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Get Front Element\n";
        std::cout << "4. Get Rear Element\n";
        std::cout << "5. Display Queue\n";
        std::cout << "6. Get Size\n";
        std::cout << "7. Check if Empty\n";
        std::cout << "8. Check if Full\n";
        std::cout << "0. Exit\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter element to enqueue: ";
            std::cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if (!q.isEmpty())
                std::cout << "Front element: " << q.front();
            else
                std::cout << "Queue is empty.";
            break;

        case 4:
            if (!q.isEmpty())
                std::cout << "Rear element: " << q.rear();
            else
                std::cout << "Queue is empty.";
            break;

        case 5:
            q.display();
            break;

        case 6:
            std::cout << "Queue size: " << q.size();
            break;

        case 7:
            std::cout << (q.isEmpty() ? "Queue is empty."
                                      : "Queue is not empty.");
            break;

        case 8:
            std::cout << (q.isFull() ? "Queue is full." : "Queue is not full.");
            break;

        case 0:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Try again.";
        }

    } while (choice != 0);

    return 0;
}