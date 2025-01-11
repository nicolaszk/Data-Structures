#include "../include/Queue.h"
#include <iostream>

int main(){
    Queue<int> q;
    for(int i = 0; i < 50; i++){
        q.enqueue(i);
        if(i % 10 == 0){
            std::cout << "Capacity: " << q.getCapacity() << std::endl;
        }
    }
    q.print(); // 0 - 49
    q.dequeue();
    q.print(); // 1 - 49
    for(int i = 48; i >= 0; i--){
        q.dequeue();
        if(i % 10 == 0){
            std::cout << "Capacity: " << q.getCapacity() << std::endl;
        }
    }
    q.print();
    return 0;
}
