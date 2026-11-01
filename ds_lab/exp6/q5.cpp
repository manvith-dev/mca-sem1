#include <iostream>

class PriorityQueue {
  public:
    struct Node {
        int value;
        int priority;
        Node *next;

        Node(int v, int p) {
            value = v;
            priority = p;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int pqSize = 0;

    void enqueue(int value, int priority) {
        Node *node = new Node(value, priority);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else if (priority > head->priority) {
            node->next = head;
            head = node;
        } else {
            Node *cur = head;
            while (cur->next != nullptr && cur->next->priority >= priority) {
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;

            if (node->next == nullptr) {
                tail = node;
            }
        }
        pqSize++;
        std::cout << "The element :" << value << " with priority :" << priority
                  << " has been enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }
        Node *prev = head;
        head = head->next;
        std::cout << "The element :" << prev->value
                  << " with priority :" << prev->priority
                  << " has been dequeued.\n";
        if (head == nullptr) {
            tail = nullptr;
        }
        delete prev;
        pqSize--;
    }

    bool isEmpty() {
        if (pqSize == 0) {
            return true;
        }
        return false;
    }

    int displayRear() { return tail->value; }

    int displayFront() { return head->value; }

    void display() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty.\n";
            return;
        }

        Node *cur = head;
        while (cur != nullptr) {
            std::cout << "( " << cur->value << " , " << cur->priority
                      << " ) -> ";
            cur = cur->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, priority;

    std::cout << "\n--- Priority Queue Menu ---\n";
    std::cout << "1. Enqueue\n";
    std::cout << "2. Dequeue\n";
    std::cout << "3. Display Front\n";
    std::cout << "4. Display Rear\n";
    std::cout << "5. Display Priority Queue\n";
    std::cout << "6. Check if Empty\n";
    std::cout << "7. Exit\n";
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            std::cout << "Enter priority: ";
            std::cin >> priority;
            pq.enqueue(value, priority);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            if (!pq.isEmpty()) {
                std::cout << "Front element: " << pq.displayFront() << "\n";
            } else {
                std::cout << "Priority Queue is empty.\n";
            }
            break;

        case 4:
            if (!pq.isEmpty()) {
                std::cout << "Rear element: " << pq.displayRear() << "\n";
            } else {
                std::cout << "Priority Queue is empty.\n";
            }
            break;

        case 5:
            pq.display();
            break;

        case 6:
            if (pq.isEmpty()) {
                std::cout << "Priority Queue is empty.\n";
            } else {
                std::cout << "Priority Queue is not empty.\n";
            }
            break;

        case 7:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}