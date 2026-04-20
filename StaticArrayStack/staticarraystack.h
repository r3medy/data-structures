#pragma once
#include <iostream>
using namespace std;

const int CAPACITY = 8;
// Last in, First out (LIFO)

class StaticStack {
private:
    int data[CAPACITY];
    int topIdx;
public:
    /* Constructor
     * - Time Complexity: O(1)
     */
    StaticStack();

    /* Checks if the Linked List is empty
     * - Time Complexity: O(1)
     * @return boolean
     */
    bool isEmpty();
    
    /* Adds an element to the stack
     * - Time Complexity: O(1)
     * @return void
     */
    void push(const int val);
    
    /* Removes the last item in the stack
     * - Time Complexity: O(1)
     * @return int
     */
    int pop();

    // ——— Sheet Questions

    /* 1. Write a function that returns the first element entered to a stack
     * - Time Complexity: O(n)
     * @return int
     */
    int first();

    /* 2. Write a function to return the size of a stack.
     * - Time Complexity: O(1)
     * @return int
     */
    int getSize();
    
    /* 3. Write a function that returns a copy from the last element in a stack
     * - Time Complexity: O(1)
     * @return int
     */
    int peek();

    /* 4. Write a function to copy a stack to another.
     * - Time Complexity: O(1)
     * @return void
     */
    void copy(StaticStack &src);

    /* 5. Write a function to destroy a stack.
     * - Time Complexity: O(n)
     * @return void
     */
    void clear();

    /* 6. Write a function to print on the screen the contents of a stack without changing the stack.
     * - Time Complexity: O(n)
     * @return void
     */
    void print();

    /* 7. Write a function to check if an expression has balanced parentheses. Input: "{[()]}" output: TRUE.
     * - Time Complexity: O(n)
     * @return bool
     */
    bool isBalancedParenthesis(const char *input);

     /* 8. Write a function that deletes the minimum and maximum elements from stack
     * - Time Complexity: O(n)
     * @return void
     */
    void deleteMinMax();

     /* 9. Write a function that takes a stack as input and separates its elements into two different stacks: one containing
even numbers and the other containing odd numbers.
     * - Time Complexity: O(n)
     * @return void
     */
    void separateEvenOdd(StaticStack &evenStack, StaticStack &oddStack);
};
