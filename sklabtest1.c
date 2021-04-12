
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n=30;
char stack[100];
int top=-1;
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
    char c;
    if (top==-1)
    {
        printf("STACK UNDERFLOW.");
    }
    else
    {
        c= stack[top];
        top--;
    }
    return c;
}
int main()
{
    printf("\n\t.........||WELCOME||........\n");
    char str[20],rev[20];
    printf("ENTER THE STRING :- ");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
        push(str[i]);
    int j;
    for(j=0;top!=-1;j++)
        rev[j]=pop();
    rev[j]='\0';
    if(strcmp(str,rev)==0)
        printf("\nINVALID INPUT\n");
    else
        printf("THE REVERSE STRING :- %s",rev);
    return 0;
}