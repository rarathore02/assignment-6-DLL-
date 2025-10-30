#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    char data;
    Node* next;
    Node* prev;
};
Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertEnd(Node*& head, char data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
bool isPalindrome(Node* head) {
    if (head == NULL)
        return true;

    Node* left = head;
    Node* right = head;
    // Move right pointer to the last node
    while (right->next != NULL)
        right = right->next;
    // Compare from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;

    string str;
    cout << "Enter characters (string): ";
    cin >> str;

    // Insert each character into DLL
    for (char c : str)
        insertEnd(head, c);

    cout << "Doubly Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
