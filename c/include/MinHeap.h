#ifndef MINHEAP_H
#define MINHEAP_H

#include <stddef.h>
#include <stdbool.h>

// Tornar a struct opaca para encapsulamento
typedef struct MinHeap MinHeap;

// Funções principais
MinHeap* createMinHeap();
void destroyMinHeap(MinHeap* heap);
bool insertMinHeap(MinHeap* heap, int value);
bool removeMinHeap(MinHeap* heap, int value);
int pollMinHeap(MinHeap* heap);

// Funções de consulta
size_t capacityMinHeap(const MinHeap* heap);
size_t sizeMinHeap(const MinHeap* heap);
bool isEmptyMinHeap(const MinHeap* heap);
bool containsMinHeap(const MinHeap* heap, int value);
bool peekMinHeap(const MinHeap* heap, int* value);
void printMinHeap(const MinHeap* heap);

// Função de modificação
bool changeValueMinHeap(MinHeap* heap, int old_value, int new_value);

#endif