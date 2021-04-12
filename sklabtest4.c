#include<stdio.h>
#include<stdlib.h>

int stack[100],n=10;
int top=-1;
void push(int x)
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

int pop()
{
    if (top==-1)
    {
        printf("STACK UNDERFLOW.");
        return 0;
    }
    else
    {
        int a=stack[top];
        top--;
        return a;
    }
}
int main()
{
    printf("\n\t........|| WELCOME ||...........\n");
    printf("\nPRESS PROPER BUTTON AS PER THE INSTRUCTION . ");
    int a=0,ct=0;
    while(a!=3)
    {
        if(ct==3)
            break;
        int num;
        printf("\nPRESS 1 TO ENTER AN INTEGER TO STACK\nPRESS 2 TO EXIT THE PROGRAM\n");
        scanf("%d",&a);
        if(a==1)
        {
            printf("\nENTER THE INTEGER :- ");
            scanf("%d",&num);
            if (num%2 ==0)
            {
                if(top!=-1)
                {
                    ct++;
                    push(num+stack[top]);
                }
                else
                    printf("\nPLEASE SELECT THE FIRST NUMBER A ODD NUMBER . \n");
            }
            else
                push(num);
        }
        else if(a==2)
        {
            printf("\nCLOSE THE PROGRAM IN BETWEEN .....\n");
            break;
        }
        else
            printf("\nPLEASE SELECT THE CORRECT OPTION.\n");
    }
    int sum=0;
    if (ct==3)
    {
        while(top!=-1)
            sum=sum+pop();
    }
    printf("THE FINAL VALUE IS = %d",sum);
    return 0;
}
