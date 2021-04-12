
#include<stdio.h>
#include<stdlib.h>

char stack[100];
int top=-1;
int n=50;
void push(char a)
{
    if (top==n-1)
    {
        printf("THE PROGRAM LIMIT IS OVER ");
    }
    else
    {
        top++;
        stack[top]=a;
    }
}
void pop()
{
    if (top==-1)
    {
        printf("STACK UNDERFLOW.");
    }
    else
    {
        top--;
    }
}
int main()
{
    printf("\t..........|| WELCOME ||............\n");
    printf("WE WILL CHECK YOUR ENTERED EXPRESSION IS BALANCED WITH PARENTHESIS OR NOT.\n");
    char inp[50];
    printf("ENTER THE EXPRESSION :- ");
    scanf("%s",inp);
    for (int i=0;inp[i]!='\0';i++)
    {
        if ((inp[i]=='{'||inp[i]=='('||inp[i]=='[')&&(stack[i]==stack[top]))
        {
            push(inp[i]);
        }
        else if (inp[i] == '}'||inp[i] == ']')
        {
            if((inp[i]-2)==stack[top])
            {
                pop();
            }
            else
            {
                printf("!!!!SORRY,CHECK YOUR EXPRESSION.\nYOUR EXPRESSION HAS NOT BALANCED WITH PARENTHESIS.");
                exit(0);
            }
        }
        else if(inp[i] == ')')
        {
            if((inp[i]-1)==stack[top])
            {
                pop();
            }
            else
            {
                printf("!!!!SORRY,CHECK YOUR EXPRESSION.\nYOUR EXPRESSION HAS NOT BALANCED WITH PARENTHESIS.");
                exit(0);
            }
        }        
    }
    if (top==-1)
    printf("CONGRATS YOUR EXPRESSSION HAS BALANCED PARENTHESIS...........");
    else
    printf("!!!!SORRY,CHECK YOUR EXPRESSION.\nYOUR EXPRESSION HAS NOT BALANCED WITH PARENTHESIS.");
    return 0;
}
