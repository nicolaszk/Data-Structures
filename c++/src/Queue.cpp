#include "../include/Queue.h"

template <typename T>
Queue<T>::Queue() :size(0), capacity(10){
    data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue(){
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(T value){
    data[size++] = value;
    resize();
}

template <typename T>
T Queue<T>::dequeue(){
    T value = data[0];
    for(int i = 0; i < size-1; i++){
        data[i] = data[i+1];
    }
    size--;
    resize();
    return value;
}

template<typename T>
T Queue<T>::peek(){
    return data[0];
}

template <typename T>
void Queue<T>::resize(){
    if(size == capacity){
        T* newData = new T[capacity*2];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= 2;
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
int Queue<T>::getSize(){
    return size;
}
template <typename T>
int Queue<T>::getCapacity(){
    return capacity;
}
template <typename T>
void Queue<T>::print(){
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


template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<std::string>;