
#include <iostream>
#include <stdlib.h>
#include <unordered_set>
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
        int element;
        std::cout << "Enter element :";
        std::cin >> element;

        p = createNode(element);

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
        int element;
        std::cout << "Enter element :";
        std::cin >> element;

        p = createNode(element);
        int value;

        cout << "Enter value: ";
        cin >> value;

        if (head == NULL) {
            std::cout << "Linked list is empty\n";
            return;
        }
        if (head->data == value) {
            p->next = head;
            head = p;
            return;
        }

        q = head;

        while (q->next != NULL && q->next->data != value) {
            q = q->next;
        }

        if (q->next == NULL) {
            std::cout << "Element " << value
                      << " not present in the linked list\n";
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

        if (head == NULL) {
            std::cout << "Linked list is empty\n";
            return;
        }

        if (head->data == value) {
            head = head->next;
            std::cout << "Node has been deleted from the linked list\n";
        } else {
            q = head;

            while (q->next != NULL && q->next->data != value) {
                q = q->next;
            }

            if (q->next == NULL) {
                std::cout << "Element not found\n";
            } else {
                q->next = q->next->next;
                std::cout << "Node has been deleted from the linked list\n";
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
        q = head;
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

        Node *prev = NULL;
        Node *next;
        q = head;

        while (q != NULL) {
            next = q->next;
            q->next = prev;
            prev = q;
            q = next;
        }
        head = prev;
    }

    void sort() { head = mergeSort(head); }

    Node *mergeSort(Node *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node *mid = getMiddle(head);
        Node *a = head;
        Node *b = mid->next;

        mid->next = NULL;
        a = mergeSort(a);
        b = mergeSort(b);
        return mergeSortHelper(a, b);
    }

    Node *mergeSortHelper(Node *head1, Node *head2) {
        Node *dummy = new Node();
        q = dummy;
        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {
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
        Node *res = dummy->next;
        delete dummy;
        return res;
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

    // Helpers for testing the advanced operations

    void createSecondList() {
        int n, element;
        cout << "How many elements in second list: ";
        cin >> n;

        head2 = NULL;
        for (int i = 0; i < n; i++) {
            cout << "Enter element: ";
            cin >> element;

            p = createNode(element);
            if (head2 == NULL) {
                head2 = p;
            } else {
                q = head2;
                while (q->next != NULL) {
                    q = q->next;
                }
                q->next = p;
            }
        }
    }

    void displaySecond() {
        q = head2;
        std::cout << "head2 -> ";
        while (q != NULL) {
            std::cout << q->data << " -> ";
            q = q->next;
        }
        std::cout << "NULL\n";
    }

    void createCycle() {
        int pos;
        cout << "Enter position (0 indexed) the last node should link to: ";
        cin >> pos;

        if (head == NULL) {
            cout << "Linked list is empty\n";
            return;
        }

        p = head;
        for (int i = 0; i < pos && p != NULL; i++) {
            p = p->next;
        }

        if (p == NULL) {
            cout << "Invalid position\n";
            return;
        }

        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p; // creates the cycle
    }

    // Advanced Operations (all work on head and head2)

    void merge() {
        Node *dummy = new Node();
        q = dummy;

        Node *q1 = head;
        Node *q2 = head2;

        while (q1 != NULL && q2 != NULL) {
            q->next = q1;
            q1 = q1->next;
            q = q->next;

            q->next = q2;
            q2 = q2->next;
            q = q->next;
        }

        if (q1 != NULL) {
            q->next = q1;
        }

        if (q2 != NULL) {
            q->next = q2;
        }
        head = dummy->next;
        head2 = NULL;
        delete dummy;
    }

    void unionList() {
        std::unordered_set<int> s;

        Node *dummy = new Node();
        q = dummy;

        Node *q1 = head;
        Node *q2 = head2;

        while (q1 != NULL && q2 != NULL) {
            if (!s.count(q1->data)) {
                q->next = q1;
                s.insert(q1->data);
                q1 = q1->next;
                q = q->next;
            } else {
                q1 = q1->next;
            }
            if (!s.count(q2->data)) {
                q->next = q2;
                s.insert(q2->data);
                q2 = q2->next;
                q = q->next;
            } else {
                q2 = q2->next;
            }
        }
        while (q1 != NULL) {
            if (!s.count(q1->data)) {
                q->next = q1;
                s.insert(q1->data);
                q1 = q1->next;
                q = q->next;
            } else {
                q1 = q1->next;
            }
        }

        while (q2 != NULL) {
            if (!s.count(q2->data)) {
                q->next = q2;
                s.insert(q2->data);
                q2 = q2->next;
                q = q->next;
            } else {
                q2 = q2->next;
            }
        }

        q->next = NULL;
        head = dummy->next;
        head2 = NULL;
        delete dummy;
    }

    void intersection() {
        std::unordered_set<int> s;
        std::unordered_set<int> added;

        Node *dummy = new Node();
        q = dummy;

        Node *q1 = head;
        Node *q2 = head2;

        while (q1 != NULL) {
            s.insert(q1->data);
            q1 = q1->next;
        }

        while (q2 != NULL) {
            if (s.count(q2->data) && !added.count(q2->data)) {
                q->next = q2;
                q = q->next;
                added.insert(q2->data);
            }
            q2 = q2->next;
        }
        q->next = NULL;
        head = dummy->next;
        head2 = NULL;
        delete dummy;
    }

    void concatenate() {
        if (head == NULL) {
            head = head2;
        } else {
            q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = head2;
        }
        head2 = NULL;
    }

    // Cycle Operations

    int detectCycle() {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL && slow != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                std::cout << "Cycle detected\n";
                return 1;
            }
        }
        std::cout << "Cycle undetected\n";
        return 0;
    }

    void displayCycle() {
        if (!detectCycle()) {
            std::cout << "There is no cycle\n";
            return;
        }

        std::unordered_set<Node *> listAddress;

        q = head;
        while (listAddress.count(q) == 0) {
            listAddress.insert(q);
            q = q->next;
        }

        listAddress.clear();
        std::cout << "Cycle : ";
        while (listAddress.count(q) == 0) {
            listAddress.insert(q);
            std::cout << q->data << " -> ";
            q = q->next;
        }
        std::cout << "(Back to start)\n";
    }
};

int main() {
    int ch;
    Sll obj;

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

    cout << "--- Helpers ---" << endl;
    cout << "20. Create Second List" << endl;
    cout << "21. Display Second List" << endl;
    cout << "22. Create Cycle" << endl;

    do {
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

        case 20:
            obj.createSecondList();
            break;
        case 21:
            obj.displaySecond();
            break;
        case 22:
            obj.createCycle();
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (ch != 19);

    return 0;
}