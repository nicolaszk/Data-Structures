#ifndef STACK_H // ifndef is used to prevent multiple inclusions of the same header file
#define STACK_H  

#include <iostream>

template <typename T>
class Stack{
private:
    T* data; // pointer to the array
    int size;
    int capacity;

    void resize();

public:
    Stack(); // constructor - initializes the stack with a default size of 10
    ~Stack(); // destructor - frees the memory allocated for the stack
    void push(T value); // adds a value to the top of then stack
    T pop(); // removes the element at the top of the stackand returns it
    T peek(); // returns the value at the top of the stack
    int getSize(); // returns the size of the stack
    int getCapacity(); // returns the capacity of the stack
    void print(); // prints the stack
};

#endif // ARRAYLIST_H