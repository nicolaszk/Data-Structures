#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

int main() {
    LinkedList* list = createLinkedList();
    while(true){
        printf("1. Add element\n2.Remove element\n3.Print list\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to add: ");
                int elementToAdd;
                scanf("%d", &elementToAdd);
                addToLinkedList(list, elementToAdd);
                break;
            case 2:
                printf("Enter the element to remove: ");
                int elementToRemove;
                scanf("%d", &elementToRemove);
                if(removeFromLinkedList(list, elementToRemove)){
                    printf("Element removed successfully\n");
                }else{
                    printf("Element not found\n");
                }
                break;
            case 3:
                printLinkedList(list);
                break;
            case 4:
                deleteLinkedList(list);
                return 0;
            default:
                printf("Invalid choice, try again\n");
                break;
        }
    }
}