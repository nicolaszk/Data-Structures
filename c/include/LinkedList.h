#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stddef.h> 
typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct{
    struct Node* head;
    struct Node* tail;
    int size;
    
}LinkedList;

Node* createNode(int value);
void deleteNode(Node* node);
LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* list);
bool addToLinkedList(LinkedList* list, int value);
bool removeFromLinkedList(LinkedList* list, int value);
void printLinkedList(LinkedList* list);


#endif