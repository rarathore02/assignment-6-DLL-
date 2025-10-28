#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev; // used only for doubly linked list
};
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
    Node* last;
public:
    CircularLinkedList() { last = nullptr; }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!last) {
            last = newNode;
            last->next = last;  // points to itself
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    int getSize() {
        if (!last) return 0;
        int count = 0;
        Node* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }

    void display() {
        if (!last) {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    // Insert some nodes
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cll.insertAtEnd(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cll.insertAtEnd(35);

    // Display both lists
    dll.display();
    cll.display();

    // Show their sizes
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}
