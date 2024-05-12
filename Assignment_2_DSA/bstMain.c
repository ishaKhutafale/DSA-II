#include <stdio.h>
#include "bstTree.h"
int main()
{
    tree t;
    init_bst(&t, 50);

    insert_bst(&t, 12);
    insert_bst(&t, 6);
    insert_bst(&t, 15);
    insert_bst(&t, 3);
    insert_bst(&t, 8);
    insert_bst(&t, 13);
    insert_bst(&t, 4);
    insert_bst(&t, 25);
    insert_bst(&t, 42);

    printf("Inorder: ");
    inorder(t);
    printf("\n");
    printf("Preorder: ");
    preorder(t);
    printf("\n");
    printf("Postorder: ");
    postorder(t);
    printf("\n");
    printf("Levelwise Traverse : ");
    levelwiseTraverse(t);
    if (iscomplete(t))
    {
        printf("\nTree is complete\n");
    }
    else
    {
        printf("\nTree is not complete\n");
    }
    return 0;
}