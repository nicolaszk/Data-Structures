#include "../include/Stack.h"
#include <iostream>

int main(){
    Stack<int> s;
    for(int i = 0; i < 50; i++){
        s.push(i);
        if(i % 10 == 0){
            std::cout << "Capacity: " << s.getCapacity() << std::endl;
        }
    }
    s.print(); // 0 - 49
    s.pop();
    s.print(); // 1 - 48
    for(int i = 48; i >= 0; i--){
        s.pop();
        if(i % 10 == 0){
            std::cout << "Capacity: " << s.getCapacity() << std::endl;
        }
    }
    s.print(); // should be empty
    return 0;
}
