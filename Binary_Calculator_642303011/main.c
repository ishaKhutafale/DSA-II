#include<stdio.h>
#include "conversions.h"
#include<stdlib.h>

int main()
{
    
    infixExp *p = NULL;
    printf("Enter numbers and ' + - * / ' in between: ");
    insertInfixExp(&p);
    if(checkInfix(p) == 1)
    {
         infixToPostfix(p);
    }
    else if(checkInfix(p)==2)
    {
        printf("Answer: \n");
        display_infix(p);
    }
    else
    {
        printf("Invalid expression!! please enter valid expression \n");
    }
    return 0;
}