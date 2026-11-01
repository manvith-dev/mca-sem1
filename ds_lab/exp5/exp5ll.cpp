// Stack using Linked List

#include <iostream>

class Stack {
  private:
    struct Node {
        int val;
        Node *next;
    };

    int count = 0;
    Node *top = nullptr;

  public:
    void underflowCondition() { std::cout << "Underflow Condition"; }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    int peek() { return top->val; }

    void push(int value) {
        Node *node = new Node();
        node->val = value;
        node->next = top;
        top = node;
        count++;
        std::cout << "The element " << value << " was pushed";
    }

    int pop() {
        int value = top->val;
        Node *prevTop = top;
        top = top->next;
        delete prevTop;
        count--;
        return value;
    }

    bool update(int position, int value) {
        if (position < 0 || position >= count) {
            return false;
        }
        Node *cur = top;
        for (int _ = 0; _ < count - position - 1; _++) {
            cur = cur->next;
        }
        cur->val = value;
        return true;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty, push some elements\n";
            return;
        }
        std::cout << "[" << top->val << "] <- Top\n";
        Node *cur = top->next;
        while (cur != nullptr) {
            std::cout << "[" << cur->val << "]\n";
            cur = cur->next;
        }
    }

    int size() { return count; }
};

void showMenu() {
    std::cout << "====================\n";
    std::cout << "STACK\n";
    std::cout << "====================\n";
    std::cout << "1. Push\n";
    std::cout << "2. Pop\n";
    std::cout << "3. Update\n";
    std::cout << "4. Peek\n";
    std::cout << "5. Size\n";
    std::cout << "6. Display\n";
    std::cout << "7. isEmpty\n";
    std::cout << "0. Exit\n";
}

int main() {
    Stack *stack = new Stack();
    int choice = -1;
    showMenu();

    while (choice != 0) {
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {

            int value;
            std::cout << "Enter value to push: ";
            std::cin >> value;

            stack->push(value);
            break;
        }

        case 2:
            if (stack->isEmpty()) {
                stack->underflowCondition();
            } else {
                std::cout << "The element " << stack->pop() << " was popped.\n";
            }
            break;

        case 3: {

            int position, value;

            std::cout << "Enter position to update: ";
            std::cin >> position;

            std::cout << "Enter new value: ";
            std::cin >> value;

            if (stack->update(position, value)) {
                std::cout << "Element updated successfully.\n";
            } else {
                std::cout << "Invalid position.\n";
            }
            break;
        }

        case 4:
            if (stack->isEmpty()) {
                stack->underflowCondition();
            } else {
                std::cout << "Top element: " << stack->peek() << '\n';
            }
            break;

        case 5:
            std::cout << "Stack size: " << stack->size() << '\n';
            break;

        case 6:
            stack->display();
            break;

        case 7:
            std::cout << (stack->isEmpty() ? "Stack is empty.\n"
                                           : "Stack is not empty.\n");
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }

        std::cout << '\n';
    }

    delete stack;
    return 0;
}