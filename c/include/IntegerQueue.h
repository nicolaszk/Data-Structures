#ifndef INTEGERQUEUE_H
#define INTEGERQUEUE_H
#include <stdbool.h> // for contains
#include <stddef.h> // for size_t

typedef struct{
    int*data;
    size_t size;
    size_t capacity;
    int front;
    int rear;
} IntegerQueue;

IntegerQueue *createIntegerQueue();
void destroyIntegerQueue(IntegerQueue *queue);
void enqueueIntegerQueue(IntegerQueue *queue, int value);
int dequeueIntegerQueue(IntegerQueue *queue);
int peekIntegerQueue(IntegerQueue *queue);
size_t getIntegerQueueSize(IntegerQueue *queue);
size_t getIntegerQueueCapacity(IntegerQueue *queue);
void printIntegerQueue(IntegerQueue *queue);
void resizeIntegerQueue(IntegerQueue *queue);
bool isIntegerQueueEmpty(IntegerQueue *queue);
bool doesIntegerQueueContain(IntegerQueue *queue, int value);
void clearIntegerQueue(IntegerQueue *queue);

#endif