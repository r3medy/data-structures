#include <iostream>
#include "StaticQueue.h"
using namespace std;

int main() {
    Queue q;
    cout << (q.isEmpty() ? "Empty" : "Contains values") << endl;
    q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4); q.enqueue(5); q.enqueue(6); q.enqueue(7); q.enqueue(8);
    cout << (q.isFull() ? "Full" : "Not Full") << endl;
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.display();
    q.swapFrontRear();
    q.display();
}
