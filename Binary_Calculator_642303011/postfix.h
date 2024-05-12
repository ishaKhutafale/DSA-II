typedef struct postfixExp
{
    char data;
    struct postfixExp* next;   
}postfixExp;

void pushToPostfix(postfixExp **,char data);
void display_postfix(postfixExp* head);
