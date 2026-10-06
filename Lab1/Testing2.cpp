#include <iostream>
#include<utility>


//syntax for a node
struct Node {
    int data;
    Node* next;
};

void printList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void insertFront(Node*& head, int value) {
    Node* newNode = new Node{value,head};
    head = newNode;
}

void insertEnd(Node*& head, int value) {
    Node* n = new Node{value, nullptr};


    if (head == nullptr) {
        head == n;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = n;
}

// void searchbyValue(Node*& head, int target) {
//     Node* current = head;

//     while (current != nullptr) {
//         if (current->data == target) {
//             return current;
//         }
//         current = current->next;
//     }
//     return nullptr;
// }

//delete node after current
void deleteFront(Node*& head) {
    if (head == nullptr) return;

    Node* oldhead = head;
    head = head->next;
    delete oldhead;
}

void deleteaftercurrent(Node*& head) {
    Node* current = head;
    Node* newhead = current->next;

    if (newhead != nullptr) {
        current->next = newhead->next;
        delete newhead;
    }
}

void destroyList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* oldhead = head;      
        head = head->next;
        delete oldhead;            
    }
}

int main() {

    //creation of nodes
    Node* head = new Node{50, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{10, nullptr};

    printList(head);

    insertFront(head, 100);

    printList(head);

    insertEnd(head, 500);

    printList(head);

    return 0;
}