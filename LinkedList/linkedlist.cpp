#include "linkedlist.h"
#include <iostream>
using namespace std;

// ——— Basic Operations

// Constructor
LinkedList::LinkedList() {
    head = NULL;
    size = 0;
}

// Destructor
LinkedList::~LinkedList() {
    clear();
    head = NULL;
    size = 0;
}

int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return size == 0;
}

void LinkedList::print() {
    Node* curr = head;

    while (curr != nullptr) {
        cout << "[" << curr->value << "]";
        // Only print arrow if there is a next node
        if (curr->next != nullptr) cout << " -> ";
        
        curr = curr->next;
    }

    cout << endl;
}

// ——— Sheet Questions

void LinkedList::clear() {
    // A current to loop over
    Node *curr = head;
    while(curr != nullptr) {
        // Make the head point to the next element
        head = head->next;
        // Delete the current item from memory
        delete curr;
        // Make the current equal to head
        curr = head;
    }
}

void LinkedList::moveHeadtoEnd() {
    // Check if the list is empty or size = 1, in this case we return
    // because we cannot do anything
    if(isEmpty() || (getSize() == 1)) return;
    
    // Save the old head, and move the list's head to the next one
    Node *oldHead = head;
    head = head->next;

    // Define a current to traverse until the last item in the list
    Node *curr = oldHead;
    while(curr->next != nullptr) {
        curr = curr->next;
    }

    // Set the last item's next to the old head
    curr->next = oldHead;
    // Remove the next pointer of the old head
    // (since it used to point to 2nd item in list which is now the head)
    oldHead->next = nullptr;
}

void LinkedList::moveEndtoHead() {
    // Check if the list is empty or size = 1, in this case we return
    // because we cannot do anything
    if(isEmpty() || (getSize() == 1)) return;

    // Save the element before last in the list
    Node *curr = head;
    Node *last;
    while(curr->next->next != nullptr) {
        curr = curr->next;
    }

    // Save the last element to make it the head
    last = curr->next;
    // Remove the next pointer from the element before last
    curr->next = nullptr;

    // Make the last element point to the head
    last->next = head;
    // Make the head equal to the previous last element
    head = last;
}

LinkedList LinkedList::clone(const LinkedList &oldList) {
    // Define a new empty list
    LinkedList newList;
    // If old list is empty we return the newly made empty list
    if(oldList.head == nullptr) return newList;

    // Make a current to traverse with the old list's head
    Node *currOld = oldList.head;

    // Set the head of the new list to a new node with the value of
    // old list's head's value
    newList.head = new Node{currOld->value, nullptr};
    Node *currNew = newList.head;

    // Move the old current
    currOld = currOld->next;

    while(currOld != nullptr) {
        currNew->next = new Node{currOld->value, nullptr};
        currNew = currNew->next;
        currOld = currOld->next;
    }

    // Set the new list's size to the old list's size
    newList.size = oldList.size;
    // Return the new list
    return newList;
}

void LinkedList::insert(const int pos, const int val) {
    // Check if the list is empty and the user isn't inserting at position 0
    // or if position is negative or greater than size
    if((isEmpty() && pos != 0) || pos < 0 || pos > size) {
        cerr << "Cannot insert at pos " << pos << ", only possible at position 0\n\n";
        return;
    }

    // Create a new node with the given value
    Node *node = new Node{val, nullptr};
    
    // Inserting at head (position 0)
    if(pos == 0) {
        node->next = head;  // Point the node's next to head
        head = node;        // Make the head equal to the new node
        size++;             // Increment the size
        return;             // Return out of the function
    }

    // Traverse until the element before the inserting position
    Node *curr = head;
    for(int i = 0; i < pos-1; i++) curr = curr->next;

    // Insert node between curr and curr->next; then increment size
    node->next = curr->next;
    curr->next = node;
    size++;
}

