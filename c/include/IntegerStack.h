#ifndef INTEGERSTACK_H
#define INTEGERSTACK_H
#include <stdbool.h>
#include <stddef.h>

typedef struct{
    int* data; 
    size_t size;
    size_t capacity; 
} IntegerStack;

IntegerStack *createIntegerStack();
void destroyIntegerStack(IntegerStack *stack);
void pushToIntegerStack(IntegerStack *stack, int value);
int popFromIntegerStack(IntegerStack *stack);
int peekIntegerStack(IntegerStack *stack);
size_t getIntegerStackSize(IntegerStack *stack);
size_t getIntegerStackCapacity(IntegerStack *stack);
void printIntegerStack(IntegerStack *stack);
void resizeIntegerStack(IntegerStack *stack);
bool isIntegerStackEmpty(IntegerStack *stack);
void clearIntegerStack(IntegerStack *stack);

#endif