#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdbool.h>
#include <stddef.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;



typedef struct{
    Node* root;
    size_t size;
} BST;

BST* createBST();
void destroyBST(BST* tree);
void insertBST(BST* tree, int value);
void removeBST(BST* tree, int value);
bool containsBST(BST* tree, int value);
void printBST(BST* tree);
size_t getBSTSize(BST* tree);
Node* searchBST(BST* tree, int value);
Node* getSuccessorBST(BST* tree, Node* node);
void removeBSTNode(BST* tree, Node* node);
void printNode(Node* node, int level);
void destroyNode(Node* node);
#endif