typedef struct infixExp
{
    char data;
    struct infixExp* next;   
}infixExp;

void insertInfixExp(infixExp **);
void display_infix(infixExp *);
int checkInfix(infixExp *head);
