#include<iostream>

class LinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int v) {
            val = v;
            next = nullptr;
        }
    };
    Node *head = nullptr;
    int size = 0;

    void insertAtBeginning(int value) {
        Node *node = new Node(value);
        if (head != nullptr) {
            node->next = head;
        }
        head = node;
        std::cout << "The value " << value << " has been inserted into the beginning of linked list.";
    }

    void insertAtEnd(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node *cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = node;
        }
        std::cout << "The value " << value << " has been inserted into the end of linked list."; 
    }

    void insertAfterValue(int value, int posVal) {
        Node *node = new Node(value);
        Node *cur = head;
        while (cur != nullptr && cur->val != posVal) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            std::cout << "The element is not present in the linked list";
        } else {
            node->next = cur->next;
            cur->next = node;
        }

        std::cout << "The value " << value << " has been inserted into after value" << posVal << "of linked list."; 
    }

    void insertBeforeValue(int value, int posVal) {
        Node *node = new Node(value);

        Node *cur = head;
        while (cur->next != nullptr && cur->next->val != posVal) {
            cur = cur->next;
        }
        if (cur->next == nullptr) {
            std::cout << "The element is not present in the linked list";
        } else {
            node->next = cur->next;
            cur->next = node;
        }

        std::cout << "The value " << value << " has been inserted into before value" << posVal << "of linked list."; 
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "The linked list is empty";
        } else {
            Node *prev = head;
            head = head->next;
            std::cout << "The value " << prev->val << " has been deleted from the linked list.";
            delete prev;
        }
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "The linked list is empty";
        } else if (head->next = nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node *cur = head;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            Node* toDelete = cur->next;
            cur->next = cur->next->next;
            std::cout << "The value " << toDelete->val << " has been deleted from the linked list.";
            delete toDelete;
        }
    }

    void deleteSpecific(int value) {
        Node *cur = head;
        while (cur != nullptr && cur->val != value) {

        }
    }



};