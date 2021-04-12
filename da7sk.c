#include<stdio.h>
#include<stdlib.h>
struct data 
{
    char code[5];
};
int front=-1,rear=-1,n=10;
struct data qu[100];
void show()
{
    printf("\n\t HERE IS YOUR DATA BUFFER\n");
    if (front!=-1)
    {
        if(rear>=front)
        {
            for(int i=front;i<=rear;i++)
                printf("%s  ",qu[i].code);
        }
        else
        {
            for (int i = front; i < n; i++) 
                printf("%s ", qu[i].code); 
            for (int i = 0; i <= rear; i++) 
                printf("%s ", qu[i].code);
        }
    }
    else
    printf("\n THE QUEUE IS EMPTY \n");
    printf("\n");
}
void enqueue(struct data x)
{
    if (front==(rear+1)%n)
        printf("\n....NO PLACE FOR INPUT .ITS OVERFLOW....\n");
    else
    {
        if (front==-1)
            front=rear=0;
        else
            rear=(rear+1)%n;
        qu[rear]=x;
    }
}
void dqueue()
{
    if (front==-1)
        printf("\n!!!!THE QUEUE IS EMPTY.ITS UNDERFLOW!!!!\n");
    else
    {
        printf("\nTHE DATA BURNED : - %s",qu[front].code);
        if (front==rear)
            front=rear=-1;
        else
            front=(front+1)%n;
    }
}
int main()
{
    printf("\t..........|| WELCOME ||............\n");
    printf("\n\t.. DVD BURNER  ..\n");
    int a=0;
    struct data d;
    while(a!=5)
    {
        printf("\n\tPRESS BUTTON AS PER THE INSTRUCTION .\n");
        printf("\n1.PRESS 1 TO ENTER DATA FROM HARDDISK TO BUFFER\n2.PRESS 2 TO SHOW FRONT AND REAR\n3.CHECK AND WRITE INTO DVD\n4.SHOW THE DATA IN BUFFER\n5.PRESS 5 TO EXIT \n");
        scanf("%d",&a);
        if(front==(rear+1)%n)
        {
            printf("\nALL DATA ARE BURN INTO DVD .\n");
            a=3;
        }
        if(a==1)
        {
            printf("ENTER THE DATA YOU WANT TO WRITE TO DVD :- ");
            scanf("%s",d.code);
            enqueue(d);
        }
        else if(a==2)
        {
            printf("\nTHE DATA AT FRONT (index:%d) IS :- %s\n",front,qu[front].code);
            printf("\nTHE DATA AT REAR (index:%d) IS :- %s\n",rear,qu[rear].code);
        }
        else if(a==3)
        {
            if(front!=(rear+1)%n)
                printf("MORE DATA NEEDED.");
            else
            {
                for(int i=front;i<rear;i++)
                    dqueue();
            }
        }
        else if(a==4)
        {
            show();
        }
        else if(a==5)
        {
            printf("DVD BURNER SHUTDOWN");
            exit(0);
        }
        else
            printf("PLEASE CHOSE CORRECT OPTION.");
    }
    return 0;
}