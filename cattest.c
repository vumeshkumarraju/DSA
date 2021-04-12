/* 
V UMESH KUMAR RAJU
REG NO. :- 20MIS0187
...CAT1 LAB TEST...
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int n=50;
char stack[100];
int top=-1;
void show()
{
    printf("\nTHE STACK IS :\n");
    for (int i=top;i>=0;i--)
    {
        printf("%c  ",stack[i]);
    }
    printf("\n");
}
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
    char b;
    if (top==-1)
    {
        printf("STACK UNDERFLOW.");
        return '0';
    }
    else
    {
        printf("%c",stack[top]);
        b = stack[top];
        top--;
        return b;
    }
}
int main()
{
    char a,check[50];
    printf("\nPLEASE ENTER THE EXPRESSION (TEXT) :- ");
    scanf("%s",check);
    printf("\nTHE OUTPUT :- \n");
    for(int i=0;check[i]!='\0';i++)
    {
        if(isalnum(check[i]))
        {
            push(check[i]);
        }
        else if(check[i]=='*')
        {
            a = pop();
        }
        else if(check[i]=='$')
        {
            a = pop();
            a = pop();
        }
        else if(check[i]=='#')
        {
            a = pop();
            printf("%c",a);
        }
    }
    printf("\n");
    show();
    return 0;
}
