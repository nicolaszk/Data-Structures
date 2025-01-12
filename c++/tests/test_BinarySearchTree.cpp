#include "../include/BinarySearchTree.h"
#include <iostream>

int main(){
    int arr[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 16, 19, 2, 9, 14, 17, 20};
    BinarySearchTree<int> bst;
    for(int i: arr){
        bst.insert(i);
    }
    bst.print();
    // removing leaf nodes;
    std::cout << "removing 2, 14, 17, 20" << std::endl;
    bst.remove(2);
    bst.remove(14);
    bst.remove(17);
    bst.remove(20);
    bst.print();
    // searching for nodes;
    std::cout << "searching for 10, 15, 3, 14" << std::endl;
    std::cout << bst.contains(10) << std::endl;
    std::cout << bst.contains(15) << std::endl;
    std::cout << bst.contains(3) << std::endl;
    std::cout << bst.contains(14) << std::endl;
    // removing nodes with one child;
    std::cout << "removing 1 and 19" << std::endl;
    bst.remove(1);
    bst.remove(19);
    bst.print();
    // removing nodes with two children;
    std::cout << "removing 10" << std::endl;
    bst.remove(10);
    bst.print();
    // removing root node;
    std::cout << "removing 15" << std::endl;
    bst.remove(15);
    bst.print();
    return 0;
}