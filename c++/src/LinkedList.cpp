#include "../include/LinkedList.h"
#include <iostream>
template<typename T>

Node<T>::Node(T value) : data(value), next(nullptr){

}

template<typename T>
Node<T>::~Node(){
    next = nullptr;
}

template class Node<int>;
template class Node<double>;
template class Node<char>;


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0){

}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;                   
        current = nextNode;               
    }
}


template<typename T>
bool LinkedList<T>::add(T value){
    Node<T>* newNode = new Node<T>(value);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
    size++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(T value) {
    if (head == nullptr) return false; // list is empty

    // Handle head removal
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next; 
        if (head == nullptr) { // if list ends up empty
            tail = nullptr;   // update tail
        }
        temp->next = nullptr; // independently if its empty or not, not letting the old head point to the second node in the list
        delete temp;          // delete node (if line above isnt correct, will cause segfault)
        size--;
        return true;
    }

    // Search for the node to remove
    Node<T>* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = temp->next; // Unlink the node

            // Update tail if the removed node was the tail
            if (temp == tail) {
                tail = current;
            }

            temp->next = nullptr; // Disconnect the node from the list
            delete temp;          // Delete the node safely
            size--;
            return true;
        }
        current = current->next;
    }

    return false; // Value not found
}

template<typename T>
void LinkedList<T>::print(){
    Node<T>* current = head;
    while(current != nullptr){
        std::cout << "[" << current -> data << "] -> ";
        current = current -> next;
    }
    std::cout << "nullptr" << std::endl;
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;


