#ifndef MAXHEAP_H
#define MAXHEAP_H
template <typename T>
class MaxHeap
{
private:
    T *data;
    int size;
    int capacity;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void swap(int i, int j);
    void resize();
    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);
public:
    MaxHeap();
    ~MaxHeap();
    void insert(T value);
    T extractMax();
    void clear();
    bool isEmpty();
    bool isFull();
    int getSize();
    int getCapacity();
    void printHeap();
    void changeValue(T old_value, T value);
    // could add: contains, peek, remove, etc.
};

#endif
 