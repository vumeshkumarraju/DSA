#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct link
{
    char name[40];
};
struct link link_arr[100];
int n=50;
int topf=-1;
int topb= 25;

void push_forward(struct link x)
{
    if (topf==n/2)
    {
        printf("STACK OVERFLOW.");
    }
    else
    {
        topf++;
        link_arr[topf]=x; 
    }
}
struct link pop_forward()
{
    struct link l= link_arr[topf];
    topf--;
    return l;
}
void push_backword(struct link x)
{
    if (topb==n-1)
    {
        printf("STACK OVERFLOW.");
    }
    else
    {
        topb++;
        link_arr[topb]=x; 
    }
}
struct link  pop_backword()
{
    struct link l= link_arr[topb];
    topb--;
    return l;
    
}
int main()
{
    char present[30];
    int s=1;
    struct link l;
    printf("\n\t..........|| WELCOME ||............\n");
    printf("\nENTER THE WEB LINK YOU ARE AT PRESENT :- ");
    scanf("%s",present);
    s = 1;
    while(s!='3')
    {
        switch (s)
        {
        case 3:
            printf("NOW YOU ARE AT LINK :- %s\n",present);
            exit(0);
            break;
        case 1:
            strcpy(l.name,present);
            push_backword(l);
            if(topf==-1)
            {
                printf("\nENTER THE WEB LINK YOU WANT TO GO :- ");
                scanf("%s",present);
            }
            else
            {
                strcpy(present,pop_forward().name);
            }
            printf("NOW YOU ARE AT LINK :- %s\n",present);
            break;
        case 2:
            strcpy(l.name,present);
            push_forward(l);
            if (topb==n/2)
            {
                printf("\nNO LINK AT BACK");
            }
            else
            {
                strcpy(present,pop_backword().name);
            }
            printf("\nNOW YOU ARE AT LINK :- %s\n",present);
            break;
        }
        printf("\n\tPRESS BUTTON AS PER THE INSTRUCTION .\n");
        printf("\n1.PRESS 1 FOR FORWARD .\n2.PRESS 2 FOR BACKWARD.\n3.PRESS 3 TO EXIT.\n :- ");
        scanf("%d",&s);
    }
    return 0;
}