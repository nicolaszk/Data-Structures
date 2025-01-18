#include "../include/MaxHeap.h"
#include <iostream>

int main(){
    MaxHeap<int> heap;
    while(true){
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Extract Max" << std::endl;
        std::cout << "3. Print Heap" << std::endl;
        std::cout << "4. Change Value" << std::endl;
        std::cout << "5. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int value;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            heap.insert(value);
        }
        else if(choice == 2){
            std::cout << "Extracting max: " << heap.extractMax() << std::endl;
        }
        else if(choice == 3){
            heap.printHeap();
        }
        else if(choice == 4){
            int oldValue, newValue;
            std::cout << "Enter old value and new value: ";
            std::cin >> oldValue >> newValue;
            heap.changeValue(oldValue, newValue);
        }
        else if(choice == 5){
            break;
        }
    }
}