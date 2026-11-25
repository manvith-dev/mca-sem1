#include <iostream>
#include <string>
using namespace std;

// One coach of the train
struct Coach {
    int coachNo; // unique coach number, e.g. 101
    string type; // e.g. "Engine", "AC", "Sleeper", "General", "Pantry"
    Coach *next;

    Coach(int no, string t) {
        coachNo = no;
        type = t;
        next = nullptr;
    }
};

class Train {
  private:
    Coach *head; // first coach (front of the train)

  public:
    Train() { head = nullptr; }

    bool isEmpty() {
        if (head == nullptr) {
            cout << "The train has no coaches\n";
            return true;
        }
        return false;
    }

    int totalCoaches() {
        int res = 0;
        Coach *cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            res++;
        }
        return res;
    }

    // ---------- Adding Coaches ----------

    void addAtFront(int coachNo, string type) {
        Coach *newCoach = new Coach(coachNo, type);
        if (head != nullptr) {
            newCoach->next = head;
        }
        head = newCoach;
    }

    void addAtEnd(int coachNo, string type) {
        if (head == nullptr) {
            addAtFront(coachNo, type);
            return;
        }

        Coach *cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Coach(coachNo, type);
    }

    void addAtPosition(int pos, int coachNo, string type) {
        int total = totalCoaches();
        if (pos < 1 || pos > total + 1) {
            cout << "Invalid position. Valid range is 1 to " << total + 1
                 << "\n";
            return;
        }
        if (pos == 1) {
            addAtFront(coachNo, type);
            return;
        }

        Coach *cur = head;
        for (int i = 1; i < pos - 1; i++) { // stop at coach number pos - 1
            cur = cur->next;
        }

        Coach *newCoach = new Coach(coachNo, type);
        newCoach->next = cur->next; // link to the rest first
        cur->next = newCoach;       // then link the previous coach to it
    }

    // ---------- Removing Coaches ----------

    void removeFromFront() {
        if (isEmpty()) {
            return;
        }
        Coach *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void removeFromEnd() {
        if (isEmpty()) {
            return;
        }
        if (head->next == nullptr) { // single coach
            delete head;
            head = nullptr;
            return;
        }

        Coach *cur = head;
        while (cur->next->next != nullptr) { // stop at the second-last coach
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
    }

    void removeAtPosition(int pos) {
        if (isEmpty()) {
            return;
        }
        int total = totalCoaches();
        if (pos < 1 || pos > total) {
            cout << "Invalid position. Valid range is 1 to " << total << "\n";
            return;
        }
        if (pos == 1) {
            removeFromFront();
            return;
        }

        Coach *cur = head;
        for (int i = 1; i < pos - 1; i++) { // stop at coach number pos - 1
            cur = cur->next;
        }

        Coach *toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
    }

    void removeByCoachNo(int coachNo) {
        if (isEmpty()) {
            return;
        }
        if (head->coachNo == coachNo) {
            removeFromFront();
            return;
        }

        Coach *cur = head;
        while (cur->next != nullptr && cur->next->coachNo != coachNo) {
            cur = cur->next;
        }

        if (cur->next == nullptr) {
            cout << "Coach " << coachNo << " not found\n";
        } else {
            Coach *toDelete = cur->next;
            cur->next = toDelete->next;
            delete toDelete;
        }
    }

    // ---------- Display ----------

    void display() {
        if (isEmpty()) {
            return;
        }
        Coach *cur = head;
        int pos = 1;
        while (cur != nullptr) {
            cout << "[" << pos << "] " << cur->type << "(" << cur->coachNo
                 << ") -> ";
            cur = cur->next;
            pos++;
        }
        cout << "END\n";
    }
};

// ---------- Menu ----------

void printMenu() {
    cout << "\n----- TRAIN COACH MANAGEMENT -----" << endl;

    cout << "1. Add Coach At Front" << endl;
    cout << "2. Add Coach At End" << endl;
    cout << "3. Add Coach At Position" << endl;

    cout << "4. Remove Coach From Front" << endl;
    cout << "5. Remove Coach From End" << endl;
    cout << "6. Remove Coach At Position" << endl;
    cout << "7. Remove Coach By Coach Number" << endl;

    cout << "8. Display Train" << endl;
    cout << "9. Count Coaches" << endl;

    cout << "0. Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    Train train;
    int choice, coachNo, pos;
    string type;

    printMenu();
    do {
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter coach number: ";
            cin >> coachNo;
            cout << "Enter coach type (no spaces): ";
            cin >> type;
            train.addAtFront(coachNo, type);
            break;
        case 2:
            cout << "Enter coach number: ";
            cin >> coachNo;
            cout << "Enter coach type (no spaces): ";
            cin >> type;
            train.addAtEnd(coachNo, type);
            break;
        case 3:
            cout << "Enter position (1 = front): ";
            cin >> pos;
            cout << "Enter coach number: ";
            cin >> coachNo;
            cout << "Enter coach type (no spaces): ";
            cin >> type;
            train.addAtPosition(pos, coachNo, type);
            break;

        case 4:
            train.removeFromFront();
            break;
        case 5:
            train.removeFromEnd();
            break;
        case 6:
            cout << "Enter position to remove (1 = front): ";
            cin >> pos;
            train.removeAtPosition(pos);
            break;
        case 7:
            cout << "Enter coach number to remove: ";
            cin >> coachNo;
            train.removeByCoachNo(coachNo);
            break;

        case 8:
            train.display();
            break;
        case 9:
            cout << "Total coaches: " << train.totalCoaches() << endl;
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