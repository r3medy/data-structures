#include "staticarraystack.h"
#include <iostream>
using namespace std;

// ——— Basic Operations
StaticStack::StaticStack() {
    topIdx = -1;
}

bool StaticStack::isEmpty() {
    return topIdx == -1;
}

void StaticStack::push(const int val) {
    if(topIdx == CAPACITY-1) {
        cerr << "Stack is full\n\n";
        return;
    }
    data[++topIdx] = val;
}

int StaticStack::pop() {
    if(isEmpty()) {
        cerr << "Stack is empty\n\n";
        return -1;
    }
    int topValue = peek();
    topIdx--;
    return topValue;
}

// ——— Sheet Questions

int StaticStack::first() {
    return isEmpty() ? -1 : data[0];
}

int StaticStack::getSize() {
    return topIdx+1;
}

int StaticStack::peek() {
    return isEmpty() ? -1 : data[topIdx];
}

void StaticStack::copy(StaticStack &src) {
    topIdx = src.topIdx;
    for(int i = 0; i < src.topIdx+1; i++) data[i] = src.data[i];
}

void StaticStack::clear() {
    topIdx = -1;
}

void StaticStack::print() {
    for(int i = topIdx; i >= 0; i--) cout << "[" << data[i] << "]" << endl;
    cout << endl;
}

bool StaticStack::isBalancedParenthesis(const char *input) {
    StaticStack p;
    for(int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        // Opening brackets → Push into stack
        if(c == '(' || c == '[' || c == '{') p.push(c);
        // Closing brackets → Check if it matches the top
        else if(c == ')' || c == ']' || c == '}') {
            // If parenthesis stack is empty then they are not balanced
            if(p.isEmpty()) return false;

            // Get the top element
            char top = p.pop();

            // Check if the last opening matches the closing
            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')) return false;
        }
    }
    return p.isEmpty();
}

void StaticStack::deleteMinMax() {
    if(isEmpty()) return;
    
    // First we get max and min
    int max = 0, min = 0;
    for(int i = 1; i < topIdx+1; i++) {
        int value = data[i];
        if(value >= data[max]) max = i;
        if(value <= data[min]) min = i;
    }

    // Shift the elements to the left while skipping min and max
    int newData[CAPACITY], j = 0;
    for(int i = 0; i < topIdx+1; i++) {
        if(i == max || i == min) continue;
        newData[j++] = data[i];
    }
    // Copy element by element to the old array
    for(int i = 0; i < j; i++) {
        data[i] = newData[i];
    }

    // Update top index
    topIdx = j-1;
}

void StaticStack::separateEvenOdd(StaticStack &evenStack, StaticStack &oddStack) {
    if(isEmpty()) return;
    for(int i = 0; i < topIdx+1; i++) {
        int value = data[i];
        if(value % 2 == 0) evenStack.push(value);
        else oddStack.push(value);
    }
}
