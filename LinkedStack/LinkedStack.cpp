#include <iostream>
#include "LinkedStack.h"

using namespace std;

LinkedStack::LinkedStack() {
    head = nullptr;
}

LinkedStack::LinkedStack(const LinkedStack &src) {
    head = nullptr;
    Node *curr = src.head;
    LinkedStack temp;
    while(curr != nullptr) {
        temp.push(curr->value);
        curr = curr->next;
    }
    while(!temp.isEmpty()) {
        push(temp.pop());
    }
}

LinkedStack::~LinkedStack() {
    Node *curr = head;
    while(curr != nullptr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedStack::push(int val) {
    Node *node = new Node(val);
    Node *temp = head;

    node->next = temp;
    head = node;
}

int LinkedStack::pop() {
    if(isEmpty()) return -1; 
    Node *temp = head;
    int val = temp->value;
    head = head->next;
    delete temp;
    return val;
}

int LinkedStack::peek() {
    if(isEmpty()) return -1;
    return head->value;
}

bool LinkedStack::isEmpty() {
    return head == nullptr;
}

void LinkedStack::traverse(void (*func)(int)) {
    Node *curr = head;
    while(curr != nullptr) {
        (*func)(curr->value);
        curr = curr->next;
    }
}

void LinkedStack::display() {
    Node *curr = head;
    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << "\n";
}
