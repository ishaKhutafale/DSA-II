#include <stdio.h>
#include "AVL.h"

int main()
{
    AVL t;
    initAVL(&t);
    int choice;
    char name[50];
    do
    {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Remove a node\n");
        printf("3. Traverse the tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student name to insert: ");
            scanf("%s", name);
            t = insertNode(t, name);
            break;
        case 2:
            printf("Enter student name to remove: ");
            scanf("%s", name);
            t = delete (t, name);
            break;
        case 3:
            preorder(t);
            break;
        case 4:
            destroyTree(t);
            printf("AVL tree destroyed. Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
    return 0;
}