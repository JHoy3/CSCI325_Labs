#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// insert new value .
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        // Todo: create and return a new node with value.
        Node* newNode = new Node(value);
        return newNode;
    }

    if (value < root->data) {
        // TODO: insert into the left subtree
        root->left = insert(root->left, value);
    } else if (value > root->data){
        // TODO: Insert into the right subtree
        root->right = insert(root->right, value);
    }

    return root;
}

// return the matching node or nullptr if key isn't in BST.
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    //key is too small recurse again left
    if (key < root->data) {
        return search(root->left, key);
    } else {
        // TODO: Search the right subtree
        //key is too large recurse again right
        return search(root->right, key);
    }
}

// Inorder expected result is : 20 30 40 50 60 65 70 80 
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    //visit left
    inorderTraversal(root->left);
    // display
    cout << root->data << " ";
    //visit right
    inorderTraversal(root->right);
// Inorder: Left -> Root -> Right
}

int main(){
    vector<int> values = {50, 30, 70, 20, 40, 60, 80, 65};
    Node* root = nullptr;
    //insertion
    for (int value : values){
        root = insert(root, value);
    }
        //traversal
    cout << "BST In-Order Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;
    //search
    int targets[] = {40, 55};
    for (int target : targets) {
        Node* result = search(root, target);
        cout << "Search for " << target << ": ";
        cout << (result != nullptr ? "Found" : "Not found") << endl;
    }

    return 0;
}


