#include <iostream>
#include "LinkedQueue.h"
using namespace std;

Queue::Queue() {
    head = tail = nullptr;
}

Queue::Queue(Queue &src) {
    head = tail = nullptr;
    Node *curr = src.head;
    while(curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

Queue::~Queue() {
    Node *curr = head;
    while(curr != nullptr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

bool Queue::isEmpty() {
    return (head == nullptr && tail == nullptr);
}

// Add to tail
void Queue::enqueue(int value) {
    Node *node = new Node(value);
    if(isEmpty()) {
        head = tail = node;
        return;
    }
    tail->next = node;
    tail = node;
}

// Remove from head
int Queue::dequeue() {
    if(isEmpty()) return -1;
    Node *temp = head;
    int value = temp->value;
    head = head->next;
    if(head == nullptr) tail = nullptr;
    delete temp;
    return value;
}

int Queue::peekFront() {
    if(isEmpty()) return -1;
    return head->value;
}

int Queue::peekRear() {
    if(isEmpty()) return -1;
    return tail->value;
}

void Queue::traverse(void (*func)(int)) {
    Node *curr = head;
    while(curr != nullptr) {
        (*func)(curr->value);
        curr = curr->next;
    }
}

void Queue::display() {
    Node *curr = head;
    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void Queue::swapFrontRear() {
    if(isEmpty() || head == tail) return;
    int temp = head->value;
    head->value = tail->value;
    tail->value = temp;
}

void Queue::appendQueue(Queue *src) {
    if(this == src) return;
    Node *curr = src->head;
    while(curr != nullptr) {
        this->enqueue(curr->value);
        curr = curr->next;
    }
}
