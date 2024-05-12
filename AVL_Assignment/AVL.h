typedef struct node
{
    int balance_factor;
    char name[20];
    struct node *left, *right,*parent;
} node;
typedef node *AVL;
void initAVL(AVL *);
node *createNode(char name[]);
node *insertNode(AVL, char name[]);
node *delete(AVL t, char name[]);
node *inOrderPredecessor(AVL t);
void destroyTree(AVL avl);
int getBalanceFactor(AVL t);
int max(int a, int b);
int getheight(AVL t);
node *rightRotate(AVL t);
node *leftRotate(AVL t);
void preorder(AVL t);