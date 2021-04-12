//da1sk

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char regno[40];
};
int n;
struct student stack[100];
int top=-1;
void show()
{
    printf("\nTHE STUDENTS ARE :\n");
    for (int i=0;i<=top;i++)
    {
        printf("%s  ",stack[i].regno);
    }
    printf("\n");
}
void push(struct student x)
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
    show();
}

void pop()
{
    if (top==-1)
    {
        printf("STACK UNDERFLOW.");
    }
    else
        top--;
    show();
}
int main()
{
    struct student stud;
    char reg[40];
    int a;
    printf("\t..........|| WELCOME ||............\n");
    printf("\n\t.....RECORDS OF THE STUDENTS SUBMITTED ASSIGNMENT SUCESSFULLY.......\n");
    printf("\nPLEASE ENTER THE NUMBER OF THE STUDENTS IN THE CLASS :- ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nENTER THE REGISTRATION NUMBER OF THE STUDENT :- ");
        scanf("%s",stud.regno);
        push(stud);
    }

    /*High Level: Should implement low level and middle level modules + any query posed by 
    faculty such as checking if a particular student has submitted the assignment or not.*/
    a=0;
    while (a==0)
    {
        printf("\nPRESS 0 TO CHECK ANY REGEISTRATION NUMBER HAS SUBMITTED OR NOT ELSE PRESS ANYOTHER NUMBER .\n");
        scanf("%d",&a);
        if(a==0)
        {
            printf("PLEASE ENTER THE RESGISTRATION NUMBER YOU WANT TO CHECK :- ");
            scanf("%s",reg);
            int k=0;
            for(int i=0;i<=top;i++)
            {
                if(strcmp(stack[i].regno,reg)==0)
                {
                    printf("YES STUDENT HAS SUBMITTED .");
                    k++;
                    break;
                }
            }
            if(k == 0)
                printf("NO STUDENT HAS NOT SUBMITTED");
        }
    }
    
    //Low Level: Display the register number of the last submitted record

    printf("\nTHE REGISTRATION NUMBER OF THE STUDENT SUBMITTED LAST :- %s \n",stack[top].regno);

    //Middle Level: Display the register number of the ten students who submitted first

    for(int i=top;i>9;i--)
        pop();
    printf("\nTHE FIRST TEN STUDENT SUBMITTED FIRST :- \n");
    show();
    return 0;
}