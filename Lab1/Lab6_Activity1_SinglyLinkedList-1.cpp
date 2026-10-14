// Activity 1: Singly Linked List (Starter Code)
// Complete each TODO func and add your own tests in main().

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Provided: Insert a node at the end.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
}

// Provided: Display the list from beginning to end.
void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// TODO 1: insert a new node at the beginning of the list.
void insertFront(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    Node* current = head;


    if (current == head) {
        current->next = head;
        head = newNode;
        return;
    }


}

// TODO 2: if exist return true; otherwise return false.
bool search(Node* head, int value) {
    bool searchresult = false;


    return searchresult;  // required for your implementation.
}

// TODO 3: count and return the number of nodes.
int countNodes(Node* head) {
    return 0;  // required for your implementation.
}

// TODO 4: Delete the node containing value.
// Update head when needed and release the removed node using delete.
void deleteValue(Node*& head, int value) {
}

int main() {
    Node* head = nullptr;
    //already provided insertEnd()
    insertEnd(head, 10); 
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    //already provided display()
    cout << "Original list: ";
    display(head);

    printf("\n");

    insertFront(head, 100);
    cout << "After adding element to front: ";
    display(head);

    // see task guidelines from Activity 1.

    return 0;
}
