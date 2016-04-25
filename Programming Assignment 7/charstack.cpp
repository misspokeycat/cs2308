// File Name: charstack.cpp
//
// Author: Luke D'Alfonso
// Date: 4/24/2016
// Assignment Number: 7
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// A simple character stack.
//

#include "charstack.h"
#include <cassert>

using namespace std;

/////////////
//CharStack()
//Sets stackstring to an empty string.
////////////
CharStack::CharStack() {
    stackString = "";
}

/////////////
//isEmpty()
//Returns: true if the stack has no characters in it, false otherwise
////////////
bool CharStack::isEmpty() const{
    return stackString.size() == 0;
}

/////////////
//isFull()
//Returns: true if the stack is at it's maximum size, false otherwise.
////////////
bool CharStack::isFull() const {
    return sizeof(stackString) == stackString.max_size();
}

/////////////
//pop()
//pops the top value of stackString.
//returns: the popped value
////////////
char CharStack::pop() {
    assert(!isEmpty());
    char toPop = stackString.at(0);
    stackString = stackString.substr(1, sizeof(stackString));
    return toPop;
}

/////////////
//push(char c)
//pushes the passed character to the top of the stack.
//c: the character to push on the stack
//returns: the popped value
////////////
void CharStack::push(char c) {
    assert(!isFull());
    stackString.insert(0, 1, c); //Inserts at position 0, 1 instance, of char c
}
