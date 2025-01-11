#include <stdio.h>
#include <stdlib.h>
#include "../include/IntegerArrayList.h"

void main() {
    IntegerArrayList* list = createIntegerArrayList();
    for(int i = 0; i < 50; i++){
        addToIntegerArrayList(list, i);
        if(i % 10 == 0){
            printf("capacity: %d\n", getIntegerArrayListCapacity(list));
        }
    }
    printIntegerArrayList(list);
    for(int i = 49; i >= 0; i--){
        removeFromIntegerArrayList(list, i);
        if(i % 10 == 0){
            printf("capacity: %d\n", getIntegerArrayListCapacity(list));
        }
    }
    printIntegerArrayList(list);
    destroyIntegerArrayList(list);
}