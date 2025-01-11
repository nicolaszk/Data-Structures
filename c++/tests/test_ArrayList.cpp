#include "../include/ArrayList.h"
#include <iostream>

int main(){
    ArrayList<int> list;
    for(int i = 0; i < 50; i++){
        list.add(i);
        if(i % 10 == 0){
            std::cout << "Capacity: " << list.getCapacity() << std::endl;
        }
    }
    list.print();
    for(int i = 49; i >= 0; i--){
        list.remove(i);
        if(i % 10 == 0){
            std::cout << "Capacity: " << list.getCapacity() << std::endl;
        }
    }
    list.print();
    return 0;
}
