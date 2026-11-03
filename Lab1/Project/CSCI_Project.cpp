#include <iostream>
//Next 2 are needed for file reading.
#include <fstream>
#include <string>
#include <sstream>
// just to make things easier
using namespace std;

//book object that contains the ISBN and Title
struct Book {
    string ISBN;
    string title;
};
//node structure for the BST
struct Node {
    Book book;
    Node* left;
    Node* right;
};

//insertion method
Node* insert(Node* root, Book newBook) {

    if (root == nullptr) {
        Node* newNode = new Node;

        newNode->book = newBook;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    if (newBook.ISBN < root->book.ISBN) {
        root->left = insert(root->left, newBook);
    }
    else if (newBook.ISBN > root->book.ISBN) {
        root->right = insert(root->right, newBook);
    }

    return root;
}

// used to test if the BST is created correctly
void inorderTraversal(Node* root) {

    if (root == nullptr) {
        return;
    }

    // Visit left subtree
    inorderTraversal(root->left);

    // Display current book
    cout << "ISBN: " << root->book.ISBN << endl;
    cout << "Title: " << root->book.title << endl;
    cout << "----------------------" << endl;

    // Visit right subtree
    inorderTraversal(root->right);
}

int main()
{
    //defines root
    Node* root = nullptr;

    //sets input file to testdata.txt
	ifstream inputFile("testdata.txt");
    //check to see if file exits
	if (!inputFile) {
		cout << "File not found" << endl;
	}

    //line is used to convert the data within the file to usable data
	string line;

    ///while loop that loops through the file to and collects the ISBN and Book title and converts them to objects 
    while (getline(inputFile, line)) {

        stringstream ss(line);

        Book newBook;

        getline(ss, newBook.title, ',');
        getline(ss, newBook.ISBN, ',');

        root = insert(root, newBook);
    }
    //closes the file after the BST is created
    inputFile.close();

    //call to see the tree
    inorderTraversal(root->right);

    return 0;
}