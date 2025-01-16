#ifndef MINHEAP_H
#define MINHEAP_H

template <typename T>

class MinHeap{
    private:
        T* data;
        int size;
        int capacity;
        int leftChild(int index);
        int rightChild(int index);
        int parent(int index);
        void heapifyUp(int index);
        void heapifyDown(int index);
        void resize();
        void swap(int i, int j);
    public:
        MinHeap();
        ~MinHeap();
        void insert(T value);
        T extractMin();
        bool isEmpty();
        bool isFull();
        void clear();
        int getSize();
        int getCapacity();
        void printHeap();
        
};

#endif
