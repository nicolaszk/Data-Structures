#ifndef INTEGERARRAYLIST_H
#define INTEGERARRAYLIST_H

#include <stddef.h> // for size_t

typedef struct{
    int* data;
    size_t size;
    size_t capacity;
} IntegerArrayList;

IntegerArrayList *createIntegerArrayList();
void destroyIntegerArrayList(IntegerArrayList* list);
void addToIntegerArrayList(IntegerArrayList* list, int value);
void removeFromIntegerArrayList(IntegerArrayList* list, size_t index);
int getFromIntegerArrayList(IntegerArrayList *list, size_t index);
size_t getIntegerArrayListSize(IntegerArrayList *list);
size_t getIntegerArrayListCapacity(IntegerArrayList *list);
void printIntegerArrayList(IntegerArrayList *list);
void resizeIntegerArrayList(IntegerArrayList *list);


#endif