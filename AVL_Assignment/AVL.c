#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

void initAVL(AVL *t)
{
    *t = NULL;
    return;
}
node *createNode(char name[])
{
    node *nn = (node *)malloc(sizeof(node));
    nn->balance_factor = 0;
    strcpy(nn->name, name);
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    return nn;
}
int getBalanceFactor(AVL t)
{
    if (t == NULL)
    {
        return 0;
    }
    return (getheight(t->left) - getheight(t->right));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getheight(AVL t)
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + max(getheight(t->left), getheight(t->right));
}
node *rightRotate(AVL t) // if the case is LL
{
    node *newNode = t->left;
    node *newNodeRight = newNode->right;
    // perform rotation
    newNode->right = t;
    t->left = newNodeRight;

    if (t->left != NULL)
    {
        newNodeRight->parent = t;
    }
     newNode->parent=t->parent;
    if(newNode->parent != NULL)
    {
        if(newNode->parent->left==t)
        {
            newNode->parent->left= newNode;
        }
        else
        {
            newNode->parent->right=newNode;
        }
    }
    
    t->parent = newNode;
    newNode->parent = NULL;
    newNode->balance_factor = getBalanceFactor(newNode);
    t->balance_factor = getBalanceFactor(t);
    return newNode;
}


node *leftRotate(AVL t) // if the case is RR
{
    node *newNode = t->right;
    node *newNodeLeft = newNode->left;
    // perform rotation
    newNode->left = t;
    t->right = newNodeLeft;
    if (newNodeLeft != NULL)
    {
        newNodeLeft->parent = t;
    }

    newNode->parent=t->parent;
    if(newNode->parent != NULL)
    {
        if(newNode->parent->left==t)
        {
            newNode->parent->left= newNode;
        }
        else
        {
            newNode->parent->right=newNode;
        }
    }
    
    t->parent = newNode;
    newNode->balance_factor = getBalanceFactor(newNode);
    t->balance_factor = getBalanceFactor(t);
    return newNode;
}
node *insertNode(AVL t, char name[])
{
    if (t == NULL)
    {
        return createNode(name);
    }
    if (strcmp(name, t->name) < 0)
    {
        t->left = insertNode(t->left, name);
        t->left->parent = t;
    }
    else if (strcmp(name, t->name) > 0)
    {
        t->right = insertNode(t->right, name);
        t->right->parent = t;
    }
    else
    {
        return t;
    }
    t->balance_factor = getBalanceFactor(t);
    if (t->balance_factor > 1 && strcmp(name, t->left->name) < 0)
    {
        
        return rightRotate(t);//LL
    }
    else if (t->balance_factor < -1 && strcmp(name, t->right->name) > 0)
    {
        return leftRotate(t);//RR
    }
    else if (t->balance_factor > 1 && strcmp(name, t->left->name) > 0)
    {
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    else if (t->balance_factor < -1 && strcmp(name, t->right->name) < 0)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}

node *inOrderPredecessor(AVL t)
{
    t = t->left;
    while (t->right)
    {
        t = t->right;
    }
    return t;
}
node *delete(AVL p, char name[])
{
    node *inpre;
    if (p == NULL)
    {
        return NULL;
    }
    // search for the location
    if (strcmp(name, p->name) < 0)
    {
        p->left = delete (p->left, name);
    }
    else if (strcmp(name, p->name) > 0)
    {
        p->right = delete (p->right, name);
    }
    else
    {
        // code for deletion if the node is leaf node or have one child
        if (p->left == NULL)
        {
            node *temp = p->right;
            if (temp != NULL)
                temp->parent = p->parent;
            free(p);
            return temp;
        }
        else if (p->right == NULL)
        {
            node *temp = p->left;
            if (temp != NULL)
                temp->parent = p->parent;
            free(p);
            return temp;
        }
        // deletion of node with 2 children
        inpre = inOrderPredecessor(p);
        strcpy(p->name, inpre->name);
        p->left = delete (p->left, inpre->name);
    }
    p->balance_factor = getBalanceFactor(p);
    if (p->balance_factor == 2 && getBalanceFactor(p->left) >= 0)
    {
        if (getBalanceFactor(p->left) >= 0)
        {
            return rightRotate(p);
        }
        else
        {
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }
    }
    else if (p->balance_factor == -2 && getBalanceFactor(p->right) <= 0)
    {
        if (getBalanceFactor(p->right) <= 0)
        {
            return leftRotate(p);
        }
        else
        {
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }
    }
    return p;
}
void destroyTree(AVL avl)
{
    if (avl != NULL)
    {
        destroyTree(avl->left);
        destroyTree(avl->right);
        free(avl);
    }
}
void preorder(AVL t)
{
    if (t == NULL)
    {
        return;
    }
    printf("name: %s,\tBalance Factor: %d ,\tParent: %s\n", t->name, t->balance_factor, (t->parent != NULL) ? t->parent->name : "None");
    preorder(t->left);
    preorder(t->right);
}