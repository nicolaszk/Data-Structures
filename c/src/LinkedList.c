#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

//node methods first

Node* createNode(int value){
    Node* node = malloc(sizeof(Node));
    if(!node){
        printf("Error creating node\n");
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void deleteNode(Node* node){
    if(node){
        free(node);
    }
}

// linked list methods next

LinkedList* createLinkedList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    if(!list){
        printf("Error creating linked list\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void deleteLinkedList(LinkedList* list){
    if(list){
        Node* current = list->head;
        while(current){
            Node* next = current-> next;
            free(current);
            current = next;
        }// deletes all nodes until current is null
        free(list);
    }

}

bool addToLinkedList(LinkedList* list, int value){
if(!list){
    printf("list does not exist\n");
    return false;
}
Node* node = createNode(value);
if(!node){
    printf("Error creating node\n");
    return false;
}
// first case, list is empty
if(list->head == NULL){
    list -> head = node;
    list -> tail = node;
    list->size++;
    return true;
}
//second case, list is not empty, add to the end - O(1)
list->tail->next = node;
list->tail = node;
list->size++;
return true;
}

bool removeFromLinkedList(LinkedList* list, int value){
    if(!list){
        printf("list does not exist\n");
        return false;
    }
    if(list->head->value == value){
        //first case, remove head
        Node* temp = list -> head;
        list -> head = list -> head -> next;
        //if there was only one node, set tail to null
        if(list->head == NULL){
            list->tail = NULL;
        }
        free(temp);
        list->size--;
        return true;
    }
    Node* current = list->head;
    while(current->next){
        if(current->next->value == value){
            // found node to remove
           Node* temp = current -> next; // temp node to free it from memory
           current -> next = current -> next -> next; // skip over node to remove
           if(temp == list -> tail){ // if node to remove is tail, set tail to current
            list -> tail = current;
           }
            free(temp);
            list->size--;
            return true;
        }
        current = current -> next; // iterate through list
    }
    return false;
}

void printLinkedList(LinkedList* list){
    if(!list){
        printf("list does not exist\n");
        return;
    }
    Node* current = list->head;
    while(current){
        if(current == list -> tail){
            printf("[%d] -> NULL\n", current->value);
        }
        else{
            printf("[%d] -> ", current->value);
        }
        current = current->next;
    }
}