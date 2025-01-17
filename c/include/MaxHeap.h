#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stddef.h>
#include <stdbool.h>

// Tornar a struct opaca para encapsulamento
typedef struct MaxHeap MaxHeap;

// Funções principais
MaxHeap* createMaxHeap();
void destroyMaxHeap(MaxHeap* heap);
bool insertMaxHeap(MaxHeap* heap, int value);
bool removeMaxHeap(MaxHeap* heap, int value);
int pollMaxHeap(MaxHeap* heap);

// Funções de consulta
size_t capacityMaxHeap(const MaxHeap* heap);
size_t sizeMaxHeap(const MaxHeap* heap);
bool isEmptyMaxHeap(const MaxHeap* heap);
bool containsMaxHeap(const MaxHeap* heap, int value);
bool peekMaxHeap(const MaxHeap* heap, int* value);
void printMaxHeap(const MaxHeap* heap);

// Função de modificação
bool changeValueMaxHeap(MaxHeap* heap, int old_value, int new_value);

#endif