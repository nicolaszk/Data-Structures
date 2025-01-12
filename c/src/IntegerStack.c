#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memmove and memcpy
#include "../include/IntegerStack.h"
#include <stdbool.h>
#define DEFAULT_CAPACITY 10

IntegerStack* createIntegerStack(){
    IntegerStack* stack = malloc(sizeof(IntegerStack));
    if(!stack){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    stack -> size = 0;
    stack -> capacity = DEFAULT_CAPACITY;
    stack -> data = malloc(DEFAULT_CAPACITY * sizeof(int));
    if(!stack -> data){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    return stack;
}

void destroyIntegerStack(IntegerStack* stack){
    if(stack){
        free(stack -> data);
        free(stack);
    }
}

void pushToIntegerStack(IntegerStack* stack, int value){
    stack -> data[stack->size++] = value;
    resizeIntegerStack(stack);
}

int popFromIntegerStack(IntegerStack *stack){
    if(stack -> size > 0){
        int value = stack -> data[stack->size--];
        resizeIntegerStack(stack);
        return value;
    }
    else{
        fprintf(stderr, "Stack is empty, returning -1");
        return -1;
    }
}

int peekIntegerStack(IntegerStack* stack){
    if(stack -> size > 0){
        return stack -> data[stack->size - 1];
    }
    else{
        fprintf(stderr, "Stack is empty");
        exit(EXIT_FAILURE);
    }
}

bool isIntegerStackEmpty(IntegerStack* stack){
    return stack -> size == 0;
}

void resizeIntegerStack(IntegerStack* stack){
    if(stack -> size == stack -> capacity){
        int* newData = malloc(stack -> capacity * 2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        memcpy(newData, stack -> data, stack -> capacity*sizeof(int));
        free(stack -> data);
        stack -> data = newData;
        stack -> capacity *= 2;
    }
    if(stack -> size < stack -> capacity/4 && stack -> capacity > DEFAULT_CAPACITY){
        int* newData = malloc(stack -> capacity/2 * sizeof(int));
        if(!newData){
            fprintf(stderr, "Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        memcpy(newData, stack -> data, stack -> size * sizeof(int));
        free(stack -> data);
        stack -> data = newData;
        stack -> capacity /= 2;
    }
}
size_t getIntegerStackCapacity(IntegerStack* stack){
    return stack->capacity;
}

size_t getIntegerStackSize(IntegerStack* stack){
    return stack->size;
}

void printIntegerStack(IntegerStack* stack){
    for(int i = 0; i < stack->size; i++){
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
void clearIntegerStack(IntegerStack*stack){
    stack->size = 0;
    int* newData = malloc(DEFAULT_CAPACITY * sizeof(int));
    if(!newData){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    free(stack->data);
    stack->data = newData;
    stack->capacity = DEFAULT_CAPACITY;
}
