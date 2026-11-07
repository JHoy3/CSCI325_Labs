// Activity 2: Doubly Linked List (Starter Code)
// Complete each TODO function and add your own tests in main().

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Provided: Insert a node at the end, check difference of prev.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr) 
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
}

// Provided: Display from the first node to the last.
void displayForward(Node* head) {
    Node* curr = head;
    cout << "nullptr<-";
    while (curr != nullptr) {
        cout << curr->data << "<->";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
    
}

// TODO 1: display nodes backward using prev.
void displayBackward(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr){
        current = current->next;
    }

    cout << "nullptr<-";
    while (current != nullptr) {
        cout << current->data << "<->";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}

// TODO 2: Delete the node containing value.
// Update next, prev, and head as necessary, and release the node.
void deleteValue(Node*& head, int value) {
    Node* current = head;

    // Search for the value
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    // Value not found
    if (current == nullptr) {
        cout << "Value not found." << endl;
        return;
    }

    // Connect the previous node to the next node
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        // Deleting the first node
        head = current->next;
    }

    // Connect the next node to the previous node
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    // Delete the node
    delete current;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    //adding another to have first middle and last
    insertEnd(head, 50);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);


    //delete front
    cout << "Deleting front:" << endl; 
    deleteValue(head, 10);
    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);
    //delete middle
    cout << "Deleting middle:" << endl;
    deleteValue(head, 30);
    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);
    //delete back
    cout << "Deleting back:" << endl;
    deleteValue(head, 50);
    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);
    //delete random number not in the link
    cout << "Deleting number not in the link:" << endl;
    deleteValue(head, 13);
    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);


    return 0;
}
