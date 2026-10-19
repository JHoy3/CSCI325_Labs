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
    newNode->next = head;
    head = newNode;
}

// TODO 2: if exist return true; otherwise return false.
bool search(Node* head, int value) {
    bool searchresult = false;
    
    while (head != nullptr) {
        if (head->data == value){
            searchresult = true;
        }
        head = head->next;
    }

    return searchresult;  // required for your implementation.
}

// TODO 3: count and return the number of nodes.
int countNodes(Node* head) {
    int count = 0;
    
    while (head != nullptr) {
        head = head->next; 
        ++count;
    }

    return count;  // required for your implementation.
}

// TODO 4: Delete the node containing value.
// Update head when needed and release the removed node using delete.
void deleteValue(Node*& head, int value) {
    Node* temp = head;
    
    while (head != nullptr) {
        if (head->data == value) {
        head = head->next;
        delete temp;        
        }
        head = head->next;
    }
    
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
    
    //for insert front function
    insertFront(head, 100);
    cout << "After adding element to front: ";
    display(head);

    printf("\n");

    // for counting nodes function
    int count = 0;
    count = countNodes(head);
    cout << "Number of Nodes: " << count << endl;
    
    //for search function
    int value = 0;
    cout << "Enter a value to search: ";
    cin >> value;
    bool searchresult = false;
    searchresult = search(head, value);
    if (searchresult == true) {
        cout << "Found " << value << endl;
    } else {
        cout << value << " was not found" << endl;
    }



    return 0;
}
