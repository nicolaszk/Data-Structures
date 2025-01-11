#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memmove and memcpy
#include "../include/IntegerArrayList.h"

#define DEFAULT_CAPACITY 10
IntegerArrayList* createIntegerArrayList(){
    IntegerArrayList* list = malloc(sizeof(IntegerArrayList));
if(!list){
    fprintf(stderr, "Memory Allocation Error");
    exit(EXIT_FAILURE);
}
list -> size = 0;
list -> capacity = DEFAULT_CAPACITY;
list -> data = malloc(DEFAULT_CAPACITY * sizeof(int)); // allocates memory for the array
if(!list -> data){
    fprintf(stderr, "Memory Allocation Error");
    exit(EXIT_FAILURE);
}
return list;
}

void destroyIntegerArrayList(IntegerArrayList* list){
    if(list){ // checks if the list is not null
        free(list -> data);
        free(list);
    }
}

void addToIntegerArrayList(IntegerArrayList* list, int value){
    list->data[list->size++] = value;
    resizeIntegerArrayList(list);
}

void resizeIntegerArrayList(IntegerArrayList* list){
    if(list->size == list->capacity){
        int* newData = malloc(list-> capacity * 2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        memcpy(newData, list->data, list->size * sizeof(int)); // copies the data from the old array to the new array
        free(list->data); // frees the old array
        list->data = newData; // assigns the new array to the list
        list->capacity *= 2; // doubles the capacity
    }
    if(list->size < list->capacity/4 && list->capacity > DEFAULT_CAPACITY){
        int* newData = malloc(list->capacity/2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        memcpy(newData, list->data, list->size * sizeof(int)); // copies the data from the old array to the new array
        free(list->data); // frees the old array
        list->data = newData; // assigns the new array to the list
        list->capacity /= 2; // halves the capacity
    }
}

void removeFromIntegerArrayList(IntegerArrayList* list, size_t index){
    if(index < 0 || index >= list->size){
        fprintf(stderr, "Index Out of Bounds");
        return;
    }
    // memmove is usually faster than a for loop for moving elements
    memmove(&list->data[index],  // destination address
            &list->data[index + 1], // source address
            (list->size - index - 1) * sizeof(int) // number of bytes to be moved
            ); // shifts the elements to the left, starting from the index
    // what the for loop would look like:
    // for(int i = index; i < list->size - 1; i++{
    //     list->data[i] = list->data[i + 1]; 
    // }
    list->size--;
    resizeIntegerArrayList(list);
}

int getFromIntegerArrayList(IntegerArrayList* list, size_t index){
    if(index < 0 || index >= list->size){
        fprintf(stderr, "Index Out of Bounds");
        return -1;
    }
    return list->data[index];
}

size_t getIntegerArrayListSize(IntegerArrayList* list){
    return list->size;  
}

size_t getIntegerArrayListCapacity(IntegerArrayList* list){
    return list->capacity;
}

void printIntegerArrayList(IntegerArrayList* list){
    printf("[");
    for(int i = 0; i < list -> size; i++){
        if(i == list->size - 1){
            printf("%d", list->data[i]);
        } else {
        printf("%d, ", list->data[i]);
        }
    }
    printf("]\n");
}   