#include<stdio.h>
#include<stdlib.h>

void insert_end(int item);
void display();
int decimal_output(int);

typedef struct node{
    int i;
    struct node *next;
}Node;
Node *head;

int decimal_output(int n)
{
    Node *t;
    int sum=0;
    t=head;
    while(t!=NULL)
    {
        sum=sum+(t->i)*(1<<n-1);
        n--;
        t=t->next;
    }
    return sum;

}
void insert_end(int item)
{
    Node *t=head;
    Node * new;
    new=(Node*)malloc(sizeof(Node));
    new->i=item;
    if(head==NULL)
    {
        new->next=head;
        head=new;
        printf("Element %d gets inserted into the list",item);
    }
    else{
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new;
        new->next=NULL;
        printf("Element %d gets inserted into the list",item);
    }
}
void display()
{
    Node * t;
    t=head;
    if(head==NULL)
    {
        printf("\n No elements to display");
        return;
    }
    else{
        while(t!=NULL)
        {
            printf("%d-->",t->i);
            t=t->next;
        }
    }

}
void main()
{
    int ele,n;
    int i=0;
    printf("\nEnter the total number of digits(0/1 only) OR Number of elements in list:");
    scanf("%d",&n);
    while(i<n)
    {
        printf("\nThe element to insert into list(0/1 only):");
        scanf("%d",&ele);
        if(ele==0 ||ele==1)
        {
            insert_end(ele);
        }
        else{
            printf("\nPlease enter valid input i,e element could either 0 or 1 only\n");
            return;
        }
        i++;

    }
    printf("\n\nThe single linked list is:\n");
    display();
    int d=decimal_output(n);
    printf("\n\nThe decimal equivalent value is %d",d);

}
