#include "../include/LinkedList.h"
#include <iostream>
template<typename T>

Node<T>::Node(T value) : data(value), next(nullptr){

}

template<typename T>
Node<T>::~Node(){
    delete next;
}

template class Node<int>;
template class Node<double>;
template class Node<char>;


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0){

}

template<typename T>
LinkedList<T>::~LinkedList(){
    delete head;
    delete tail;
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
    if (head == nullptr) return false; // List is empty

    // Handle head removal
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next; // Move head to the next node
        if (head == nullptr) {
            tail = nullptr; // If head is now nullptr, the list is empty, so update tail
        }
        delete temp; // Free the memory of the removed node
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

            delete temp; // Free the memory of the removed node
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


