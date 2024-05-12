typedef struct node
{
    char data;
    struct node* next;   
}node;
typedef node* list;

void init_list(list *);
node* createNewNode(char );
void insert_beg(list *,char );
void insert_end(list *,char );
void display_list(list );
void destroy_list(list *);
node* reverseList(list  *head);
int isEmptyList(list *head);
list copyList(list original);
