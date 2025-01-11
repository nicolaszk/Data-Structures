#include "../include/Stack.h"

template <typename T>
Stack<T>::Stack() :size(0), capacity(10){
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack(){
    delete[] data;
}

template <typename T>
void Stack<T>::push(T value){
    data[size++] = value;
    resize();
}

template <typename T>
T Stack<T>::pop(){
    T value = data[--size];
    resize();
    return value;
}

template <typename T> 
T Stack<T>::peek(){
    return data[size-1];
}

template <typename T>
void Stack<T>::resize(){
    if(size == capacity){
        T* newData = new T[capacity*2];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= 2;
        return;
    }
    if(size < capacity/4 && capacity > 10){
        T* newData = new T[capacity/2];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity /= 2;
    } 
}

template <typename T>
int Stack<T>::getSize(){
    return size;
}
template <typename T>
int Stack<T>::getCapacity(){
    return capacity;
}

template <typename T>
void Stack<T>::print(){
    std::cout << "[";
    for(int i = 0; i < size; i++){
        if(i != size-1){
            std::cout << data[i] << ", ";
        }
        else{
            std::cout << data[i];
        }
    }
    std::cout << "]" << std::endl;
}

template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<std::string>;