#include <iostream>

class Queue {
  public:
    struct Node {
        int val;
        Node *next = nullptr;
    };

    Node *frontptr = nullptr;
    Node *rearptr = nullptr;

    int count = 0;

    void enqueue(int value) {
        Node *node = new Node();
        node->val = value;
        if (frontptr == nullptr) {
            frontptr = node;
            rearptr = node;
        } else {
            rearptr->next = node;
            rearptr = node;
        }
        std::cout << "The element " << value << " enqueued.";
        count++;
        return;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Underflow condition. No elements present in queue.";
            return;
        }
        Node *prev = frontptr;
        frontptr = frontptr->next;
        std::cout << "The element " << prev->val << " removed.";
        count--;
        delete prev;
    }

    bool isEmpty() {
        if (rearptr == nullptr || frontptr == nullptr) {
            return true;
        }
        return false;
    }

    int front() { return frontptr->val; }

    int rear() { return rearptr->val; }

    void display() {
        if (isEmpty()) {
            std::cout << "Underflow condition. No elements present in queue.";
            return;
        }
        Node *cur = frontptr;
        std::cout << "front ->";
        while (cur != nullptr) {
            std::cout << "[ " << cur->val << " ]";
            cur = cur->next;
        }
        std::cout << "<- rear";
    }

    int size() { return count; }
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
    std::cout << "7. Display Queue Size\n";
    std::cout << "8. Exit\n";

    while (choice != 8) {
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
            std::cout << "Queue size: " << q.size();
            break;

        case 8:
            std::cout << "Exiting program...";
            break;

        default:
            std::cout << "Invalid choice. Please try again.";
        }
    }

    return 0;
}