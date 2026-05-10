#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main() {
    Queue q, q2;
    q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4); q.enqueue(5); q.enqueue(6);
    q2.enqueue(10); q2.enqueue(20); q2.enqueue(30); q2.enqueue(40);

    q.display(); q2.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    q.swapFrontRear();
    q.display();
    q.appendQueue(&q2);
    q.display();
}
