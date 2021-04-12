#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int n=30,top=-1;
char postexp[100];
float stack[100];
void push(float x)
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
float pop()
{
    if (top==-1)
        return -1;
    else
    {
        float r=stack[top];
        top--;
        return r;
    }
}
int main()
{
    printf("\t..........|| WELCOME ||............\n");
    printf("\tTHE EVALUATION OF POSTFIX EXPRESSION.\n");
    printf("Enter the expression :- ");
    scanf("%s",postexp);
    int ct=0;
    float p;
    for(int i=0;postexp[i]!='\0';i++)
    {         
        if (isalnum(postexp[i]))
        {
            p=postexp[i]-'0';
            push(p);
        }
        else
        {
            float s;
            float b = pop();
            float a = pop();
            if (postexp[i]=='+')
                s=a+b;
            else if(postexp[i]=='-')
                s=a-b;
            else if(postexp[i]=='*')
                s=a*b;
            else if(postexp[i]=='/')
                s=a/b;
            else if(postexp[i]=='^')
                s=pow(a,b);
            ct++;
            push(s);
        }
    }
    printf("THE EVALUATION OF PREFIX = %.2f\n",pop());
    printf("THE NUMBER OF OPERATORS PRESENT = %d",ct);
}
