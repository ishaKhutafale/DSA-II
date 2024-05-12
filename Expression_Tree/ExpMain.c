#include <stdio.h>
#include "Expression.h"

int main()
{
    char exp[100];
    printf("Enter the Infix Expression with parentheses '(' and ')': ");
    scanf("%s", exp);
    if (validateInfix(exp))
    {
        printf("Infix Expression: %s\n", exp);
        tree t1;
        init_tree(&t1);
        t1 = constructTree(exp);
        printf("Inorder Traversal: ");
        inorder(t1);
        printf("\n");
    }
    else
    {
        printf("Enter valid infix Expression\n");
    }

    return 0;
}