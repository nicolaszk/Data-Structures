#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>

class Node{
    public:
    T data;
    Node<T>* next;
    Node(T value);
    ~Node();
};

template<typename T>

class LinkedList{
    private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
    LinkedList();
    ~LinkedList();
    bool add(T value);
    bool remove(T value);
    void print();
};

#endif