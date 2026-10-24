#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Linked stack operations
void push(Node*& top, char value) {
    top = new Node{value, top};
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* oldTop = top;
    char value = oldTop->data;
    top = oldTop->next;
    delete oldTop;
    return value;
}

char peek(Node* top) {
    return (top == nullptr) ? '\0' : top->data;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

// TODO 1: return 2 for * and /; 1 for + and -; 0 otherwise.
int precedence(char op) {
    // Write your code here.
    return 0; //  replace with your return
}

// TODO 2: Convert a valid infix expression to postfix.
// Assume single character operands and operators +, -, *, /.
// Expressions may contain matching parentheses, without spaces.
string infixToPostfix(string infix) {
    Node* top = nullptr;
    string postfix = "";

    // Process characters one at a time.
    // Operand: append to postfix.
    // '(': push to stack.
    // ')': pop operators until '(', then discard '('.
    // Operator: pop higher/equal precedence operators, then push.
    // At end: pop remaining operators.
    // Write your code here.

    return postfix;
}

int main() {
    string expression;
    cout << "Enter infix expression: ";
    cin >> expression;
    cout << "Postfix: " << infixToPostfix(expression) << endl;
    return 0;
}
