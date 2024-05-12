typedef struct node
{
    char data;
    struct node *left,*right;
}node;
typedef node *tree;
void init_tree(tree *);
node* createNode(char data);
void insert(tree *t,char data);
node *constructTree(char exp[]);
void inorder(tree t1);
int validateInfix(char exp[]);

//stack structure
typedef struct Node {
    tree data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initialize(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, tree value);
tree pop(Stack* stack);
tree peek(Stack* stack);


