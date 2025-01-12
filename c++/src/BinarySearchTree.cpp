#include "../include/BinarySearchTree.h"
#include <string>

#include <iostream>
template<typename T>
Node<T>::Node(T value) : data(value), left(nullptr), right(nullptr){
    
}

template<typename T>
Node<T>::~Node(){
    delete left;
    delete right;
}

template class Node<int>;
template class Node<double>;
template class Node<char>;
template class Node<std::string>;

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr){


}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    delete root;
}

template<typename T>
void BinarySearchTree<T>::insert(T value){
    if(root == nullptr){ // if the tree is empty, insert value as root
        root = new Node<T>(value);
        return;
    }
    Node<T>* current = root;
    while(current != nullptr){ 
        if(value == current->data) return; // if the value is already in the tree, return
        if(value < current->data){
            if(current -> left == nullptr){
                current-> left = new Node<T>(value);
                return;
            }
            current = current->left;
        }
        else{
            if(current -> right == nullptr){
                current -> right = new Node<T>(value);
                return;
            }
            current = current->right;
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(T value){
    Node<T>* current = root;
    while(current != nullptr){
        if(value == current->data) return true;
        if(value < current->data) current = current->left;
        else{
            current = current->right;
        }

    }
    return false;
}

template<typename T>
void BinarySearchTree<T>::remove(T value) {
    Node<T>* current = root;
    Node<T>* parent = nullptr;
    
    // if empty tree
    if(current == nullptr) return;
    
    // finding the node and its parent
    while(current != nullptr) {
        if(value == current->data) {
            break;
        }
        parent = current;
        if(value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // if the value is not found
    if(current == nullptr) return;
    
    // case 1: removing the root
    if(parent == nullptr) { 
        if(root->left == nullptr && root->right == nullptr) { // if root has no children
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr) { // if root has right child only
            Node<T>* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr) { // if root has left child only
            Node<T>* temp = root;
            root = root->left;
            delete temp;
        }
        else { 
            Node<T>* successor = findSuccessor(root); 
            T successorData = successor->data;
            remove(successor->data);  
            root->data = successorData;  
        }
        return;
    }
    
    // case 2: leaf node removal
    if(current->left == nullptr && current->right == nullptr) {
        if(parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // case 3: one child
    else if(current->left == nullptr || current->right == nullptr) {
        Node<T>* child = current->left != nullptr ? current->left : current->right;
        if(parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    }
    // case 4: two children
    else {
        Node<T>* successor = findSuccessor(current); // finding the successor
        T successorData = successor->data; // successor will always be a leaf node, so we can just copy its data to current node
        remove(successor->data);  // remove the successor
        current->data = successorData;  // copy the successor's data to current node (to keep the tree structure)
        return;  // the size is already decremented in the recursive call
    }
    
}

template<typename T>
Node<T>* BinarySearchTree<T>::findSuccessor(Node<T>* node){
    Node<T>* successor = node -> right;
    while(successor -> left != nullptr){
        successor = successor -> left;
    }
    return successor;
}
template<typename T>
void BinarySearchTree<T>::print(){
    printHelper(root, 0);
}

template<typename T>
void BinarySearchTree<T>::printHelper(Node<T>* node, int level) {
    if (node == nullptr) {
        return;
    }
    
    printHelper(node->right, level + 1);
    
    for (int i = 0; i < level; i++) {
        std::cout << "    ";
    }
    std::cout << node->data << std::endl;
    
    printHelper(node->left, level + 1);
}

template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
template class BinarySearchTree<char>;
template class BinarySearchTree<std::string>;