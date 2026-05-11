#pragma once

class Queue {
struct Node {
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
};

private:
    Node *head;
    Node *tail;

public:
    Queue();
    Queue(Queue &);
    ~Queue();
    bool isEmpty();
    void enqueue(int val);
    int dequeue();
    int peekFront();
    int peekRear();
    void traverse(void (*func)(int));
    void display();
    void swapFrontRear();
    void appendQueue(Queue *q2);
};
