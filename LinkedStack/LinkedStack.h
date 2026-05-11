#pragma once
#include <iostream>

class LinkedStack {
private:
    struct Node {
        int value;
        Node *next;

        Node(int val) : value(val), next(nullptr) {}
    };

    Node *head;

public:
    LinkedStack();
    LinkedStack(const LinkedStack &src);
    ~LinkedStack();

    void push(int val);
    int pop();
    int peek();
    bool isEmpty();
    void traverse(void (*func)(int));
    void display();
};

// LIFO
