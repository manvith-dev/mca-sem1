// Stack using array

#include <iostream>

class Stack {
  private:
    int stack[10];
    int top = -1;
    int max_size = sizeof(stack) / sizeof(int);

  public:
    void overflowCondition() { std::cout << "Overflow Condition"; }

    void underflowCondition() { std::cout << "Underflow Condition"; }

    bool isEmpty() {
        if (top == -1)
            return true;
        return false;
    }

    bool isFull() {
        if (top == max_size - 1)
            return true;
        return false;
    }

    int peek() { return stack[top]; }

    void push(int value) {
        if (isFull()) {
            overflowCondition();
            return;
        }
        stack[++top] = value;
        std::cout << "The value :" << value << " was pushed\n";
        return;
    }

    int pop() {
        std::cout << "The value :" << stack[top] << " was pushed\n";
        return stack[top--];
    }

    bool update(int index, int value) {
        if (top >= index) {
            stack[index] = value;
            return true;
        }
        return false;
    }

    void display() {
        if (isEmpty()) {
            underflowCondition();
            return;
        }
        std::cout << "[ " << stack[top] << " ] <- Top\n";
        for (int i = top - 1; i >= 0; i--) {
            std::cout << "[ " << stack[i] << " ]\n";
        }
    }

    int size() { return top + 1; }
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
    std::cout << "8. isFull\n";
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

            int index, value;

            std::cout << "Enter index to update: ";
            std::cin >> index;

            std::cout << "Enter new value: ";
            std::cin >> value;

            if (stack->update(index, value)) {
                std::cout << "Element updated successfully.\n";
            } else {
                std::cout << "Invalid index.\n";
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

        case 8:
            std::cout << (stack->isFull() ? "Stack is full.\n"
                                          : "Stack is not full.\n");
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