#include <stdio.h>
#include <stdlib.h>
#include "../include/BinarySearchTree.h"

BST* createBST(){
    BST* tree = malloc(sizeof(BST));
    if(!tree){
        fprintf(stderr, "Memory Allocation Error");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void destroyNode(Node* node){
    if(node){
        destroyNode(node -> left);
        destroyNode(node -> right);
        free(node);
    }
}

void destroyBST(BST* tree){
    if(tree){
        destroyNode(tree->root); // recursive deletion of all nodes in the tree
        free(tree);
    }
}

void insertBST(BST* tree, int value){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode){
        fprintf(stderr, "Memory Allocation Error:");
    }
    newNode -> value = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    //now to insert the node into the tree
    if(tree -> root == NULL){
        tree -> root = newNode;
    } else {
        Node* current = tree -> root;
        while(current != NULL){
            if(value < current -> value){
                if(current -> left == NULL){
                    current -> left = newNode;
                    newNode -> parent = current;
                    break;
                }
                current = current -> left;
            }
            else if(value > current -> value){
                if(current -> right == NULL){
                    current -> right = newNode;
                    newNode -> parent = current;
                    break;
                }
                current = current -> right;
            }
            else{
                free(newNode); // free new node memory
                printf("value already exists in the tree");
            }
        }
        tree -> size++;
    }
}

void removeBST(BST* tree, int value){ // auxiliar function to see if node exists in the tree
    Node* nodeToRemove = searchBST(tree, value);
    if(nodeToRemove == NULL){
        printf("Node not found");
        return;
    }
    removeBSTNode(tree, nodeToRemove);
}


void removeBSTNode(BST* tree, Node* node){
    if(node -> left == NULL && node -> right == NULL){
        if(node == tree -> root){
            tree -> root = NULL;
            free(node);
            tree -> size--;
            return;
        }
        else if(node -> parent -> left == node){ // node is leaf and left child
            node -> parent -> left = NULL;
        }
        else if(node -> parent -> right == node){ // node is leaf and right child
            node -> parent -> right = NULL;
        }
        free(node);
        tree -> size--;
        return;
    }
    else if(node -> left == NULL || node -> right == NULL){
        Node* child = node -> left != NULL? node -> left : node -> right; //child is the only child of our node
        if(node == tree -> root){
            tree -> root = child;
        }
        else if(node -> parent -> left == node){ // se nodo for filho esquerdo, o unico filho do nodo se torna o filho esquerdo do pai
            node -> parent -> left = child;
        }
        else if(node -> parent -> right == node){ // se nodo for filho direito, o unico filho do nodo se torna o filho direito do pai
            node -> parent -> right = child;
        }
        child -> parent = node -> parent;
        free(node);
        tree -> size--;
        return;
    }
    else{
        Node* successor = getSuccessorBST(tree, node);
        node -> value = successor -> value;
        removeBSTNode(tree, successor);
    }
}


Node* getSuccessorBST(BST* tree, Node* node){
    if(node -> right != NULL){
        Node* aux = node -> right;
        while(aux -> left != NULL){
            aux = aux -> left;
        }
        return aux;
    }   
    return NULL;
}

size_t getBSTSize(BST* tree){
    return tree -> size;
}

bool containsBST(BST* tree, int value){
    Node* node = searchBST(tree, value);
    return node != NULL;
}

Node* searchBST(BST* tree, int value){
    Node* current = tree -> root;
    while(current != NULL){
        if(value == current -> value){
            return current;
        }
        if(value < current -> value){
            current = current -> left;
        }
        else{
            current = current -> right;
        }
    }
    return NULL;
}

void printBST(BST* tree){
    if(tree -> root == NULL){
        printf("Tree is empty");
        return;
    }
    printNode(tree -> root, 0);
}

void printNode(Node* node, int level){
    if(node == NULL){
        return;
    }
    printNode(node -> right, level + 1);
    for(int i = 0; i < level; i++){
        printf("  ");
    }
    printf("%d\n", node -> value);
    printNode(node -> left, level + 1);
}