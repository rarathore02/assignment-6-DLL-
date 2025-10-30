#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    // Traverse the list
    while (temp != NULL && temp != head)
        temp = temp->next;

    // If we reach back to head, it’s circular
    return (temp == head);
}

// Main function
int main() {
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL; // Normal linked list (not circular)

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    // Now make it circular for testing
    third->next = head;

    if (isCircular(head))
        cout << "After connecting last node to head, the list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}
