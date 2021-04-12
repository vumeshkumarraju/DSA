#include<stdio.h>
#include<stdlib.h>

struct ride
{
    char group[5];
};

int front=-1,rear=-1,n=20;
struct ride qu[100];
void enqueue(struct ride x)
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
        printf("\n %d. A %s IS ENTERING THE ROLERCOSTER ",front+1,qu[front].group);
        if (front==rear)
            front=rear=-1;
        else
            front++;
    }
}
void vip(struct ride x)
{
    for(int i=rear;i>front;i--)
    {
        qu[i+1]=qu[i];
    }
    rear+=1;
    qu[front]=x;
}
int main()
{
    printf("\t..........|| WELCOME ||............\n");
    printf("\n\t.. ROLLER COSTER RIDE ..\n");
    int a=0;
    struct ride r;
    while(a!=4)
    {
        printf("\n\tPRESS BUTTON AS PER THE INSTRUCTION .\n");
        printf("\n1.PRESS 1 TO ENTER A PERSON INTO QUEUE\n2.PRESS 2 TO ENTER A VIP TO QUEUE\n3.CHECK AND START THE RIDE\n4.EXIT THE PROGRAM\n");
        scanf("%d",&a);
        if(rear == 19)
        {
            printf("\nALL MEMBERS ARE READY NOW START FOR RIDE .\n");
            a=3;
        }
        if((a==1)&&(rear!=19))
        {
            printf("ENTER WEATHER THE PERSON IS CHILD OR ADULT :- ");
            scanf("%s",r.group);
            enqueue(r);
        }
        else if((a==2)&&(rear!=19))
        {
            printf("ENTER WEATHER THE PERSON IS CHILD OR ADULT :- ");
            scanf("%s",r.group);
            vip(r);
        }
        else if(a==3)
        {
            if(rear!=19)
                printf("MORE MEMBERS NEEDED.");
            else
            {
                for(int i=front;i<rear;i++)
                    dqueue();
            }
        }
        else if(a==4)
        {
            printf("ROLLERCOSTER SHUTDOWN.");
            exit(0);
        }
        else
            printf("PLEASE CHOSE CORRECT OPTION.");
    }
    return 0;
}