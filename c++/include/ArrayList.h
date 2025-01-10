#ifndef ARRAYLIST_H // ifndef is used to prevent multiple inclusions of the same header file
#define ARRAYLIST_H  

#include <iostream>

template <typename T>
class ArrayList{
private:
    T* data; // pointer to the array
    int size;
    int capacity;

    void resize();

public:
    ArrayList(); // constructor - initializes the array with a default size of 10
    ~ArrayList(); // destructor - frees the memory allocated for the array
    void add(T value); // adds a value to the end of the array
    void remove(int index); // removes a value from the array at a given index
    T get(int index); // returns the value at a given index
    int getSize(); // returns the size of the array
    int getCapacity(); // returns the capacity of the array
    void print(); // prints the array
};

#endif // ARRAYLIST_H