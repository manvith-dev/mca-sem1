#include <iostream>

class NetworkBufferQueue {
    int *queue;
    int bufferSize;
    int frontIdx = -1;
    int rearIdx = -1;
    int dq_size = 0;

  public:
    NetworkBufferQueue(int bufferSize) {
        this->bufferSize = bufferSize;
        queue = new int[bufferSize];
    }

    void enqueuePacket(int packetId) {
        if (isFull()) {
            std::cout << "Overflow Condition.";
            return;
        }
        if (frontIdx == -1) {
            frontIdx = 0;
        }
        rearIdx = (rearIdx + 1) % bufferSize;
        queue[rearIdx] = packetId;
        std::cout << "The packet with id : " << packetId << " was enqueued.";
        dq_size++;
        return;
    }

    void dequeuePacket() {
        if (isEmpty()) {
            std::cout << "Underflow Condition";
            return;
        }
        std::cout << "The packet with id : " << queue[frontIdx]
                  << " has been processed.";
        frontIdx = (frontIdx + 1) % bufferSize;
        dq_size--;
        if (isEmpty()) {
            frontIdx = -1;
            rearIdx = -1;
        }
        return;
    }

    bool isEmpty() { return dq_size == 0; }

    bool isFull() { return dq_size == bufferSize; }

    int displayFront() {
        if (isEmpty()) {
            std::cout << "Buffer is empty.";
            return -1;
        }
        return queue[frontIdx];
    }

    int displayRear() {
        if (isEmpty()) {
            std::cout << "Buffer is empty.";
            return -1;
        }
        return queue[rearIdx];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Underflow condition. No packets present in buffer";
            return;
        };
        for (int i = frontIdx; i < frontIdx + dq_size; i++) {
            std::cout << "[" << queue[i % bufferSize] << "] ";
        }
    }

    int size() { return dq_size; }
};

int main() {
    int bufferSize;
    std::cout << "Enter buffer capacity: ";
    std::cin >> bufferSize;

    NetworkBufferQueue nq(bufferSize);

    int choice, packetId;
    std::cout << "\n\n--- Network Packet Buffer Menu ---\n";
    std::cout << "1. Enqueue Packet\n";
    std::cout << "2. Dequeue Packet (Process Packet)\n";
    std::cout << "3. Display Front Packet\n";
    std::cout << "4. Display Rear Packet\n";
    std::cout << "5. Display All Packets\n";
    std::cout << "6. Check if Buffer is Empty\n";
    std::cout << "7. Check if Buffer is Full\n";
    std::cout << "8. Display Buffer Size\n";
    std::cout << "9. Exit\n";

    do {
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter packet ID: ";
            std::cin >> packetId;
            nq.enqueuePacket(packetId);
            break;

        case 2:
            nq.dequeuePacket();
            break;

        case 3:
            if (!nq.isEmpty()) {
                std::cout << "Front packet ID: " << nq.displayFront();
            } else {
                std::cout << "Buffer is empty.";
            }
            break;

        case 4:
            if (!nq.isEmpty()) {
                std::cout << "Rear packet ID: " << nq.displayRear();
            } else {
                std::cout << "Buffer is empty.";
            }
            break;

        case 5:
            nq.display();
            break;

        case 6:
            if (nq.isEmpty()) {
                std::cout << "Buffer is empty.";
            } else {
                std::cout << "Buffer is not empty.";
            }
            break;

        case 7:
            if (nq.isFull()) {
                std::cout << "Buffer is full.";
            } else {
                std::cout << "Buffer is not full.";
            }
            break;

        case 8:
            std::cout << "Current number of packets: " << nq.size();
            break;

        case 9:
            std::cout << "Exiting Network Packet Buffer.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}