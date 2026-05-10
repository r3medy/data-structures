#include <iostream>
#include "StaticQueue.h"
using namespace std;

const int CAPACITY = 8;

Queue::Queue() {
    head = 0;
    tail = -1;
    size = 0;
    data = new int[CAPACITY];
}
Queue::~Queue() {
    head = 0;
    tail = -1;
    delete []data;
    size = 0;
}

bool Queue::isEmpty() {
    return size == 0;
}

bool Queue::isFull() {
    return size == CAPACITY;
}

void Queue::enqueue(int value) {
    if(isFull()) return;
    tail = (tail+1) % CAPACITY;
    data[tail] = value;
    size+=1;
}

int Queue::dequeue() {
    if(isEmpty()) return -1;
    int value = data[head];
    head = (head+1) % CAPACITY;
    size-=1;
    return value;
}

void Queue::traverse(void (*func)(int)) {
    for(int i = 0; i < size; i++) {
        int idx = (head+i) % CAPACITY;
        (*func)(data[idx]);
    }
}

void Queue::display() {
    for(int i = 0; i < size; i++) {
        int idx = (head+i) % CAPACITY;
        cout << data[idx] << " ";
    }
    cout << "\n";
}

void Queue::swapFrontRear() {
    int temp = data[head];
    data[head] = data[tail];
    data[tail] = temp;
}
