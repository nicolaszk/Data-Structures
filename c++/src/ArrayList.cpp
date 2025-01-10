#include "ArrayList.h"

//this arraylist is initialized with a default capacity of 10, doubles when full, halves when less than 25% full
//capacity is never less than 10

template <typename T>
ArrayList<T>::ArrayList() : size(0), capacity(10){ // constructor

    data = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList(){ // destructor
    delete[] data;
}

template <typename T>
void ArrayList<T>::resize(){
    if(size == capacity){
        capacity *= 2;
        T* new_data = new T[capacity];
        for(int i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    if(size < capacity / 4 && capacity > 10){
        capacity /= 2;
        T* new_data = new T[capacity];
        for(int i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
}

template<typename T>
void ArrayList<T>::add(T value){
    data[size++] = value;
    resize();
}

template<typename T>
void ArrayList<T>::remove(int index){
    if(index < 0 || index > size-1){
        throw std::out_of_range("Invalid index");
}
for(int i = index; i < size-1; i++){
	data[i] = data[i+1];
}
    size--;
    resize();
}

template<typename T>
T ArrayList<T>::get(int index){
    if(index < 0 || index > size-1){
        throw std::out_of_range("Invalid index");
    }
    return data[index];
}

template<typename T> 
int ArrayList<T>::getSize(){
    return size;
}

template<typename T>
int ArrayList<T>::getCapacity(){
    return capacity;
}

template<typename T>
void ArrayList<T>::print(){
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

template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<char>;
template class ArrayList<std::string>;