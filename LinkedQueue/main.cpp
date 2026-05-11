#include <iostream>
#include "LinkedQueue.h"
using namespace std;

// 1. Write a function that returns the first element entered to a queue.
int firstElement(Queue);
// 2. Write a function to return the size of a queue.
int queueSize(Queue);
// 3. Write a function that returns a copy from the last element in a queue.
int lastElement(Queue);
// 4. Write a function to copy a queue to another.
void mergeQueues(Queue &, Queue &);
// 5. Write a function to destroy a queue.
void destroyQueue(Queue &);
// 6. Write a function to print on the screen the contents of a queue without changing the queue.
void printQueue(const Queue);
// 8. Write a function that deletes the minimum and maximum elements from queue.
void deleteMinMax(Queue &);
// 9. Write a function that takes a queue as input and separates its elements into two different queues: one containing even numbers and the other containing odd numbers.
void queueEvenOdd(Queue &, Queue &, Queue &);

int main() {
    Queue queue, q2;
    queue.enqueue(7); queue.enqueue(2); queue.enqueue(11); queue.enqueue(67); queue.enqueue(25); queue.enqueue(10); queue.enqueue(101); queue.enqueue(49);
    q2.enqueue(1);
    q2.enqueue(72);
    q2.enqueue(3);

    cout << "First Element: " << firstElement(queue) << endl;
    cout << "Last Element: " << lastElement(queue) << endl;
    cout << "Element Count: " << queueSize(queue) << endl;

}

int firstElement(Queue queue) {
    return queue.peekFront();
}

int counter = 0;
void incrementCounter(int) { counter+=1; }
int queueSize(Queue queue) {
    queue.traverse(incrementCounter);
    return counter;
}

int lastElement(Queue queue) {
    return queue.peekRear();
}

void mergeQueues(Queue &src, Queue &dist) {
    while(!src.isEmpty()) {
        dist.enqueue(src.dequeue());
    }
}

void destroyQueue(Queue &queue) {
    while(!queue.isEmpty()) {
        queue.dequeue();
    }
}

void printQueue(Queue queue) {
    Queue copy(queue);
    while(!copy.isEmpty()) {
        cout << copy.dequeue() << " ";
    }
    cout << "\n";
}

void deleteMinMax(Queue &queue) {
    Queue copy(queue);
    int min, max;
    bool isFirst = true;
    
    while(!copy.isEmpty()) { // Find max and min
        int value = copy.dequeue();
        if(isFirst) { min = value; max = value; isFirst = false; }
        else if(value >= max) max = value;
        else if(value <= min) min = value;
    }

    Queue temp;
    while(!queue.isEmpty()) { // Skip max and min
        int value = queue.dequeue();
        if(value == max || value == min) continue;
        temp.enqueue(value);
    }

    while(!temp.isEmpty()) { // Restore to original stack
        queue.enqueue(temp.dequeue());
    }
}

void queueEvenOdd(Queue &queue, Queue &even, Queue &odd) {
    Queue copy(queue);
    while(!copy.isEmpty()) {
        int value = copy.dequeue();
        if(value % 2 == 0) even.enqueue(value);
        else odd.enqueue(value);
    }
}

