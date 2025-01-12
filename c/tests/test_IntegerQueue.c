/* circular queues are beautiful*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/IntegerQueue.h"
void main(){
    IntegerQueue *queue = createIntegerQueue();
    for(int i = 0; i < 50; i++){
        enqueueIntegerQueue(queue, i);
        if(i % 10 == 0){
            printf("capacity: %d\n", getIntegerQueueCapacity(queue));
        }
    }
    printf("size: %d\n", getIntegerQueueSize(queue));
    printf("peek: %d\n", peekIntegerQueue(queue));
    printf("contains 10: %d\n", doesIntegerQueueContain(queue, 10));
    printf("contains 100: %d\n", doesIntegerQueueContain(queue, 100));
    printf("contains 50: %d\n", doesIntegerQueueContain(queue, 50));
    printf("contains 1000: %d\n", doesIntegerQueueContain(queue, 1000));
    printIntegerQueue(queue);
    for(int i = 49; i >= 0; i--){
        dequeueIntegerQueue(queue);
        if(i % 10 == 0){
            printf("capacity: %d\n", getIntegerQueueCapacity(queue));
        }
    }
    printf("is empty: %d\n", isIntegerQueueEmpty(queue));
    printf("size: %d\n", getIntegerQueueSize(queue));
    printf("peek: %d\n", peekIntegerQueue(queue));
    printIntegerQueue(queue);
    destroyIntegerQueue(queue);
}