void LinkedList::sort() {
    // If list is empty or has 1 element, then it's already sorted
    if(isEmpty() || size == 1) return;

    bool swapped;           // Tracks whether any swapes happend in a pass
    Node *curr;             // Pointer to traverse the list
    Node *last = nullptr;   // Marks the boundary of sorted position

    do {
        swapped = false;    // Reset the swap flag for this current pass
        curr = head;        // Start from head

        // Traverse until the last sorted node
        while(curr->next != last) {
            // If value is greater than the next, swap
            if(curr->value > curr->next->value) {
                swap(curr->value, curr->next->value);   // Swap data
                swapped = true;                         // Mark that a swap occured
            }
            // Move to next node
            curr = curr->next;
        }
        // After each pass, the last node is in the correct position
        last = curr;
    } while(swapped);   // Repeat until no swaps occur
}

void LinkedList::moveEventoEnd() {
    // If list is empty or has one element, then there is nothing to do
    if(isEmpty() || size == 1) return;

    // Heads and tails for 2 odd and even lists
    Node *oddHead  = nullptr, *oddTail  = nullptr;
    Node *evenHead = nullptr, *evenTail = nullptr;

    // Traverse the original list
    Node *curr = head;
    while(curr != nullptr) {
        // Save next node before breaking links
        Node *next = curr->next;
        // Disconnect current node from original list
        curr->next = nullptr;

        if(curr->value % 2 == 0) {  // Even value
            // Append to even list
            if(evenHead == nullptr) evenHead = evenTail = curr;
            else { evenTail->next = curr; evenTail = curr; }
        } else {                   // Odd value
            // Append to odd list
            if(oddHead == nullptr) oddHead = oddTail = curr;
            else { oddTail->next = curr; oddTail = curr; }
        }

        curr = next;
    }

    // Merge the 2 lists
    if(oddHead == nullptr) head = evenHead;
    else {
        head = oddHead;
        if(evenHead != nullptr) oddTail->next = evenHead;
    }
}

void LinkedList::merge(LinkedList &old) {
    // If the old list is empty, then there is nothing to do
    if(old.head == nullptr) return;

    // Current list is empty, we just point head to old list's head
    if(head == nullptr) {
        head = old.head;
        size = old.size;
        old.head = nullptr;
        old.size = 0;
        return;
    }

    // Traverse to get the last node of the list
    Node *tail = head;
    while(tail->next != nullptr) tail = tail->next;

    // Connect tail of current list with head of the old list
    tail->next = old.head;
    size += old.size;

    // Leave old list empty but not clear because we still use the nodes just not the list
    old.head = nullptr;
    old.size = 0;
}

int LinkedList::findNthfromEnd(const int pos) {
    if(pos < 0 || pos > size) {
        cerr << "Invalid position " << pos << "\n\n";
        return -1;
    }

    Node *curr = head;
    for(int i = 0; i < size-pos; i++) curr = curr->next;

    return curr->value;
}

bool LinkedList::isPalindrome() {
    // If the list is empty or has only 1 element, then there is nothing to do
    if(isEmpty() || size == 1) return true;

    // Allocate an empty array to store the values
    int *arr = new int[size];

    // Traverse the linked list and store every value in the array
    Node *curr = head;
    for(int i = 0; i < size; i++) {
        arr[i] = curr->value;
        curr = curr->next;
    }

    // Use 2 pointer approach to check from both left and right
    // If they are equal, if not we return false
    int L = 0, R = size-1;
    bool result = true;
    while(L < R) {
        // If they are not the same value, we let result = false and break out of the loop
        if(arr[L] != arr[R]) { result = false; break; };
        // Otherwise increment Left and decrement Right
        L++;
        R--;
    }
    // Delete the array from memory and return the result
    delete []arr;
    return result;
}

void LinkedList::reverse() {
    // If the list is empty or has only 1 element, then there is nothing to do
    if(isEmpty() || size == 1) return;

    Node *prev = nullptr, *curr = head, *next = nullptr;

    while(curr != nullptr) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Flip the pointer backwards
        prev = curr;        // Advance prev
        curr = next;        // Advance curr
    }

    // prev is now the last node, therefore we make it the new head
    head = prev;
}
