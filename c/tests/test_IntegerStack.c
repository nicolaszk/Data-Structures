#include <stdio.h>
#include <stdlib.h>
#include "../include/IntegerStack.h"

void main() {
    IntegerStack *stack = createIntegerStack();
    for(int i = 0; i < 50; i++){
        pushToIntegerStack(stack, i);
        if(i % 10 == 0){
            printf("capacity at %d insertion: %d\n", i+1, getIntegerStackCapacity(stack));
        }
    }
    printIntegerStack(stack);
    printf("popping last element: %d\n", popFromIntegerStack(stack));
    printIntegerStack(stack);
    for(int i = 48; i >= 0; i--){
        popFromIntegerStack(stack);
        if(i % 10 == 0){
            printf("capacity at %d pop: %d\n", 49-i, getIntegerStackCapacity(stack));
        }
    }
    printIntegerStack(stack);
    destroyIntegerStack(stack);
    printf("stack destroyed, end of program\n");
}