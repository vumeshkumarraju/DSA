
#include<stdio.h>
#include<stdlib.h>

//HOT POTTATO GAME

struct child 
{
    char name[20];
};
int n,rear=-1,front=-1;
struct child qu[300];
void show()
{
    if (front!=-1)
    {
        if(rear>=front)
        {
            for(int i=rear;i>=front;i--)
                printf("%s  ",qu[i].name);
        }
        else
        {
            for (int i = n-1; i >=front; i--) 
                printf("%s ", qu[i].name); 
            for (int i = rear; i >=0 ; i--) 
                printf("%s ", qu[i].name);
        }
    }
    printf("\n");
}
void enqueue(struct child x)
{
    if (front==(rear+1)%n)
        printf("\n....NO PLACE FOR MORE PARTICIPANTS....\n");
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
        printf("\n!!!! NO PARTICIPANTS !!!!\n");
    else
    {
        if (front==rear)
            front=rear=-1;
        else
            front=(front+1)%n;
    }
}
int main()
{
    int num;
    struct child pl;
    printf("\n\t...........|| WELCOME ||............\n");
    printf("\tLETS START THE GAME..........\n");
    printf("PLEASE ENTER THE NUMBER OF PARTICIPANTS :- ");
    scanf("%d",&n);
    printf(" PLEASE ENTER THE NAME OF THE PARTICIPANTS IN A QUEUE.");
    for(int i=0;i<n;i++)
    {
        printf("\nENTER THE NAME OF THE PARTICIPANT %d :- ",i+1);
        scanf("%s",qu[i].name);
        enqueue(qu[i]);
    }
    printf("\n\t...HERE IS THE OUR PARTICIPANTS...\n");
    show();
    printf("LETS BEGIN THE COUNTING............\n");
    num=1;
    while(rear!=front)
    {
        if(num!=7)
        {
            pl=qu[front];
            printf("\n....THE CHILD %s SAYS %d....\n",pl.name,num);
            dqueue();
            enqueue(pl);
        }
        else
        {
            printf("\n!!! THE PARTICIPANT OUT OF THE GAME : - %s\n",qu[front].name);
            dqueue();
            num=0;
            printf("\nNOW REMAINED CONTENSTANTS ARE :- \n");
            show();
        }
        num++;
    }
    printf("\n\n\t.....THE WINNER IS :- %s",qu[front].name);
    return 0;
}
