#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head=NULL,*p;
void show()
{
    printf("\n\tTHE LINKLIST :- \n head --> ");
    if(head!=NULL)
    {
        p=head;
        while(p->next!=NULL)
        {
            printf("%d --> ",p->data);
            p=p->next;
        }
        printf("%d --> ",p->data);
    }
    printf(" NULL\n");
}

void insertBegin(int x)
{
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data=x;
    if (head == NULL)
    {
        head=newnode;
        newnode->next=NULL; 
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    show();
}

void deletelast()
{
    struct node* temp;
    p=head;
    if (head==NULL)
        printf("NO ELEMENTS ARE PRESENT IN THE LINK LIST !!!..");    
    else
    {
        if (p->next==NULL)
        {
            temp=p;
            head=temp->next;
            free(temp);
        }
        else
        {
            while(p->next->next!=NULL)
                p=p->next;
            temp=p->next;
            p->next=temp->next;
            free(temp);
        }
    }
    show();
}
