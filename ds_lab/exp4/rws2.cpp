#include <iostream>
#include <string>
using namespace std;

// One image in the gallery
struct Image {
    string name; // file name, e.g. "beach.jpg"
    Image *prev;
    Image *next;

    Image(string n) {
        name = n;
        prev = nullptr;
        next = nullptr;
    }
};

class Gallery {
  private:
    Image *head;    // first image
    Image *tail;    // last image
    Image *current; // image currently being viewed

  public:
    Gallery() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    ~Gallery() {
        Image *cur = head;
        while (cur != nullptr) {
            Image *nextImage = cur->next;
            delete cur;
            cur = nextImage;
        }
    }

    bool isEmpty() {
        if (head == nullptr) {
            cout << "The gallery is empty\n";
            return true;
        }
        return false;
    }

    // ---------- Insertion ----------

    void insertAtFront(string name) {
        Image *img = new Image(name);
        if (head == nullptr) {
            head = tail = current = img;
        } else {
            img->next = head;
            head->prev = img;
            head = img;
        }
        cout << "Added \"" << name << "\" at the front\n";
    }

    void insertAtEnd(string name) {
        Image *img = new Image(name);
        if (head == nullptr) {
            head = tail = current = img;
        } else {
            img->prev = tail;
            tail->next = img;
            tail = img;
        }
        cout << "Added \"" << name << "\" at the end\n";
    }

    // Inserts right after the image being viewed, and moves to it
    void insertAfterCurrent(string name) {
        if (current == nullptr) {
            insertAtEnd(name);
            return;
        }
        Image *img = new Image(name);
        img->prev = current;
        img->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = img;
        } else {
            tail = img;
        }
        current->next = img;
        current = img;
        cout << "Inserted \"" << name << "\" after the current image\n";
    }

    // ---------- Deletion ----------

    // Deletes the image being viewed, then shows the next one
    // (or the previous one if it was the last image)
    void deleteCurrent() {
        if (isEmpty()) {
            return;
        }
        Image *toDelete = current;

        if (toDelete->prev != nullptr) {
            toDelete->prev->next = toDelete->next;
        } else {
            head = toDelete->next; // deleting the first image
        }

        if (toDelete->next != nullptr) {
            toDelete->next->prev = toDelete->prev;
            current = toDelete->next;
        } else {
            tail = toDelete->prev; // deleting the last image
            current = toDelete->prev;
        }

        cout << "Deleted \"" << toDelete->name << "\"\n";
        delete toDelete;
    }

    void deleteByName(string name) {
        if (isEmpty()) {
            return;
        }
        Image *cur = head;
        while (cur != nullptr && cur->name != name) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Image \"" << name << "\" not found\n";
            return;
        }

        if (cur == current) { // reuse the logic that moves the viewer
            deleteCurrent();
            return;
        }

        if (cur->prev != nullptr) {
            cur->prev->next = cur->next;
        } else {
            head = cur->next;
        }
        if (cur->next != nullptr) {
            cur->next->prev = cur->prev;
        } else {
            tail = cur->prev;
        }
        cout << "Deleted \"" << name << "\"\n";
        delete cur;
    }

    // ---------- Navigation ----------

    void viewCurrent() {
        if (isEmpty()) {
            return;
        }
        cout << "Now viewing: " << current->name << "\n";
    }

    void showNext() {
        if (isEmpty()) {
            return;
        }
        if (current->next == nullptr) {
            cout << "This is the last image\n";
            return;
        }
        current = current->next;
        viewCurrent();
    }

    void showPrevious() {
        if (isEmpty()) {
            return;
        }
        if (current->prev == nullptr) {
            cout << "This is the first image\n";
            return;
        }
        current = current->prev;
        viewCurrent();
    }

    void goToFirst() {
        if (isEmpty()) {
            return;
        }
        current = head;
        viewCurrent();
    }

    void goToLast() {
        if (isEmpty()) {
            return;
        }
        current = tail;
        viewCurrent();
    }

    // ---------- Display ----------

    // Shows every image, with [ ] around the one being viewed
    void displayAll() {
        if (isEmpty()) {
            return;
        }
        cout << "Gallery: ";
        Image *cur = head;
        while (cur != nullptr) {
            if (cur == current) {
                cout << "[" << cur->name << "]";
            } else {
                cout << cur->name;
            }
            if (cur->next != nullptr) {
                cout << " <-> ";
            }
            cur = cur->next;
        }
        cout << "\n";
    }

    int count() {
        int total = 0;
        Image *cur = head;
        while (cur != nullptr) {
            total++;
            cur = cur->next;
        }
        return total;
    }
};

// ---------- Menu ----------

void printMenu() {
    cout << "\n----- IMAGE GALLERY VIEWER -----" << endl;

    cout << "1. Next Image" << endl;
    cout << "2. Previous Image" << endl;
    cout << "3. Go To First Image" << endl;
    cout << "4. Go To Last Image" << endl;
    cout << "5. View Current Image" << endl;

    cout << "6. Add Image At Front" << endl;
    cout << "7. Add Image At End" << endl;
    cout << "8. Insert Image After Current" << endl;

    cout << "9. Delete Current Image" << endl;
    cout << "10. Delete Image By Name" << endl;

    cout << "11. Display Gallery" << endl;
    cout << "12. Count Images" << endl;

    cout << "0. Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    Gallery gallery;
    int choice;
    string name;

    printMenu();
    do {
        cin >> choice;

        switch (choice) {
        case 1:
            gallery.showNext();
            break;
        case 2:
            gallery.showPrevious();
            break;
        case 3:
            gallery.goToFirst();
            break;
        case 4:
            gallery.goToLast();
            break;
        case 5:
            gallery.viewCurrent();
            break;

        case 6:
            cout << "Enter image name (no spaces): ";
            cin >> name;
            gallery.insertAtFront(name);
            break;
        case 7:
            cout << "Enter image name (no spaces): ";
            cin >> name;
            gallery.insertAtEnd(name);
            break;
        case 8:
            cout << "Enter image name (no spaces): ";
            cin >> name;
            gallery.insertAfterCurrent(name);
            break;

        case 9:
            gallery.deleteCurrent();
            break;
        case 10:
            cout << "Enter image name to delete: ";
            cin >> name;
            gallery.deleteByName(name);
            break;

        case 11:
            gallery.displayAll();
            break;
        case 12:
            cout << "Total images: " << gallery.count() << endl;
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