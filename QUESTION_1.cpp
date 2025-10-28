//rashika 1024030292 batch - 2c22


#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }
 void insertAtBeginning(int data) {
        Node* newNode = new Node{data, head, nullptr};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << "Inserted " << data << " at the beginning.\n";
    }
void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << data << " as the first node.\n";
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << data << " at the end.\n";
    }
void insertBefore(int key, int data) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == key) {
            insertAtBeginning(data);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node{data, temp, temp->prev};
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "Inserted " << data << " before " << key << ".\n";
    }
// Insert after a specific node
    void insertAfter(int key, int data) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node{data, temp->next, temp};
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted " << data << " after " << key << ".\n";
    }
// Delete a specific node
    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp == head)
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete temp;
        cout << "Deleted node " << key << ".\n";
    }
 // Search for a node
    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }
    // Display list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
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

    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "Inserted " << data << " at the beginning.\n";
    }
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Inserted " << data << " at the end.\n";
    }
    void insertAfter(int key, int data) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;
        do {
            if (temp->data == key) {
                Node* newNode = new Node{data, temp->next, nullptr};
                temp->next = newNode;
                if (temp == last)
                    last = newNode;
                cout << "Inserted " << data << " after " << key << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }
    void deleteNode(int key) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;
        Node* prev = last;
        do {
            if (temp->data == key) {
                if (temp == last && temp->next == last) {
                    last = nullptr;
                } else {
                    prev->next = temp->next;
                    if (temp == last)
                        last = prev;
                }
                delete temp;
                cout << "Deleted node " << key << ".\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }
    void searchNode(int key) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);
        cout << "Node " << key << " not found.\n";
    }
    void display() {
        if (!last) {
            cout << "List is empty.\n";
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
    int choice, subchoice, data, key;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\nEnter operation: ";
        cin >> subchoice;

        switch (choice) {
        case 1: // Doubly Linked List
            if (subchoice == 1) {
                cout << "Enter data: ";
                cin >> data;
                cout << "1. At Beginning\n2. At End\n3. Before Node\n4. After Node\n";
                int opt; cin >> opt;
                if (opt == 1) dll.insertAtBeginning(data);
                else if (opt == 2) dll.insertAtEnd(data);
                else if (opt == 3) { cout << "Enter key: "; cin >> key; dll.insertBefore(key, data); }
                else if (opt == 4) { cout << "Enter key: "; cin >> key; dll.insertAfter(key, data); }
            } else if (subchoice == 2) {
                cout << "Enter key to delete: "; cin >> key; dll.deleteNode(key);
            } else if (subchoice == 3) {
                cout << "Enter key to search: "; cin >> key; dll.searchNode(key);
            } else if (subchoice == 4) {
                dll.display();
            }
            break;

        case 2: // Circular Linked List
            if (subchoice == 1) {
                cout << "Enter data: ";
                cin >> data;
                cout << "1. At Beginning\n2. At End\n3. After Node\n";
                int opt; cin >> opt;
                if (opt == 1) cll.insertAtBeginning(data);
                else if (opt == 2) cll.insertAtEnd(data);
                else if (opt == 3) { cout << "Enter key: "; cin >> key; cll.insertAfter(key, data); }
            } else if (subchoice == 2) {
                cout << "Enter key to delete: "; cin >> key; cll.deleteNode(key);
            } else if (subchoice == 3) {
                cout << "Enter key to search: "; cin >> key; cll.searchNode(key);
            } else if (subchoice == 4) {
                cll.display();
            }
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
