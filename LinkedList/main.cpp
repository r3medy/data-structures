#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main() {
    LinkedList list, list2;
    list.insert(0, 1); list.insert(1, 7); list.insert(2, 5);

    list2.insert(0, 0); list2.insert(1, 2); list2.insert(2, 3);

    list.merge(list2);
    cout << "Before sorting \n";
    list.print();
    list.sort();
    cout << "\nAfter sorting \n";
    list.print();
    return 0;
}
