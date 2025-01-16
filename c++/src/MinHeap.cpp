#include "../include/MinHeap.h"
#include <iostream>
// need to add changeValue function and remove function
template <typename T>
MinHeap<T>::MinHeap() : size(0), capacity(10){ // constructor

    data = new T[capacity];
}

template <typename T>
MinHeap<T>::~MinHeap(){ // destructor
    delete[] data;
}

template<typename T>
int MinHeap<T>::parent(int index){
    return (index - 1) / 2;
}

template<typename T>
int MinHeap<T>::leftChild(int index){
    return 2*index + 1;
}

template<typename T>
int MinHeap<T>::rightChild(int index){
    return 2*index + 2;
}

template<typename T>
int MinHeap<T>:: getSize(){
    return size;
}

template<typename T>
int MinHeap<T>:: getCapacity(){
    return capacity;
}

template<typename T>
bool MinHeap<T>::isEmpty(){
    return size == 0;
}

template<typename T>
bool MinHeap<T>::isFull(){
    return size == capacity;
}

template<typename T>
void MinHeap<T>::clear(){
    size = 0;
}


template<typename T>
void MinHeap<T>::resize(){
    if(isFull()){
        capacity *= 2;
        T* newData = new T[capacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    if(size < capacity / 4){
        capacity /= 2;
        T* newData = new T[capacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

template<typename T>
void MinHeap<T>::swap(int i, int j){
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template<typename T>
void MinHeap<T>::insert(T value){
    if(isFull()){
        resize();
    }
    data[size] = value;
    size++; 
    heapifyUp(size - 1);
}

template<typename T>
T MinHeap<T>::extractMin(){
    if(isEmpty()){
        throw std::runtime_error("Heap is empty");
    }
    T min = data[0];
    data[0] = data[size - 1];
    size--;
    heapifyDown(0);
    return min;
}

template<typename T>
void MinHeap<T>::heapifyUp(int index){
    while(index > 0 && data[parent(index)] > data[index]){ // if the parent is greater than the child, swap them
        swap(parent(index), index); // swap the parent and child
        index = parent(index); // update the index to the parent's index
    }
}

template<typename T>
void MinHeap<T>::heapifyDown(int index){
    // get left and right child, find smallest and swap with parent;
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;
    if(left < size && data[left] < data[smallest]){ // if exists and is smaller
        smallest = left;
    }
    if(right < size && data[right] < data[smallest]){// if exists and is smaller
        smallest = right;
    }
    if(smallest != index){ // if the smallest is not the parent, swap them
        swap(index, smallest); // swap the parent and smallest
        heapifyDown(smallest); // continue heapifying down 
    }
}

template<typename T>
void MinHeap<T>::printHeap(){
    int level = 0;
    for(int i = 0; i < size; i++){
        if(i == (1 << level) - 1){
            std::cout << std::endl;
            level++;
        }
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template class MinHeap<int>;
template class MinHeap<double>;
template class MinHeap<char>;
template class MinHeap<std::string>;