#include<iostream>
// #include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int d, Node*p, Node* n) {
        data = d;
        prev = p;
        next = n;
    }
};

class DoublyLinkedList {
    public:
    int element;
    int size = 0;
    Node *head = nullptr;
    Node *p;
    Node *q;

    void sizeChange(int change) {
        size = std::max(0, size + change);
    }

    void insertFromBeginning() {
        cout << "Enter the element to insert";
        cin >> element;
        p = new Node(element, nullptr, nullptr);
        if (head == nullptr) {
            head = p;
        } else {   
            p->next = head;
            head->prev = p;
            head = p;
        }
        sizeChange(1);
    }

    void insertAtEnd() {
        cout << "Enter the element to insert";
        cin >> element;
        if (head == nullptr) {
            head = new Node(element, nullptr, nullptr);
        } else {   
            q = head;
            while(q->next != nullptr) {
                q = q->next;
            }
            
            p = new Node(element, q, nullptr);
            q->next = p;
        }
        sizeChange(1);
    }

    void insertBeforeValue() {
        cout << "Enter the element to insert";
        cin >> element;

        int value;
        cout << "Enter value :";
        cin >> value;

        q = head;
        while (q!= nullptr && q->data != value) {
            q = q->next;
        }
        
        if (q == nullptr) {
            cout << "Element not found";
            return;
        } else if(q == head) {
            p = new Node(element, nullptr, nullptr);   
            p->next = head;
            head->prev = p;
            head = p;
        }else {
            p = new Node(element, q->prev, q);            
            q->prev->next = p;
        }
        sizeChange(1);

    }

    void insertAfterValue() {
        cout << "Enter the element to insert";
        cin >> element;

        int value;
        cout << "Enter value :";
        cin >> value;

        q = head;
        while (q!= nullptr && q->data != value) {
            q = q->next;
        }
        
        if (q == nullptr) {
            cout << "Element not found";
        } else {
            p = new Node(element, q, q->next);            
            q->next = p;
        }
        sizeChange(1);
    }

    void insertAtPosition() {
        cout << "Enter the element to insert";
        cin >> element;

        int position;
        cout << "Enter position (0 indexed):";
        cin >> position;
        if (position >= size || position < 0) {
            cout << "Invalid position";
            return;
        }
        q = head;
        for (int _ = 0; _ < position; _++) {
            q = q->next;
        }

        p = new Node(element, q->prev, q);
        q->prev->next = p;

        sizeChange(1);
    }

    void display() {
        q = head;
        while (q != nullptr) {
            cout << "[" << q->data << "] <-> ";
            q = q->next;
        }
        cout << "nullptr";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice;

    cout << "\n\n===== DOUBLY LINKED LIST MENU =====";
    cout << "\n1. Insert at Beginning";
    cout << "\n2. Insert at End";
    cout << "\n3. Insert Before a Value";
    cout << "\n4. Insert After a Value";
    cout << "\n5. Insert at a Position";
    cout << "\n6. Display";
    cout << "\n0. Exit";
    
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dll.insertFromBeginning();
                break;

            case 2:
                dll.insertAtEnd();
                break;

            case 3:
                dll.insertBeforeValue();
                break;

            case 4:
                dll.insertAfterValue();
                break;

            case 5:
                dll.insertAtPosition();
                break;
            case 6:
                dll.display();
                break;
            case 0:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice! Please try again.";
        }

    } while (choice != 0);

    return 0;
}