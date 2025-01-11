#ifndef QUEUE_H // ifndef is used to prevent multiple inclusions of the same header file
#define QUEUE_H  

#include <iostream>

template <typename T>
class Queue{
private:
    T* data; // pointer to the array
    int size;
    int capacity;

    void resize();

public:
    Queue(); // constructor - initializes the queue with a default size of 10
    ~Queue(); // destructor - frees the memory allocated for the queue
    void enqueue(T value); // adds a value to the back of the queue
    T dequeue(); // removes the element at the front of the queue
    T peek(); // returns the value at the front of the queue
    int getSize(); // returns the size of the queue
    int getCapacity(); // returns the capacity of the queue
    void print(); // prints the queue
};

#endif // QUEUE_H