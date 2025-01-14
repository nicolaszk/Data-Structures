#include <stdio.h>
#include <stdbool.h>
#include "../include/BinarySearchTree.h"

int main() {
    BST* tree = createBST();
    if (!tree) {
        printf("Erro ao criar árvore\n");
        return 1;
    }

    while(true) {
        printf("\n=== Menu BST ===\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Entrada inválida\n");
            while (getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1: {
                printf("Digite o valor para inserir: ");
                int value;
                if (scanf("%d", &value) == 1) {
                    insertBST(tree, value);
                    printf("Valor %d inserido na árvore\n", value);
                } else {
                    printf("Valor inválido\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 2: {
                printf("Digite o valor para remover: ");
                int value;
                if (scanf("%d", &value) == 1) {
                    removeBST(tree, value);
                    printf("Valor %d removido da árvore\n", value);
                } else {
                    printf("Valor inválido\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 3: {
                printf("Digite o valor para buscar: ");
                int value;
                if (scanf("%d", &value) == 1) {
                    if(containsBST(tree, value)) {
                        printf("Valor %d encontrado na árvore\n", value);
                    } else {
                        printf("Valor %d não encontrado na árvore\n", value);
                    }
                } else {
                    printf("Valor inválido\n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 4:
                printBST(tree);
                break;
            case 5:
                destroyBST(tree);
                return 0;
            default:
                printf("Opção inválida\n");
        }
    }

    return 0;
}