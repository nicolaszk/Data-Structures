#include <stdio.h>
#include <stdlib.h>
#include "../include/MinHeap.h"

int main(){
    MinHeap* heap = createMinHeap();
    while(true){
        printf("1. Insert\n2. Remove\n3. Poll\n4. Change Value\n5. Print\n6. Exit\n");
        int choice;
        scanf("%d", &choice);
        int value = 0;
        switch(choice){
            case 1: 
                value = 0;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertMinHeap(heap, value);
                break;
            case 2:
                value = 0;
                printf("Enter value to remove: ");
                scanf("%d", &value);
                removeMinHeap(heap, value);
                break;
            case 3:
            printf("Value polled: %d\n", pollMinHeap(heap));
            break;
            case 4:
                value = 0;
                printf("Enter value to change: ");
                scanf("%d", &value);
                printf("Enter new value: ");
                int new_value = 0;
                scanf("%d", &new_value);
                changeValueMinHeap(heap, value, new_value);
                break;
            case 5:
                printMinHeap(heap);
                break;
            case 6: 
                destroyMinHeap(heap);
                printf("heap destroyed, end of program\n");
                return 0;
            default:
                printf("invalid choice, try again\n");
        }
    }
    return 0;
}