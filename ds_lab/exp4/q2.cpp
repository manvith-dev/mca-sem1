#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int v, Node *p, Node *n) {
        data = v;
        prev = p;
        next = n;
    }
};

class DoublyLinkedList {
  private:
    Node *head;

  public:
    DoublyLinkedList() { head = nullptr; }

    // ---------- 4 Types of Insertion ----------

    void fixLinks() {
        if (head == nullptr)
            return;
        head->prev = nullptr;
        Node *cur = head;
        while (cur->next != nullptr) {
            cur->next->prev = cur;
            cur = cur->next;
        }
    }

    void insertAtBeginning(int value) {
        Node *node = new Node(value, nullptr, head);
        if (head != nullptr)
            head->prev = node;
        head = node;
    }

    void insertAtEnd(int value) {
        if (head == nullptr) {
            insertAtBeginning(value);
            return;
        }

        Node *cur = head;

        while (cur->next != nullptr) {
            cur = cur->next;
        }
        Node *node = new Node(value, cur, nullptr);
        cur->next = node;
    }

    void insertAfterValue(int target, int value) {
        Node *cur = head;
        while (cur != nullptr && cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            std::cout << "The list has no node with value" << target << "\n";
        } else {
            Node *node = new Node(value, cur, cur->next);
            if (cur->next != nullptr)
                cur->next->prev = node;
            cur->next = node;
        }
    }

    void insertBeforeValue(int target, int value) {
        Node *cur = head;
        while (cur != nullptr && cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            std::cout << "The list has no node with value" << target << "\n";
        } else if (cur == head) {
            insertAtBeginning(value);
        } else {
            cur = cur->prev;
            Node *node = new Node(value, cur, cur->next);
            cur->next = node;
            node->next->prev = node;
        }
    }

    // ---------- 3 Types of Deletion ----------

    void deleteFromBeginning() {
        if (isEmpty()) {
            return;
        }
        Node *toDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete toDelete;
    }

    void deleteFromEnd() {
        if (isEmpty())
            return;

        Node *cur = head;

        while (cur->next != nullptr) {
            cur = cur->next;
        }

        if (cur->prev == nullptr) {
            head = nullptr;
        } else {
            cur->prev->next = nullptr;
        }

        delete cur;
    }

