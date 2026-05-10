#pragma once

class Queue {
class Node {
    int entry;
    Node *next;
};

private:
    int head;
    int tail;
    int size;
    int *data;
    
public:
    Queue();
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int val);
    int dequeue();
    void traverse(void (*func)(int));
    void display();
    void swapFrontRear();
};
