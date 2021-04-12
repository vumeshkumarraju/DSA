#include<stdio.h>
#include<ctype.h>

int n=30,top=-1;
char inexp[100],stack[100];
void push(char x)
{
    if (top==n-1)
    {
        printf("STACK OVERFLOW.");
    }
    else
    {
        top++;
        stack[top]=x; 
    }
}
char pop()
{
    if (top==-1)
        return -1;
    else
    {
        char r=stack[top];
        top--;
        return r;
    }
}
int prior(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}
int main()
{
    printf("\t..........|| WELCOME ||............\n");
    printf("\tTHE EXPRESSION WILL BE CONVERTED TO POSTFIX EXPRESSION.\n");
    char a;
    printf("Enter the expression :- ");
    scanf("%s",inexp);
    for(int i=0;inexp[i]!='\0';i++)
    {
        if (isalnum(inexp[i]))
            printf("%c",inexp[i]);
        else if (inexp[i]=='(')
            push(inexp[i]);
        else if (inexp[i]==')')
        {
            a=pop();
            while(a!='(')
            {
                printf("%c",a);
                a=pop();
            }
        }
        else
        {
            while(prior(stack[top])>=prior(inexp[i]))
                printf("%c",pop());
            push(inexp[i]);
        }
    }
    while (top!=-1)
        printf("%c",pop());
    return 0;
}