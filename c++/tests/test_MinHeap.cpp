#include "../include/MinHeap.h"
#include <iostream>

int main(){
    MinHeap<int> heap;
    while(true){
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Extract Min" << std::endl;
        std::cout << "3. Print Heap" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int value;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            heap.insert(value);
        }
        else if(choice == 2){
            std::cout << "Extracting min: " << heap.extractMin() << std::endl;
        }
        else if(choice == 3){
            heap.printHeap();
        }
        else if(choice == 4){
            break;
        }
    }
}