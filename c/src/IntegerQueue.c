#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/IntegerQueue.h"

#define DEFAULT_CAPACITY 10

IntegerQueue *createIntegerQueue(){
    IntegerQueue *queue = malloc(sizeof(IntegerQueue));
    if(!queue){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    queue->data = malloc(DEFAULT_CAPACITY * sizeof(int));
    if(!queue->data){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    queue->size = 0;
    queue->capacity = DEFAULT_CAPACITY;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void destroyIntegerQueue(IntegerQueue *queue){
    if(queue){
        free(queue -> data);
        free(queue);
    }

}
void enqueueIntegerQueue(IntegerQueue *queue, int value){
    if(queue -> size == queue -> capacity){
        resizeIntegerQueue(queue);
    }
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> data[queue -> front] = value;
    queue -> size++;
    if(queue -> rear == -1){
        queue -> rear = 0;
    }
}
int dequeueIntegerQueue(IntegerQueue *queue){
    if(isIntegerQueueEmpty(queue)){
        fprintf(stderr, "Queue is empty");
        exit(EXIT_FAILURE);
    }
    int value = queue -> data[queue -> rear];
    queue -> rear = (queue -> rear + 1) % queue -> capacity;
    queue -> size--;
    if(queue -> size < queue -> capacity/4 && queue -> capacity > DEFAULT_CAPACITY){
        resizeIntegerQueue(queue);
    }
    return value;
}

void resizeIntegerQueue(IntegerQueue * queue){
    if(queue -> size == queue -> capacity){
        int* newData = malloc(queue -> capacity * 2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < queue -> size; i++){
            newData[i] = queue -> data[(queue -> rear + i) % queue -> capacity];
        }
        free(queue -> data);
        queue -> data = newData;
        queue -> capacity *= 2;
        queue -> rear = 0;
        queue -> front = queue -> size - 1;
    }
    else{
        int* newData = malloc(queue -> capacity/2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < queue -> size; i++){
            newData[i] = queue -> data[(queue -> rear + i) % queue -> capacity];
        }
        free(queue -> data);
        queue -> data = newData;
        queue -> capacity /= 2;
        queue -> rear = 0;
        queue -> front = queue -> size - 1;
    }
}

bool isIntegerQueueEmpty(IntegerQueue *queue){
    return queue -> size == 0;
}

bool doesIntegerQueueContain(IntegerQueue *queue, int value){
    for(int i = 0; i < queue -> capacity; i++){
        if(queue -> data[i] == value){
            return true;
        }
    }
    return false;
}

void clearIntegerQueue(IntegerQueue *queue){
    if(queue){
        free(queue -> data);
        int* newData = malloc(DEFAULT_CAPACITY * sizeof(int));
        queue -> data = newData;
    }
    queue -> size = 0;
    queue -> front = -1;
    queue -> rear = -1;
}
int peekIntegerQueue(IntegerQueue *queue){
    if(isIntegerQueueEmpty(queue)){
        fprintf(stderr, "Queue is empty");
    }
    return queue -> data[queue -> rear];
}

size_t getIntegerQueueSize(IntegerQueue *queue){
    return queue -> size;
}

size_t getIntegerQueueCapacity(IntegerQueue *queue){
    return queue -> capacity;
}
void printIntegerQueue(IntegerQueue * queue){
    printf("[");
    for(int i = 0; i < queue -> size; i++){
        int index = (queue -> rear + i) % queue -> capacity;
        if(i == queue -> size - 1){
            printf("%d", queue -> data[index]);
        } else {
            printf("%d, ", queue -> data[index]);
        }
    }
    printf("]\n");
}
