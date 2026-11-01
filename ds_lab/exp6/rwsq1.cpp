#include <iostream>

class CustomerDeque {
    struct Node {
        std::string name;
        Node *next;

        Node(std::string n) {
            name = n;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;

  public:
    void addNormalCustomer(std::string name) {
        Node *node = new Node(name);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        std::cout << "The customer " << name
                  << " has been added to the rear of the queue";
    }

    void addUrgentCustomer(std::string name) {
        Node *node = new Node(name);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        std::cout << "The customer (urgent)" << name
                  << " has been added to the front of the queue";
    }

    void serveFront() {
        if (head == nullptr) {
            std::cout << "The customer queue is empty.";
        } else {
            Node *prev = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            std::cout << "The customer named :" << prev->name
                      << " has been served";
            delete prev;
        }
    }

    void serveRear() {
        if (head == nullptr) {
            std::cout << "The customer queue is empty.";
        } else if (head == tail) {
            std::cout << "The customer named :" << head->name
                      << " has been served";
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *cur = head;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            std::cout << "The customer named :" << tail->name
                      << " has been served";
            tail = cur;
            delete cur->next;
            cur->next = nullptr;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "The customer queue is empty.";
        } else {
            Node *cur = head;
            std::cout << "Customer Queue :";
            while (cur != nullptr) {
                std::cout << "[" << cur->name << "] ";
                cur = cur->next;
            }
        }
    }
};

int main() {
    CustomerDeque dq;
    int choice;
    std::string name;
    std::cout << "\n\n--- Customer Service System ---\n";
    std::cout << "1. Add Normal Customer\n";
    std::cout << "2. Add Urgent Customer\n";
    std::cout << "3. Serve Customer from Front\n";
    std::cout << "4. Serve Customer from Rear\n";
    std::cout << "5. Display Customer Queue\n";
    std::cout << "6. Exit\n";

    do {
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter customer name: ";
            std::getline(std::cin >> std::ws, name);
            dq.addNormalCustomer(name);
            break;

        case 2:
            std::cout << "Enter urgent customer name: ";
            std::getline(std::cin >> std::ws, name);
            dq.addUrgentCustomer(name);
            break;

        case 3:
            dq.serveFront();
            break;

        case 4:
            dq.serveRear();
            break;

        case 5:
            dq.display();
            break;

        case 6:
            std::cout << "Exiting Customer Service System.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}