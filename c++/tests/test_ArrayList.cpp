#include "ArrayList.h"
#include <iostream>

int main(){
    ArrayList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    list.remove(1);
    list.print();
    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "Capacity: " << list.getCapacity() << std::endl;
    return 0;
}