    void deleteByValue(int value) {
        Node *cur = head;

        while (cur != nullptr && cur->data != value) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            std::cout << "The list has no node with value" << value << "\n";
            return;
        }
        if (cur->prev == nullptr) {
            deleteFromBeginning();
        } else {
            cur->prev->next = cur->next;
            if (cur->next != nullptr) {
                cur->next->prev = cur->prev;
            }
            delete cur;
        }
    }

    // ---------- Basic Operations ----------
    bool isEmpty() {
        if (head == nullptr) {
            std::cout << "Linked list is empty\n";
            return true;
        }
        return false;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        std::cout << "nullptr";
        Node *cur = head;
        while (cur != nullptr) {
            std::cout << " <--> " << cur->data;
            cur = cur->next;
        }
        std::cout << " <--> nullptr\n";
    }

    void displayBackward() {
        if (isEmpty()) {
            return;
        }
        Node *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        std::cout << "nullptr";
        while (cur != nullptr) {
            std::cout << " <--> " << cur->data;
            cur = cur->prev;
        }
        std::cout << " <--> nullptr\n";
    }

    int count() {
        int res = 0;
        Node *cur = head;
        while (cur != nullptr) {
            res++;
            cur = cur->next;
        }
        return res;
    }

    int search(int value) {
        int pos = -1;
        Node *cur = head;
        while (cur != nullptr) {
            pos++;
            if (cur->data == value) {
                return pos;
            }
            cur = cur->next;
        }
        return -1;
    }

    void reverse() {
        Node *cur = head;
        Node *last = nullptr;
        while (cur != nullptr) {
            Node *curPrev = cur->prev;
            cur->prev = cur->next;
            cur->next = curPrev;
            last = cur;
            cur = cur->prev;
        }
        head = last;
    }

    void sort() {
        int n = count();

        for (int i = 0; i < n; i++) {
            Node *cur = head;
            for (int j = 0; j < n - i - 1; j++) {
                if (cur->data > cur->next->data) {
                    int temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                }
                cur = cur->next;
            }
        }
    }

    // ---------- Operations Using a Second List ----------

    void merge(DoublyLinkedList &other) {
        Node *dummy = new Node(0, nullptr, nullptr);
        Node *q = dummy;

        Node *q1 = this->head;
        Node *q2 = other.head;

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
        this->head = dummy->next;
        other.head = nullptr;
        delete dummy;
        fixLinks();
    }

    void unionList(DoublyLinkedList &other) {
        std::unordered_set<int> s;

        Node *dummy = new Node(0, nullptr, nullptr);
        Node *q = dummy;

        Node *q1 = this->head;
        Node *q2 = other.head;

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
        this->head = dummy->next;
        other.head = nullptr;
        delete dummy;
        fixLinks();
    }

    void intersection(DoublyLinkedList &other) {
        std::unordered_set<int> s;
        std::unordered_set<int> added;

        Node *dummy = new Node(0, nullptr, nullptr);
        Node *q = dummy;

        Node *q1 = head;
        Node *q2 = other.head;

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
        this->head = dummy->next;
        other.head = nullptr;
        delete dummy;
        fixLinks();
    }

    void concatenate(DoublyLinkedList &other) {
        if (this->head == NULL) {
            this->head = other.head;
        } else {
            Node *cur = this->head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = other.head;
        }
        other.head = nullptr;
        fixLinks();
    }

    // ---------- Cycle Operations ----------

    void createCycle(int pos) {

        if (head == NULL) {
            cout << "Linked list is empty\n";
            return;
        }

        Node *p = head;
        for (int i = 0; i < pos && p != NULL; i++) {
            p = p->next;
        }

        if (p == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node *q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }

    bool detectCycle() {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL && slow != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                std::cout << "Cycle detected\n";
                return true;
            }
        }
        std::cout << "Cycle undetected\n";
        return false;
    }

    void displayCycle() {
        if (!detectCycle()) {
            std::cout << "There is no cycle\n";
            return;
        }

        std::unordered_set<Node *> listAddress;

        Node *q = head;
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

// ---------- Menu ----------

void printMenu() {
    cout << "\n----- DOUBLY LINKED LIST -----" << endl;

    cout << "1.  Insert At Beginning" << endl;
    cout << "2.  Insert At End" << endl;
    cout << "3.  Insert After Value" << endl;
    cout << "4.  Insert Before Value" << endl;

    cout << "5.  Delete From Beginning" << endl;
    cout << "6.  Delete From End" << endl;
    cout << "7.  Delete By Value" << endl;

    cout << "8.  Display" << endl;
    cout << "9.  Display Backward" << endl;
    cout << "10. Count" << endl;
    cout << "11. Search" << endl;

    cout << "12. Reverse" << endl;
    cout << "13. Sort" << endl;

    cout << "14. Merge (with second list)" << endl;
    cout << "15. Union (with second list)" << endl;
    cout << "16. Intersection (with second list)" << endl;
    cout << "17. Concatenate (with second list)" << endl;

    cout << "18. Detect Cycle" << endl;
    cout << "19. Display Cycle" << endl;

    cout << "--- Helpers ---" << endl;
    cout << "20. Fill Second List" << endl;
    cout << "21. Display Second List" << endl;
    cout << "22. Create Cycle" << endl;

    cout << "0.  Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    DoublyLinkedList list;  // main list
    DoublyLinkedList list2; // second list for merge/union/intersection/concat
    int choice, value, target, pos, n;
    printMenu();

    do {
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Insert after which value: ";
            cin >> target;
            list.insertAfterValue(target, value);
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Insert before which value: ";
            cin >> target;
            list.insertBeforeValue(target, value);
            break;

        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;

        case 8:
            list.display();
            break;
        case 9:
            list.displayBackward();
            break;
        case 10:
            cout << "Count: " << list.count() << endl;
            break;
        case 11:
            cout << "Enter value to search: ";
            cin >> value;
            pos = list.search(value);
            if (pos == -1)
                cout << value << " not found" << endl;
            else
                cout << value << " found at position " << pos << " (0 indexed)"
                     << endl;
            break;

        case 12:
            list.reverse();
            break;
        case 13:
            list.sort();
            break;

        case 14:
            list.merge(list2);
            break;
        case 15:
            list.unionList(list2);
            break;
        case 16:
            list.intersection(list2);
            break;
        case 17:
            list.concatenate(list2);
            break;

        case 18:
            if (list.detectCycle())
                cout << "Cycle detected" << endl;
            else
                cout << "No cycle" << endl;
            break;
        case 19:
            list.displayCycle();
            break;

        case 20:
            cout << "How many elements in second list: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter value: ";
                cin >> value;
                list2.insertAtEnd(value);
            }
            break;
        case 21:
            list2.display();
            break;
        case 22:
            cout << "Enter position (0 indexed) the last node should link to: ";
            cin >> pos;
            list.createCycle(pos);
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 0);

    return 0;
}