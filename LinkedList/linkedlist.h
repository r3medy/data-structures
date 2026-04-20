#pragma once
#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int value;
        Node *next;
    };
    int size;
    Node *head;
public:
    /* Constructor
     * - Time Complexity: O(1)
     */
    LinkedList();

    /* Destructor
     * - Time Complexity: O(n)
     */
    ~LinkedList();

    /* Checks if the Linked List is empty
     * - Time Complexity: O(1)
     * @return boolean
     */
    bool isEmpty();

    /* Prints the linked list
     * - Time Complexity: O(n)
     * @return void
     */
    void print();

    /* Returns the size of the linked list (# of nodes) 
     * - Time Complexity: O(1)
     * @return int
     */
    int getSize();

    // ——— Sheet Questions

    /* 1. Write a function to destroy a given LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void clear();

    /* 2. Write a function to move first node to last in a given LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void moveHeadtoEnd();

    /* 3. Write a function to move last node to front in a given LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void moveEndtoHead();

    /* 4. Write a function to clone a given LinkedList.
     * - Time Complexity: O(n)
     * @return LinkedList
     */
    static LinkedList clone(const LinkedList &oldList);

    /* 5. Write a function to insert a node in a specific position in a LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void insert(const int pos, const int val);

    /* 6. Write a function to sort a given LinkedList.
     * Uses bubble sort
     * - Time Complexity: Best case O(n) already sorted | Worst case O(n²) list is in reverse order
     * @return void
     */
    void sort();

    /* 7. Write a function to move even nodes to the end of a LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void moveEventoEnd();
    
    /* 8. Write a function to merge to given LinkedList.
     * - Time Complexity: O(n)
     * @return void
     */
    void merge(LinkedList &old);

    /* 9. Write a function to find the nth node from the end in a given LinkedList.
     * - Time Complexity: O(n)
     * @return int
     */
    int findNthfromEnd(const int pos);

    /* 10. Write a function to check if a given LinkedList is a palindrome or not. (ex. level, refer, radar)
     * - Time Complexity: O(n)
     * @return void
     */
    bool isPalindrome();

    /* 11. Write a function that transform a list to a mirror list (ex. abccba).
     * (Reversing a linked list)
     * - Time Complexity: O(n)
     * * @return void
     */
    void reverse();
};
