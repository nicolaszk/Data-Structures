#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class Node{
    public:
        T data;
        Node<T>* left;
        Node<T>* right;
        Node(T data);
        ~Node();
};

template <typename T>
class BinarySearchTree{
    private:
        Node<T>* root;
        void printHelper(Node<T>* node , int level);
        Node<T>* findSuccessor(Node<T>* node);
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(T data);
        void remove(T data);
        bool contains(T data);
        void print();
       
        
};
#endif // BINARYSEARCHTREE_H