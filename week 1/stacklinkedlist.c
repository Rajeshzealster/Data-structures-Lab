#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//creating a structure for node of linked list
typedef struct node
{
    int i;
    struct node *link;
}Node;

Node * head;
void push(int item);
void pop();
void display();

//Driver code
void main()
{
    int ch,item;
    printf(" 0.Exit\n 1.push\n 2.pop\n 3.display\n");
    do
    {

        printf("\nEnter your  choice:");
        scanf("%d",&ch);
        if(ch==0)
            printf("Exit point\n");
        else if(ch==1){
            printf("Enter element to be pushed:");
            scanf("%d",&item);
            push(item);
        }
        else if(ch==2)
            pop();
        else if(ch==3)
            display();
        else
            printf("\nEnter valid choice");


    }while(ch!=0);
}
//Inserting an element into stack
void push(int item)
{
    Node * p;
    p=(Node*)malloc(sizeof(Node));
    if(!p)
    {
        printf("error in creating a node & element can't be pushed");
    }
    p->i=item;
    p->link=head;
    head=p;

}
//Removing the last inserted element from stack--LIFO order
void pop()
{
    Node *temp;
    if(head==NULL)
    {
        printf("stack underflow");
    }
    int ele=head->i;
    temp=head;
    head=head->link;
    free(temp);
    printf("Element %d is popped",ele);

}

//Displaying the elements of stack
void display()
{
    Node * temp;
    temp=head;
    if(temp==NULL)
    {
        printf("No elements in the stack");
    }
    else
    {
        printf("Printing stack elements:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->i);
            temp=temp->link;
        }
    }

}
