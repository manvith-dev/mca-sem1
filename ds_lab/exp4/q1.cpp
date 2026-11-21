
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL, *head2 = NULL, *p, *q;

class Sll {
  public:
    int element;

    // Node creation
    Node *createNode(int element) {
        p = (Node *)malloc(sizeof(Node));

        p->data = element;
        p->next = NULL;

        return p;
    }

    // 4 Types of Insertion

    void insertFromB() {
        int element;
        std::cout << "Enter element :";
        std::cin >> element;

        p = createNode(element);
        if (head != NULL) {
            p->next = head;
        }
        head = p;
    }

    void insertFromE() {
        int element;
        std::cout << "Enter element :";
        std::cin >> element;

        p = createNode(element);
        q = head;

        if (head == NULL) {
            p->next = head;
            head = p;
        } else {
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }

    void insertAfterValue() {
        int value;

        cout << "Enter value: ";
        cin >> value;

        q = head;

        while (q != NULL && q->data != value) {
            q = q->next;
        }

        if (q == NULL) {
            std::cout << "Element" << value << "not present in the linked list";
        } else {
            p->next = q->next;
            q->next = p;
        }
    }

    void insertBeforeValue() {
        int value;

        cout << "Enter value: ";
        cin >> value;

        q = head;

        while (q != NULL && q->next != NULL && q->next->data != value) {
            q = q->next;
        }

        if (q == NULL) {
            std::cout << "Element" << value << "not present in the linked list";
        } else {
            p->next = q->next;
            q->next = p;
        }
    }

    // 3 Types of Deletion

    void deleteFromB() {
        if (head == NULL) {
            std::cout << "Linked list is empty";
        } else {
            head = head->next;
        }
    }

    void deleteFromE() {
        if (head == NULL) {
            std::cout << "Linked list is empty";
        } else if (head->next == NULL) {
            head = head->next;
        } else {
            q = head;

            while (q->next->next != NULL) {
                q = q->next;
            }

            q->next = NULL;
        }
    }

    void deleteElement() {
        int value;

        cout << "Enter value to delete: ";
        cin >> value;

        if (head->data == value) {
            head = head->next;
        } else {

            q = head;

            while (q != NULL && q->next->data != value) {
                q = q->next;
            }

            if (q == NULL) {
                std::cout << "Element not found";
            } else {
                q->next = q->next->next;
                std::cout << "Node has been deleted from the linked list";
            }
        }
    }

    // Basic Operations

    void display() {
        q = head;
        std::cout << "head -> ";
        while (q != NULL) {
            std::cout << q->data << " -> ";
            q = q->next;
        }
        std::cout << "NULL\n";
    }

    int count() {
        int c = 0;

        q = head;
        while (q != NULL) {
            c++;
            q = q->next;
        }

        return c;
    }

    void search() {
        int value;

        cout << "Enter value to search: ";
        cin >> value;

        int pos = 0;
        while (q != NULL) {
            if (q->data == value) {
                std::cout << "The value " << value << " is present at position "
                          << pos << "(0 indexed)\n";
            }
            q = q->next;
            pos++;
        }
    }

    void reverse() {
        if (head == NULL) {
            std::cout << "Linked list is empty.\n";
            return;
        } else if (head->next == NULL) {
            return;
        }
        Node *prev = head;
        q = head->next;

        while (q != NULL) {
            q->next = prev;
            prev = q;
            q = q->next;
        }
    }

    void sort() { head = mergeSort(head); }

    Node *mergeSort(Node *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        Node *mid = getMiddle(head);
        Node *a = head;
        Node *b = mid->next;

        mid->next = NULL;
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }

    Node *merge(Node *head1, Node *head2) {
        Node *dummy = new Node();
        q = dummy;
        while (head1 != NULL && head2 != NULL) {
            if (head1->data < head2->data) {
                q->next = head1;
                head1 = head1->next;
            } else {
                q->next = head2;
                head2 = head2->next;
            }
            q = q->next;
        }

        if (head1 != NULL) {
            q->next = head1;
        }

        if (head2 != NULL) {
            q->next = head2;
        }
        return dummy->next;
    }

    Node *getMiddle(Node *head) {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Advanced Operations

    void merge() {
        // Use head and head2
        // Write your logic here
    }

    void unionList() {
        // Use head and head2
        // Write your logic here
    }

    void intersection() {
        // Use head and head2
        // Write your logic here
    }

    void concatenate() {
        // Use head and head2
        // Write your logic here
    }

    // Cycle Operations

    void detectCycle() {
        // Write your logic here
    }

    void displayCycle() {
        // Write your logic here
    }
};

int main() {
    int ch;
    Sll obj;

    do {
        cout << "\n----- SINGLY LINKED LIST -----" << endl;

        cout << "1. Insert From Beginning" << endl;
        cout << "2. Insert From End" << endl;
        cout << "3. Insert After Value" << endl;
        cout << "4. Insert Before Value" << endl;

        cout << "5. Delete From Beginning" << endl;
        cout << "6. Delete From End" << endl;
        cout << "7. Delete Element" << endl;

        cout << "8. Display" << endl;
        cout << "9. Count" << endl;
        cout << "10. Search" << endl;

        cout << "11. Reverse" << endl;
        cout << "12. Sort" << endl;

        cout << "13. Merge" << endl;
        cout << "14. Union" << endl;
        cout << "15. Intersection" << endl;
        cout << "16. Concatenation" << endl;

        cout << "17. Detect Cycle" << endl;
        cout << "18. Display Cycle" << endl;

        cout << "19. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.insertFromB();
            break;
        case 2:
            obj.insertFromE();
            break;
        case 3:
            obj.insertAfterValue();
            break;
        case 4:
            obj.insertBeforeValue();
            break;

        case 5:
            obj.deleteFromB();
            break;
        case 6:
            obj.deleteFromE();
            break;
        case 7:
            obj.deleteElement();
            break;

        case 8:
            obj.display();
            break;
        case 9:
            cout << "Count: " << obj.count() << endl;
            break;
        case 10:
            obj.search();
            break;

        case 11:
            obj.reverse();
            break;
        case 12:
            obj.sort();
            break;

        case 13:
            obj.merge();
            break;
        case 14:
            obj.unionList();
            break;
        case 15:
            obj.intersection();
            break;
        case 16:
            obj.concatenate();
            break;

        case 17:
            obj.detectCycle();
            break;
        case 18:
            obj.displayCycle();
            break;

        case 19:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (ch != 19);

    return 0;
}
