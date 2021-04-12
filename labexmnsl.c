#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//making a queue and perform insertion and deltion

int front=-1,rear=-1,n=60,qu[100];
void show()
{
    printf("\n\t HERE IS YOUR QUEUE \n");
    if (front!=-1)
    {
        for(int i=front;i<=rear;i++)
            printf("%c  ",qu[i]);
    }
    else
    printf("\n THE QUEUE IS EMPTY \n");
    printf("\n");
}
void enqueue(char x)
{
    if (rear==n-1)
        printf("\n....NO PLACE FOR INPUT .ITS OVERFLOW....\n");
    else
    {
        if (front==-1)
        front=0;
        rear ++;
        qu[rear]=x;
    }
}
char dqueue()
{
    char b;
    if (front==-1)
        printf("\n!!!!THE QUEUE IS EMPTY.ITS UNDERFLOW!!!!\n");
    else
    {
        b = qu[front];
        if (front==rear)
            front=rear=-1;
        else
            front++;
    }
    return b;
}
int main()
{
    char a,str[20],check[50];
    scanf("%s",check);
    for(int i=0;check[i]!='\0';i++)
    {
        if(isalnum(check[i]))
        {
            enqueue(check[i]);
        }
        else if(check[i]=='*')
        {
            printf("%c",dqueue());
        }
        else if(check[i]=='$')
        {
            a = dqueue();
            printf("%c",a);
            enqueue(a);
        }
    }
    show();
    return 0;
}
