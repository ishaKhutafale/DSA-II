#include <stdio.h>
#include "tree.h"

int main()
{
    tree t1;
    initBST(&t1);
    int choice, mis;
    char Name[50];

    do
    {
        printf("\n1. Insert Node");
        printf("\n2. Remove Node");
        printf("\n3. Search Node");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Count Nodes");
        printf("\n8. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter MIS: ");
            scanf("%d", &mis);
            printf("Enter Name: ");
            scanf("%s", Name);
            t1 = insertNode(t1, mis, Name);
            break;
        case 2:
            printf("\nEnter MIS to remove: ");
            scanf("%d", &mis);
            t1 = delete (t1, mis);
            break;
        case 3:
            printf("\nEnter MIS to search: ");
            scanf("%d", &mis);
            if (search(t1, mis) == 1)
            {
                printf("It is present!\n");
            }
            else
            {
                printf("Not Present.\n");
            }
            break;
        case 4:
            printf("\nInorder Traversal:\n");
            inorder(t1);
            break;
        case 5:
            printf("\nPreorder Traversal:\n");
            preorder(t1);
            break;
        case 6:
            printf("\nPostorder Traversal:\n");
            postorder(t1);
            break;
        case 7:
            printf("\nTotal number of nodes: %d\n", Count(t1));
            break;
        case 8:
            printf("\nExiting program.\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
