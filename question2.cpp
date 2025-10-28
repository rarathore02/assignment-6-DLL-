//rashika 1024030292 batch-2c22
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* last;  // keeps track of last node
public:
    CircularLinkedList() { last = nullptr; }

    // Function to insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (last == nullptr) {
            last = newNode;
            last->next = last;  // points to itself
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to display list (repeat head value at end)
    void displayWithHeadRepeat() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;  // head node
        Node* head = temp;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Repeat head node value at the end
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cout << "Output: ";
    cll.displayWithHeadRepeat();

    return 0;
}
