#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void initBST(tree *t)
{
    *t = NULL;
    return;
}
node *createNode(int data, char name[])
{
    node *nn = (node *)malloc(sizeof(node));
    nn->mis = data;
    strcpy(nn->name, name);
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
node *insertNode(node *t, int mis, char name[])
{

    if (t == NULL)
    {
        return createNode(mis, name);
    }
    if (mis == t->mis)
    {
        return t;
    }
    else if (mis < t->mis)
    {
        t->left = insertNode(t->left, mis, name);
    }
    else if (mis > t->mis)
    {
        t->right = insertNode(t->right, mis, name);
    }
    return t;
}
void inorder(tree t1)
{
    if (t1 == NULL)
    {
        return;
    }
    inorder(t1->left);
    printf("[%d ,%s] -> ", t1->mis, t1->name);
    inorder(t1->right);
}
void preorder(tree t1)
{
    if (t1 == NULL)
    {
        return;
    }
    printf("[%d ,%s] -> ", t1->mis, t1->name);
    preorder(t1->left);
    preorder(t1->right);
}
void postorder(tree t1)
{
    if (t1 == NULL)
    {
        return;
    }
    postorder(t1->left);
    postorder(t1->right);
    printf("[%d ,%s] -> ", t1->mis, t1->name);
}
int Count(tree t)
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + Count(t->left) + Count(t->right);
}
int search(tree t, int key)
{
    if (t == NULL)
    {
        return 0; // The tree is empty, key not found
    }
    if (t->mis == key)
    {
        return 1;
    }
    else if (key < t->mis)
    {
        return search(t->left, key);
    }
    else if (key > t->mis)
    {
        return search(t->right, key);
    }
}
node *inOrderPredecessor(tree t)
{
    t = t->left;
    while (t->right)
    {
        t = t->right;
    }
    return t;
}
node *delete(tree t, int key)
{
    node *p = t;
    node *inpre;
    if (p == NULL)
    {
        return NULL;
    }
    // search for the location
    if (key < p->mis)
    {
        p->left = delete (p->left, key);
    }
    else if (key > p->mis)
    {
        p->right = delete (p->right, key);
    }
    else
    {
        // code for deletion if the node is leaf node or have one child
        if (t->left == NULL)
        {
            node *temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL)
        {
            node *temp = t->left;
            free(t);
            return temp;
        }
        // deletion of node with 2 children
        inpre = inOrderPredecessor(p);
        p->mis = inpre->mis;
        p->left = delete (p->left, inpre->mis);
    }
    return p;
}
