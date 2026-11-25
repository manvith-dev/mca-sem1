#include <iostream>
#include <string>
using namespace std;

// One song in the playlist
struct Song {
    string title;
    Song *next;

    Song(string t) {
        title = t;
        next = nullptr;
    }
};

class Playlist {
  private:
    Song *tail;    // last song; tail->next is always the first song
    Song *current; // song currently playing

  public:
    Playlist() {
        tail = nullptr;
        current = nullptr;
    }

    ~Playlist() {
        if (tail == nullptr)
            return;
        Song *cur = tail->next; // first song
        tail->next = nullptr;   // break the loop so we can free safely
        while (cur != nullptr) {
            Song *nextSong = cur->next;
            delete cur;
            cur = nextSong;
        }
    }

    bool isEmpty() {
        if (tail == nullptr) {
            cout << "The playlist is empty\n";
            return true;
        }
        return false;
    }

    // ---------- Adding / Removing Songs ----------

    void addSong(string title) {
        Song *song = new Song(title);
        if (tail == nullptr) {
            song->next = song; // single song points to itself
            tail = song;
            current = song;
        } else {
            song->next = tail->next; // new last song points to the first
            tail->next = song;
            tail = song;
        }
        cout << "Added \"" << title << "\"\n";
    }

    void removeSong(string title) {
        if (isEmpty()) {
            return;
        }

        Song *prev = tail;
        Song *cur = tail->next; // first song
        do {
            if (cur->title == title) {
                break;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != tail->next);

        if (cur->title != title) {
            cout << "Song \"" << title << "\" not found\n";
            return;
        }

        if (cur == cur->next) { // only song in the playlist
            tail = nullptr;
            current = nullptr;
        } else {
            prev->next = cur->next;
            if (cur == tail) {
                tail = prev;
            }
            if (cur == current) {
                current = cur->next; // move on to the next song
            }
        }
        cout << "Removed \"" << title << "\"\n";
        delete cur;
    }

    // ---------- Playback ----------

    void playCurrent() {
        if (isEmpty()) {
            return;
        }
        cout << "Now playing: " << current->title << "\n";
    }

    // Moves to the next song; after the last song it wraps to the first
    void playNext() {
        if (isEmpty()) {
            return;
        }
        current = current->next;
        if (current == tail->next) {
            cout << "(End of playlist, looping back to the first song)\n";
        }
        playCurrent();
    }

    // Simulates letting the playlist run for n songs
    void autoPlay(int n) {
        if (isEmpty()) {
            return;
        }
        for (int i = 0; i < n; i++) {
            playNext();
        }
    }

    void restart() {
        if (isEmpty()) {
            return;
        }
        current = tail->next;
        playCurrent();
    }

    // ---------- Display ----------

    // Shows the playlist, with [ ] around the song that is playing
    void display() {
        if (isEmpty()) {
            return;
        }
        Song *cur = tail->next; // first song
        do {
            if (cur == current) {
                cout << "[" << cur->title << "]";
            } else {
                cout << cur->title;
            }
            cout << " -> ";
            cur = cur->next;
        } while (cur != tail->next);
        cout << "(back to " << tail->next->title << ")\n";
    }

    int count() {
        if (tail == nullptr) {
            return 0;
        }
        int total = 0;
        Song *cur = tail->next;
        do {
            total++;
            cur = cur->next;
        } while (cur != tail->next);
        return total;
    }
};

// ---------- Menu ----------

void printMenu() {
    cout << "\n----- MUSIC PLAYLIST LOOP -----" << endl;

    cout << "1. Add Song" << endl;
    cout << "2. Remove Song" << endl;

    cout << "3. Play Next Song" << endl;
    cout << "4. Auto Play (next N songs)" << endl;
    cout << "5. Restart From First Song" << endl;
    cout << "6. Show Current Song" << endl;

    cout << "7. Display Playlist" << endl;
    cout << "8. Count Songs" << endl;

    cout << "0. Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    Playlist playlist;
    int choice, n;
    string title;
    printMenu();

    do {
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song title (no spaces): ";
            cin >> title;
            playlist.addSong(title);
            break;
        case 2:
            cout << "Enter song title to remove: ";
            cin >> title;
            playlist.removeSong(title);
            break;

        case 3:
            playlist.playNext();
            break;
        case 4:
            cout << "How many songs to play: ";
            cin >> n;
            playlist.autoPlay(n);
            break;
        case 5:
            playlist.restart();
            break;
        case 6:
            playlist.playCurrent();
            break;

        case 7:
            playlist.display();
            break;
        case 8:
            cout << "Total songs: " << playlist.count() << endl;
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