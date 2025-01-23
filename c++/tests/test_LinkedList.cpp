#include "../include/LinkedList.h"
#include <iostream>
#include <ostream>

int main(){
    LinkedList<int> list;
    while(true){
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Remove" << std::endl;
        std::cout << "3. Print" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int value;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list.add(value);
        }
        else if(choice == 2){
            int valueToRemove;
            std::cout << "Enter the value you want to remove:" << std::endl;
            std::cin >> valueToRemove;
            std::cout << "Removing chosen number: " << list.remove(valueToRemove) << std::endl;
        }
        else if(choice == 3){
            list.print();
        }
        else if(choice == 4){
            break;
        }
    }
}