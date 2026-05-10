#include <iostream>
#include "LinkedStack.h"
using namespace std;

int i = 1;
void traverseTest(int value) {
    cout << "[" << i << "] - " << value << endl;
    i+=1;
}

int main() { 
    LinkedStack l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.display();
    l.traverse(traverseTest);
}
