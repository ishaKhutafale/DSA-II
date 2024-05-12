#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int compareLists(list l1, list l2)
{
    node *temp1 = l1;
    node *temp2 = l2;
    list l3, l4;
    init_list(&l3);
    init_list(&l4);
    int len1 = 0, len2 = 0;
   
    while (temp1 != NULL)
    {
        insert_beg(&l3, temp1->data + '0');
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        insert_beg(&l4, temp2->data + '0');
        len2++;
        temp2 = temp2->next;
    }
    // Compare lengths
    if (len1 > len2)
    {
        return 1; // List 1 is greater
    }
    else if (len1 < len2)
    {
        return -1; // List 2 is greater
    }
    else
    {
       
        while (l3 != NULL && l4 != NULL)
        {
            if ((l3->data - '0') > (l4->data - '0'))
            {
                return 1; // List 1 is greater
            }
            else if ((l3->data - '0') < (l4->data - '0'))
            {
                return -1; // List 2 is greater
            }
            else
            {
                l3 = l3->next;
                l4 = l4->next;
            }
        }
    }
    // If all digits are equal, the numbers are equal
    return 0;
}

void removeNegation(list *l1)
{
    *l1 = reverseList(l1);
    if ((*l1)->data == '-')
    {
        list temp1 = *l1;
        *l1 = (*l1)->next;
        free(temp1);
    }
    *l1 = reverseList(l1);
}

void removeZero(list *l1)
{
    *l1 = reverseList(l1);
    while ((*l1) && (*l1)->data == '0')
    {
        list temp1 = *l1;
        *l1 = (*l1)->next;
        free(temp1);
    }
    *l1 = reverseList(l1);
}

list addList(list l1, list l2)
{
    int sum, res, tens, units, carry = 0, sign = 0;
    list L3;
    init_list(&L3);
    int i = compareLists(l1, l2);

    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    if (l1->data == '-' && l2->data != '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l1);
        L3 = subNum(l1, l2);
        if (i == 1)
        {
            insert_end(&L3, '-');
        }
        else
        {
            removeNegation(&L3);
        }
        return L3;
    }
    else if (l1->data != '-' && l2->data == '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l2);
        L3 = subNum(l1, l2);
        return L3;
    }
    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    removeNegation(&l1);
    removeNegation(&l2);
    while (l1 && l2)
    {
        sum = (l1->data - '0') + (l2->data - '0') + carry;
        if (sum >= 10)
        {
            // Extract the tens and units places
            tens = sum / 10;
            units = sum % 10;
            insert_end(&L3, units + '0');
            carry = tens;
        }
        else
        {
            insert_end(&L3, sum + '0');
            carry = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        res = (l1->data - '0') + carry;
        if (res >= 10)
        {
            insert_end(&L3, (res % 10) + '0');
            carry = res / 10;
        }
        else
        {
            insert_end(&L3, res + '0');
            carry = 0;
        }
        l1 = l1->next;
    }
    while (l2)
    {
        res = (l2->data - '0') + carry;
        if (res >= 10)
        {
            insert_end(&L3, (res % 10) + '0');
            carry = res / 10;
        }
        else
        {
            insert_end(&L3, res + '0');
            carry = 0;
        }
        l2 = l2->next;
    }
    if (carry != 0)
        insert_end(&L3, carry + '0');
    return L3;
}

list subNum(list l1, list l2)
{
    int diff, borrow = 0;
    list l3;
    init_list(&l3);
    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    if (l1->data == '-' && l2->data != '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l1);
        l3 = addList(l1, l2);
        insert_end(&l3, '-');
        return l3;
    }
    else if (l1->data != '-' && l2->data == '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l2);
        l3 = addList(l1, l2);
        return l3;
    }
    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    removeNegation(&l1);
    removeNegation(&l2);
    int result = compareLists(l1, l2);

    // Display the result
    if (result == 1)
    {
        while (l1 && l2)
        {

            diff = (l1->data - '0') - (l2->data - '0') - borrow;

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            diff = (l1->data - '0') - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l1 = l1->next;
        }
        while (l2)
        {
            diff = (l2->data - '0') - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l2 = l2->next;
        }
        removeZero(&l3);
    }
    else if (result == -1)
    {
        while (l1 && l2)
        {

            diff = (l2->data - '0') - (l1->data - '0') - borrow;

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            diff = (l1->data - '0') - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l1 = l1->next;
        }
        while (l2)
        {
            diff = (l2->data - '0') - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            insert_end(&l3, diff + '0');
            l2 = l2->next;
        }
        removeZero(&l3);
        insert_end(&l3, '-');
    }
    else
    {
        insert_end(&l3, '0');
       
    }
    destroy_list(&l1);
    destroy_list(&l2);
    return l3;
}

list multiply(list l1, list l2)
{
    list result, tempResult;
    init_list(&result);
    insert_end(&result, '0');
    int position = 0;
    int sign = 0;
    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    if (l1->data == '-' && l2->data != '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l1);
        sign = 1;
    }
    else if (l1->data != '-' && l2->data == '-')
    {
        l1 = reverseList(&l1);
        l2 = reverseList(&l2);
        removeNegation(&l2);
        sign = 1;
    }
    l1 = reverseList(&l1);
    l2 = reverseList(&l2);
    while (l1)
    {
        int carry = 0;
        int product = 0;
        init_list(&tempResult);
        list currentl2 = l2;
        while (currentl2 || carry != 0)
        {
            product = carry + ((l1->data - '0')) * (currentl2 ? (currentl2->data) - '0' : 0);
            carry = product / 10;
            product %= 10;
            insert_end(&tempResult, product + '0');
            if (currentl2)
            {
                currentl2 = currentl2->next;
            }
        }
        for (int i = 0; i < position; ++i)
        {
            insert_beg(&tempResult, '0');
        }
        if (tempResult)
        {
            result = addList(result, tempResult);
        }
        l1 = l1->next;
        position++;
    }
    if (sign == 1)
        insert_end(&result, '-');
    return result;
}

list divide(list dividend, list divisor)
{
    list quotient;
    init_list(&quotient);
    insert_end(&quotient, '0');
    if (divisor->data == '0')
    {
        printf("Cannot divide by zero!! \n");
        return NULL;
    }
    else
    {
        int d = 0, carry = 0;
        list div = copyList(divisor);
        while (div)
        {
            d++;
            div=div->next;
        }
        if (d == 1)
        {
            dividend=reverseList(&dividend);
            while (dividend)
            {
                int currentVal = carry * 10 + (dividend->data - '0');
                int Q = currentVal / (divisor->data - '0');
                carry = currentVal % (divisor->data - '0');

                if (Q != 0 || quotient->next != NULL)
                {
                    insert_end(&quotient, Q + '0');
                }
                dividend=dividend->next;
            }
            quotient=reverseList(&quotient);
            removeZero(&quotient);
        }
        else
        {
            while (dividend != NULL)
            {
                while (dividend != NULL && compareLists(dividend, divisor) >= 0 )
                {
                    dividend = subNum(dividend, divisor);
                    quotient = addList(quotient, createNewNode('1'));

                    
                }
                dividend = dividend->next;
            }
        }
    }
    destroy_list(&dividend);
    return quotient;
}
