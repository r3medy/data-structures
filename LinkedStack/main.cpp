#include <iostream>
#include "LinkedStack.h"
using namespace std;

// 1. Write a function that returns the first element entered to a stack.
int firstElement(LinkedStack);
// 2. Write a function to return the size of a stack.
int stackSize(LinkedStack);
// 3. Write a function that returns a copy from the last element in a stack.
int lastElement(LinkedStack);
// 4. Write a function to copy a stack to another.
void mergeStacks(LinkedStack &, LinkedStack &);
// 5. Write a function to destroy a stack.
void destroyStack(LinkedStack &);
// 6. Write a function to print on the screen the contents of a stack without changing the stack.
void printStack(const LinkedStack);
// 7. Write a function to check if an expression has balanced parentheses. Input: "{[()]}" output: TRUE.
bool isValidParentheses(char*);
// 8. Write a function that deletes the minimum and maximum elements from stack.
void deleteMinMax(LinkedStack &);
// 9. Write a function that takes a stack as input and separates its elements into two different stacks: one containing even numbers and the other containing odd numbers.
void stackEvenOdd(LinkedStack &, LinkedStack &, LinkedStack &);

int main() {
    LinkedStack ls, even, odd;
    ls.push(7); ls.push(2); ls.push(5); ls.push(11); ls.push(8); ls.push(24); ls.push(67); ls.push(101);

    cout << "First Element: " << firstElement(ls) << endl;
    cout << "Stack Size: " << stackSize(ls) << endl;
    cout << "Last Element: " << lastElement(ls) << endl;
    printStack(ls);
    char s[] = "([{})]";
    cout << "Parentheses valid? ([{})]: " << (isValidParentheses(s) ? "Yes" : "No") << endl;
    cout << "---------------------" << endl;
    stackEvenOdd(ls, even, odd);
    cout << "Original: "; ls.display();
    cout << "Even: "; even.display();
    cout << "Odd: "; odd.display();
    return 0;
}

int firstElement(LinkedStack stack) {
    LinkedStack newStack(stack);
    int lastValue;
    while(!newStack.isEmpty()) lastValue = newStack.pop();
    return lastValue;
}

int counter = 0;
void increment(int) { counter+=1;}
int stackSize(LinkedStack stack) {
    stack.traverse(increment);
    return counter;
}

int lastElement(LinkedStack stack) {
    return stack.peek();
}

void mergeStacks(LinkedStack &src, LinkedStack &dist) {
    LinkedStack temp;
    LinkedStack copy(src);
    while(!copy.isEmpty()) temp.push(copy.pop());
    while(!temp.isEmpty()) dist.push(temp.pop());
}

void destroyStack(LinkedStack &stack) {
    while(!stack.isEmpty()) stack.pop();
}

void printStack(const LinkedStack stack) {
    LinkedStack copy(stack);
    LinkedStack temp;
    while(!copy.isEmpty()) temp.push(copy.pop());
    while(!temp.isEmpty()) cout << temp.pop() << " ";
    cout << "\n";
}

bool isValidParentheses(char *str) {
    int i = 0;
    LinkedStack parentheses;
    while(str[i] != '\0') {
        char curr = str[i];
        if(curr == '[' || curr == '{' || curr == '(') parentheses.push(curr);
        else if(curr == ']' || curr == ')' || curr == '}') {
            if(parentheses.isEmpty()) return false;
            char last = parentheses.peek();
            if((last == '[' && curr == ']') ||
               (last == '{' && curr == '}') ||
               (last == '(' && curr == ')')) parentheses.pop();
            else return false;
        }
        i++;
    }
    return parentheses.isEmpty();
}

void deleteMinMax(LinkedStack &stack) {
    int min, max;
    bool isFirst = true;
    LinkedStack temp; // To Find min and max
    while(!stack.isEmpty()) {
        int value = stack.pop();
        if(isFirst) { min = max = value; isFirst = false; }
        else if(value >= max) max = value;
        else if(value <= min) min = value;
        temp.push(value);
    }

    LinkedStack skippingMaxMin; // Reverse order without max and min
    while(!temp.isEmpty()) {
        int value = temp.pop();
        if(value == min || value == max) continue;
        skippingMaxMin.push(value);
    }

    while(!skippingMaxMin.isEmpty()) { // Restore order
        stack.push(skippingMaxMin.pop());
    }
}

void stackEvenOdd(LinkedStack &src, LinkedStack &even, LinkedStack &odd) {
    LinkedStack copy(src);
    while(!copy.isEmpty()) {
        int value = copy.pop();
        if(value % 2 == 0) even.push(value);
        else odd.push(value);
    }
}

