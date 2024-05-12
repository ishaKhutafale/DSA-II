typedef struct node
{
    int mis;
    char name[20];
    struct node *left,*right;
}node;

typedef node* tree;

void initBST(tree *);
node *createNode(int data,char[]);
node *insertNode(node *,int,char[]);
int Count(tree);
node *delete(tree ,int);
node *inOrderPredecessor(tree t);
int search(tree,int);
void inorder(tree);
void preorder(tree);
void postorder(tree);

