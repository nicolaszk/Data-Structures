#include "../include/MaxHeap.h"
#include <iostream>
// need to add changeValue function and remove function
template <typename T>
MaxHeap<T>::MaxHeap() : size(0), capacity(10){ // constructor

    T* data = new T[capacity];
}

template <typename T>
MaxHeap<T>::~MaxHeap(){ // destructor
    delete[] data;
}

template<typename T>
int MaxHeap<T>::parent(int index){
    return (index - 1) / 2;
}

template<typename T>
int MaxHeap<T>::leftChild(int index){
    return 2*index + 1;
}

template<typename T>
int MaxHeap<T>::rightChild(int index){
    return 2*index + 2;
}

template<typename T>
int MaxHeap<T>:: getSize(){
    return size;
}

template<typename T>
int MaxHeap<T>:: getCapacity(){
    return capacity;
}

template<typename T>
bool MaxHeap<T>::isEmpty(){
    return size == 0;
}

template<typename T>
bool MaxHeap<T>::isFull(){
    return size == capacity;
}

template<typename T>
void MaxHeap<T>::clear(){
    size = 0;
}


template<typename T>
void MaxHeap<T>::resize(){
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
void MaxHeap<T>::swap(int i, int j){
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template<typename T>
void MaxHeap<T>::insert(T value){
    if(isFull()){
        resize();
    }
    data[size] = value;
    size++; 
    heapifyUp(size - 1);
}

template<typename T>
T MaxHeap<T>::extractMax(){
    if(isEmpty()){
        throw std::runtime_error("Heap is empty");
    }
    T max = data[0];
    data[0] = data[size - 1];
    size--;
    heapifyDown(0);
    return max;
}

template<typename T>
void MaxHeap<T>::heapifyUp(int index){
    while(index > 0 && data[parent(index)] < data[index]){ // if the parent is less than the child, swap them
        swap(parent(index), index); // swap the parent and child
        index = parent(index); // update the index to the parent's index
    }
}

template<typename T>
void MaxHeap<T>::heapifyDown(int index){
    // get left and right child, find largest and swap with parent;
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;
    if(left < size && data[left] > data[largest]){ // if exists and is smaller
        largest = left;
    }
    if(right < size && data[right] > data[largest]){// if exists and is smaller
        largest = right;
    }
    if(largest != index){ // if the largest is not the parent, swap them
        swap(index, largest); // swap the parent and largest
        heapifyDown(largest); // continue heapifying down 
    }
}

template<typename T>
void MaxHeap<T>::printHeap(){
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

template<typename T>
void MaxHeap<T>::changeValue(T old_value, T new_value){
    int index = 0;
    for(int i = 0; i < size; i++){
        if(data[i] == old_value){
            index = i;
            break;
        }
    }
    data[index] = new_value;
    if(new_value > data[parent(index)]){
        heapifyUp(index);
    }
    else if(new_value < data[leftChild(index)] || new_value < data[rightChild(index)]){
        heapifyDown(index);
    }
}

template class MaxHeap<int>;
template class MaxHeap<double>;
template class MaxHeap<char>;
template class MaxHeap<std::string>;