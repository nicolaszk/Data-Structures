#include <stdio.h> // for printf, fprintf
#include <stddef.h> // for size_t
#include <stdlib.h> // for malloc, realloc, free
#include <stdbool.h> // for bool
#include <math.h> // for pow
#include "../include/MaxHeap.h"
#define INITIAL_CAPACITY 10
struct MaxHeap{
    int* data;
    size_t size;
    size_t capacity;
};
// function declarations
MaxHeap* createMaxHeap();
void destroyMaxHeap(MaxHeap* heap);
bool insertMaxHeap(MaxHeap* heap, int value);
void bubbleUp(MaxHeap* heap, size_t index);
size_t parent_index(size_t index);
void swap(MaxHeap* heap, size_t index1, size_t index2);
void resize(MaxHeap* heap);
int pollMaxHeap(MaxHeap* heap);
void bubbleDown(MaxHeap* heap, size_t index);
size_t left_index(size_t index);
size_t right_index(size_t index);
bool isEmptyMaxHeap(const MaxHeap* heap);
bool changeValueMaxHeap(MaxHeap* heap, int old_value, int new_value);
size_t capacityMaxHeap(const MaxHeap* heap);
size_t sizeMaxHeap(const MaxHeap* heap); 
void printMaxHeap(const MaxHeap* heap);

// function definitions
MaxHeap* createMaxHeap(){
    MaxHeap* heap = malloc(sizeof(MaxHeap));
    if(!heap){
        fprintf(stderr, "Memory allocation error");
        return NULL;
    }
    heap -> data = malloc(INITIAL_CAPACITY * sizeof(int));
    if(!heap -> data){
        fprintf(stderr, "Memory allocation error");
        free(heap);
        return NULL;
    }
    heap -> size = 0;
    heap -> capacity = INITIAL_CAPACITY;
    return heap;
}
bool removeMaxHeap(MaxHeap* heap, int value){
    if(isEmptyMaxHeap(heap)){
        fprintf(stderr, "head is empty");
        return false;
    }
    for(size_t i = 0; i < heap -> size; i++){
        if(heap -> data[i] == value){ // if found
            heap -> data[i] = heap -> data[heap -> size - 1]; // replace with last element of array
            heap -> size--; //decrement size
            bubbleDown(heap, i); // bubble down from the i-th position
            return true;
        }
    }
    return false;
}
void destroyMaxHeap(MaxHeap* heap){
    if(heap){
        if(heap -> data){
            free(heap -> data);
        }
        free(heap);
    }
    return;
}

bool insertMaxHeap(MaxHeap* heap, int value){
    if(heap -> size == heap -> capacity){
        resize(heap);
    }
    heap -> data[heap -> size] = value;
    heap -> size++;
    bubbleUp(heap, heap -> size - 1);
    return true;
    }

void bubbleUp(MaxHeap* heap, size_t index){
    size_t parent = parent_index(index);
    if(index > 0 && heap -> data[index] > heap -> data[parent]){
        swap(heap, index, parent);
        bubbleUp(heap, parent);
    }
    return;
}

size_t parent_index(size_t index){
    return (index-1) / 2;
}

void swap(MaxHeap* heap, size_t index1, size_t index2){
    int temp = heap -> data[index1];
    heap -> data[index1] = heap -> data[index2];
    heap -> data[index2] = temp;
}

void resize(MaxHeap* heap){
    if(heap -> size == heap -> capacity){
        // double capacity
        heap -> capacity *= 2;
        heap -> data = realloc(heap -> data, heap -> capacity * sizeof(int));
        // cool function i found on stackoverflow so i dont need malloc
        if(!heap -> data){
            fprintf(stderr, "Memory allocation error");
            return;
        }
    }
    if(heap -> size < heap -> capacity/4 && heap -> capacity > INITIAL_CAPACITY){
        heap -> capacity /= 2;
        heap -> data = realloc(heap -> data, heap ->capacity * sizeof(int));
        if(!heap -> data){
            fprintf(stderr, "Memory allocation error");
            return;
        }
    }
    return;
}

int pollMaxHeap(MaxHeap* heap){
    if(heap ->size == 0){
        fprintf(stderr, "heap is empty");
        return -1;
    }
    int value = heap -> data[0];
    heap -> data[0] = heap -> data[heap -> size - 1];
    heap -> size--;
    bubbleDown(heap, 0);
    return value;
}

void bubbleDown(MaxHeap* heap, size_t index){
    size_t left = left_index(index);
    size_t right = right_index(index);
    size_t largest = index;
    
    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;
    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;
        
    if (largest != index) {
        swap(heap, index, largest);
        bubbleDown(heap, largest);
    }
}

size_t left_index(size_t index){
    return 2 * index + 1;
}

size_t right_index(size_t index){
    return 2* index + 2;
}

bool isEmptyMaxHeap(const MaxHeap* heap){
    return heap -> size == 0;
}

bool changeValueMaxHeap(MaxHeap* heap, int old_value, int new_value){
    if(old_value == new_value){
        return false;
    }
    for(size_t i = 0; i < heap -> size; i++){
        if(heap -> data[i] == old_value){
            heap -> data[i] = new_value;
            if(new_value < old_value){
                bubbleDown(heap, i);
            } else {
                bubbleUp(heap, i);
            }
            return true;
        }
    }
    fprintf(stderr, "Value not found in heap");
    return false;
}

size_t capacityMaxHeap(const MaxHeap* heap){
    return heap -> capacity;
}

size_t sizeMaxHeap(const MaxHeap* heap){
    return heap -> size;
}

void printMaxHeap(const MaxHeap* heap){
    printf("-----heap-----\n");
    int level = 0;
    for(size_t i = 0; i < heap -> size; i++){
        if(i == (2 << level) - 1){ // undefined reference: pow 
            printf("\n");
            level++;
        }
        printf("%d ", heap -> data[i]);
    }
    printf("\n");
    printf("---------------\n");
}