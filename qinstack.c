#include<stdio.h>
#include<stdlib.h>

//we will make quee opeartion inside a stack.

int top1,top2,s1[100],s2[100],n;
top1=-1;
top2=-1;
void show()
{
    printf("\nTHE QUEE IS :\n");
    for (int i=0;i<=top1;i++)
    {
        printf("%d  ",s1[i]);
    }
    printf("\n");
}
void push1(int x)
{
    if(top1==n-1)
        printf("OVERFLOW\n");
    else
        s1[++top1]=x;
}
void push2(int x)
{
    s2[++top2]=x;
}
int pop1()
{
    if (top1==-1)
    {
        printf("UNDERFLOW\n");
        exit(0);
    }
    else
        return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void enqueue(int x)
{
    push1(x);
    show();
}
void dequeue()
{
    while (top1!=-1)
        push2(pop1());
    printf("THE ELEMENT DELETED :- %d\n",pop2());
    while(top2!=-1)
        push1(pop2());
    show();
}   
int main()
{
   int a=0,num;
    printf("\n\t...........|| WELCOME ||............\n");
    printf("we will insert and delete various integers in queue format.\n");
    printf("PLEASE ENTER THE SIZE OF THE QUEUE :- ");
    scanf("%d",&n);
    printf("\n\t..LETS BEGIN..\n");
    while (a!=3)
    {
        printf("\nPRESS THE CORRESPONDING NUMBER FOR RESPECTIVE QUEUE OPERATION.\n");
        printf("\n1.Insertion or Enqueue\n2.Deletion or Dqueue\n3.Exit\n :");
        scanf("%d",&a);
        if (a==1)
        {
            printf("\nENTER THE INTEGER YOU WANT TO PUSH :- ");
            scanf("%d",&num);
            enqueue(num);
        }
        else if(a==2)
        {
            printf("\nDELETING..........");
            dequeue();
        }
        else if (a==3)
        {
            show();
            printf("\ngood bye.....");
            exit(0);
        }
        else
        printf("\n INVALID INPUT PLEASE PRESS CORRECT OPTION.\n");
    }
    return 0;

}