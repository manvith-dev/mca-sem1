#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int v, Node *n) {
        data = v;
        next = n;
    }
};

class CircularList {
  private:
    Node *head;
    Node *tail;

    // Optional helper: walk to the last node (the one whose next is head)
    Node *getLast() {
        // TODO: return NULL if empty
        //       otherwise loop until cur->next == head
        return nullptr;
    }

  public:
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        if (head == nullptr) {
            cout << "Linked list is empty\n";
            return true;
        }
        return false;
    }

    // ---------- 4 Types of Insertion ----------

    void insertAtBeginning(int value) {
        Node *node = new Node(value, nullptr);
        if (isEmpty()) {
            head = node;
            tail = node;
            tail->next = head;
        } else {
            tail->next = node;
            node->next = head;
            head = node;
        }
    }

    void insertAtEnd(int value) {
        Node *node = new Node(value, nullptr);
        if (head == nullptr) {
            head = node;
            tail = node;
            tail->next = head;
        } else {
            tail->next = node;
            tail = node;
            node->next = head;
        }
    }

    void insertAfterValue(int target, int value) {
        if (isEmpty())
            return;
        Node *cur = head;
        do {
            if (cur->data == target) {
                Node *node = new Node(value, cur->next);
                cur->next = node;

                if (cur == tail)
                    tail = node;

                tail->next = head;
                return;
            }

            cur = cur->next;
        } while (cur != head);

        cout << "Value not found\n";
    }

    void insertBeforeValue(int target, int value) {

        Node *cur = head;

        while (cur->next->data != target) {
            cur = cur->next;
            if (cur == head) {
                cur = nullptr;
                break;
            }
        }

        if (cur == head) {
            insertAtBeginning(value);
        } else if (cur == nullptr) {
            std::cout << "The list have no element of value " << target << "\n";
        } else {
            Node *node = new Node(value, nullptr);
            cur->next = node;
            node->next = cur->next;
        }
    }

    // ---------- 3 Types of Deletion ----------

    void deleteFromBeginning() {
        if (isEmpty())
            return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteFromEnd() {
        if (isEmpty())
            return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        delete cur->next;
        tail = cur;
        cur->next = head;
    }

    void deleteByValue(int value) {
        Node *cur = head;
        do {
            if (cur->next->data = value) {
                break;
            }
            cur = cur->next;
        } while (cur != head);
        if (cur->next->data == value) {
            Node *toDelete = cur->next;
            cur->next = cur->next->next;
            delete toDelete;
        } else {
            std::cout << "The element " << value
                      << " is not present in the linked list";
        }
    }

    // ---------- Basic Operations ----------

    void display() {
        if (isEmpty())
            return;

        Node *cur = head;
        std::cout << "head -> ";

        do {
            std::cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != head);

        std::cout << " -> (back to main)\n";
    }

    int count() {
        if (isEmpty())
            return 0;

        int res = 0;
        Node *cur = head;

        do {
            res++;
            cur = cur->next;
        } while (cur != head);
        return res;
    }

    int search(int value) {
        if (isEmpty())
            return -1;

        int pos = 0;
        Node *cur = head;

        do {
            if (cur->data == value) {
                return pos;
            }
            cur = cur->next;
            pos++;
        } while (cur != head);

        return -1;
    }

    void reverse() {
        if (isEmpty())
            return;

        if (head->next == nullptr) {
            return;
        }

        Node *prev = tail;
        Node *cur = head;
        Node *next = head->next;

        do {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        } while (cur != head);

        head = prev;
        tail->next = head;
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

    void merge(CircularList &other) {
        if (this == &other)
            return;

        int n1 = count();
        int n2 = other.count();

        Node *q1 = head;
        Node *q2 = other.head;

        Node *dummy = new Node(0, nullptr);
        Node *q = dummy;

        while (n1 > 0 || n2 > 0) {
            if (n1 > 0) {
                Node *temp = q1;
                q1 = q1->next;
                n1--;

                q->next = temp;
                q = temp;
            }

            if (n2 > 0) {
                Node *temp = q2;
                q2 = q2->next;
                n2--;

                q->next = temp;
                q = temp;
            }
        }

        head = dummy->next;
        tail = q;

        if (head != nullptr)
            tail->next = head;

        other.head = nullptr;
        other.tail = nullptr;

        delete dummy;
    }

    void unionList(CircularList &other) {
        if (this == &other)
            return;

        unordered_set<int> s;

        int n1 = count();
        int n2 = other.count();

        Node *q1 = head;
        Node *q2 = other.head;

        Node *dummy = new Node(0, nullptr);
        Node *q = dummy;

        auto append = [&](Node *node) {
            if (s.insert(node->data).second) {
                q->next = node;
                q = node;
            } else {
                delete node;
            }
        };

        while (n1 > 0 || n2 > 0) {
            if (n1 > 0) {
                Node *temp = q1;
                q1 = q1->next;
                n1--;

                append(temp);
            }

            if (n2 > 0) {
                Node *temp = q2;
                q2 = q2->next;
                n2--;

                append(temp);
            }
        }

        head = dummy->next;
        tail = q;

        if (head != nullptr)
            tail->next = head;

        other.head = nullptr;
        other.tail = nullptr;

        delete dummy;
    }

    void intersection(CircularList &other) {
        if (this == &other)
            return;

        unordered_set<int> s, added;

        int n1 = count();
        int n2 = other.count();

        Node *q1 = head;
        Node *q2 = other.head;

        Node *dummy = new Node(0, nullptr);
        Node *q = dummy;

        while (n1 > 0) {
            s.insert(q1->data);

            Node *temp = q1;
            q1 = q1->next;
            n1--;

            delete temp;
        }

        while (n2 > 0) {
            Node *temp = q2;
            q2 = q2->next;
            n2--;

            if (s.count(temp->data) && added.insert(temp->data).second) {
                q->next = temp;
                q = temp;
            } else {
                delete temp;
            }
        }

        head = dummy->next;
        tail = q;

        if (head != nullptr)
            tail->next = head;

        other.head = nullptr;
        other.tail = nullptr;

        delete dummy;
    }

    void concatenate(CircularList &other) {
        if (this == &other)
            return;

        if (other.head == nullptr)
            return;

        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else {
            tail->next = other.head;
            tail = other.tail;
        }

        tail->next = head;

        other.head = nullptr;
        other.tail = nullptr;
    }

    // ---------- Circular Check ----------

    bool isCircular() {
        if (isEmpty())
            return false;
        return tail->next == head;
    }
};

// ---------- Menu ----------

void printMenu() {
    cout << "\n----- SINGLY CIRCULAR LIST -----" << endl;

    cout << "1.  Insert At Beginning" << endl;
    cout << "2.  Insert At End" << endl;
    cout << "3.  Insert After Value" << endl;
    cout << "4.  Insert Before Value" << endl;

    cout << "5.  Delete From Beginning" << endl;
    cout << "6.  Delete From End" << endl;
    cout << "7.  Delete By Value" << endl;

    cout << "8.  Display" << endl;
    cout << "9.  Count" << endl;
    cout << "10. Search" << endl;

    cout << "11. Reverse" << endl;
    cout << "12. Sort" << endl;

    cout << "13. Merge (with second list)" << endl;
    cout << "14. Union (with second list)" << endl;
    cout << "15. Intersection (with second list)" << endl;
    cout << "16. Concatenate (with second list)" << endl;

    cout << "17. Check If Circular" << endl;

    cout << "--- Helpers ---" << endl;
    cout << "18. Fill Second List" << endl;
    cout << "19. Display Second List" << endl;

    cout << "0.  Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    CircularList list;  // main list
    CircularList list2; // second list for merge/union/intersection/concat
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
            cout << "Count: " << list.count() << endl;
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            pos = list.search(value);
            if (pos == -1)
                cout << value << " not found" << endl;
            else
                cout << value << " found at position " << pos << " (0 indexed)"
                     << endl;
            break;

        case 11:
            list.reverse();
            break;
        case 12:
            list.sort();
            break;

        case 13:
            list.merge(list2);
            break;
        case 14:
            list.unionList(list2);
            break;
        case 15:
            list.intersection(list2);
            break;
        case 16:
            list.concatenate(list2);
            break;

        case 17:
            if (list.isCircular())
                cout << "The list is circular" << endl;
            else
                cout << "The list is not circular" << endl;
            break;

        case 18:
            cout << "How many elements in second list: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter value: ";
                cin >> value;
                list2.insertAtEnd(value);
            }
            break;
        case 19:
            list2.display();
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