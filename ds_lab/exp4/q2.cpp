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

    void insertAtBeginning(int value) {
        Node *node = new Node(value, nullptr, head);
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
        while (cur != nullptr || cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            std::cout << "The list has no node with value" << target << "\n";
        } else {
            Node *node = new Node(value, cur, cur->next);
            cur->next = node;
        }
    }

    void insertBeforeValue(int target, int value) {
        Node *cur = head;
        while (cur != nullptr || cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            std::cout << "The list has no node with value" << target << "\n";
        } else if (head->data == target) {
            Node *node = new Node(value, nullptr, head);
            head = node;
        } else {
            cur = cur->prev;
            Node *node = new Node(value, cur, cur->next);
            cur->next = node;
        }
    }

    // ---------- 3 Types of Deletion ----------

    void deleteFromBeginning() {
        if (isEmpty()) {
            return;
        }
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void deleteFromEnd() {
        if (isEmpty()) {
            return;
        }

        if (head->next = nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur = cur->prev;
        delete cur->next;
        cur->next = nullptr;
    }

    void deleteByValue(int value) {
        Node *cur = head;

        while (cur != nullptr || cur->data != value) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            std::cout << "The list has no node with value" << value << "\n";
        } else if (head->data = value) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Node *toDelete = cur;
            cur = cur->prev;
            cur->next = cur->next->next;
            delete toDelete;
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
        while (cur->next != nullptr) {
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
        // TODO: swap prev and next of every node, then fix head
    }

    void sort() {}

    // ---------- Operations Using a Second List ----------

    void merge(DoublyLinkedList &other) {
        // TODO: merge two SORTED lists into this one
        // (or interleave, depending on what your course means by merge)
    }

    void unionList(DoublyLinkedList &other) {
        // TODO: all distinct elements from both lists (unordered_set helps)
    }

    void intersection(DoublyLinkedList &other) {
        // TODO: distinct elements present in both lists
    }

    void concatenate(DoublyLinkedList &other) {
        // TODO: attach other's head after this list's tail
        // Set other.head = NULL afterwards
    }

    // ---------- Cycle Operations ----------

    void createCycle(int pos) {
        // TODO: link the last node's next to the node at position pos
        // (test helper, so you have a cycle to detect)
    }

    bool detectCycle() {
        // TODO: Floyd's slow/fast pointers
        return false;
    }

    void displayCycle() {
        // TODO: find the cycle start, then print nodes until you return to it
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

    do {
        printMenu();
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