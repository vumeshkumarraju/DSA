#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head1=NULL,*head2=NULL,*head3=NULL,*p;
int k=0;
void show(struct node* head)
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
void insertBegin(int x,struct node** head)
{
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data=x;
    if (head == NULL)
    {
        *head=newnode;
        newnode->next=NULL; 
    }
    else
    {
        newnode->next=*head;
        *head=newnode;
    }
    show(*head);
}
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sortlink(struct node* a)
{
    struct node *ptr1;
    struct node *ptr2;
    ptr2=a;
    while (ptr2->next!=NULL)
    {
        ptr1=a;
        while (ptr1->next != NULL)
        {
            if (ptr1->data > ptr1->next->data)
                swap(ptr1, ptr1->next);
            ptr1 = ptr1->next;
        }
        ptr2=ptr2->next;   
    }
    show(a);
}
void MergeLists(struct node *a, struct node*b)
{
    if (a == NULL) 
        head3=b;
    else if (b==NULL) 
        head3=a;
    else
    {
        while(a!=NULL&&b!=NULL)
        {   
            struct node* newnode;
            newnode=malloc(sizeof(newnode));
            if (a->data <= b->data) 
            {
                newnode->data=a->data;
                a=a->next;
            }
            else
            {
                newnode->data=b->data;
                b=b->next;
            }
            if (head3==NULL)
            {
                head3=newnode;
                p=head3;
            }   
            else
            {
                p->next=newnode;
                p=p->next;
            }
        }
        while (a!=NULL)
        {
            struct node* newnode;
            newnode=malloc(sizeof(newnode));
            newnode->data=a->data;
            a=a->next;
            p->next=newnode;
            p=p->next;
        }
        while (b!=NULL)
        {
            struct node* newnode;
            newnode=malloc(sizeof(newnode));
            newnode->data=b->data;
            b=b->next;
            p->next=newnode;
            p=p->next;
        }
    }
}
int main()
{
    int num,a=0;
    while (a==0)
    {
        printf("ENTER THE ELEMENT YOU WANT TO INSERT :- ");
        scanf("%d",&num);
        insertBegin(num,&head1);
        printf("enter 0 to enter element:-");
        scanf("%d",&a);
    }
    a=0;
    while (a==0)
    {
        printf("ENTER THE ELEMENT YOU WANT TO INSERT :- ");
        scanf("%d",&num);
        insertBegin(num,&head2);
        printf("enter 0 to enter element:-");
        scanf("%d",&a);
    }
    sortlink(head1);
    sortlink(head2);
    MergeLists(head1,head2);
    show(head3);
    return 0;
}