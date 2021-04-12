#include<stdio.h>
#include<stdlib.h>
struct vehicle
{
    char name[40];
};
int front=-1,rear=-1,n=5;
struct vehicle qu[100];
void show()
{
    printf("\n\t THE VEHICLES AT THE TOLLGATE : \n");
    if (front!=-1)
    {
        for(int i=front;i<=rear-1;i++)
            printf("%s -> ",qu[i].name);
        printf("%s -> ",qu[rear].name);
    }
    else
    printf("\n THE QUEUE IS EMPTY \n");
    printf("\n");
}
void enqueue(struct vehicle x)
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
void dqueue()
{
    if (front==-1)
        printf("\n!!!!THE QUEUE IS EMPTY.ITS UNDERFLOW!!!!\n");
    else
    {
        printf("\nTHE VEHICLE PASSED : - %s\n",qu[front].name);
        if (front==rear)
            front=rear=-1;
        else
            front++;
    }
}
int main()
{
    int count;
    struct vehicle info;
    int a=0;
    count=0;
    while (a!=1)
    {
        if (count!=5)
        {
            printf("\nTHE VEHICLE INFO :- ");
            scanf("%s",info.name);
            enqueue(info);
            count++;
        }
        else
        {
            dqueue();
            dqueue();
            count=0;
        }
        show();
        printf("\n PLEASE PRESS 1 IF YOU WANT TO EXIT THE PROGRAM :- ");
        scanf("%d",&a);
    }
    return 0;
}