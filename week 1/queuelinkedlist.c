#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int i;
    struct node *link;
}Node;

Node *rear;
Node *front;

void enqueue(int item);
void dequeue();
void display();


//int queue[100],max,ch,item,rear=0,front=0;
void main()
{
    int ch,item;
    printf(" 0.Exit\n 1.Enqueue\n 2.Dequeue\n 3.Display\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==0)
            printf("Exit point\n");
        else if(ch==1){
            printf("Enter element to be pushed:");
            scanf("%d",&item);
            enqueue(item);
        }
        else if(ch==2)
            dequeue();
        else if(ch==3)
            display();
        else
            printf("\nEnter valid choice");


    }while(ch!=0);


}
void enqueue(int item)
{
    Node * temp;
    temp=(Node*)malloc(sizeof(Node));
    if(!temp)
    {
        printf("error in creating node");
    }
    else{
        temp->i=item;
        if(front==NULL)
        {
            front=temp;
            rear=temp;
            front->link=NULL;
            rear->link=NULL;
        }
        else{
            rear->link=temp;
            rear=temp;
            rear->link=NULL;
        }
    }

}
void dequeue()
{
    Node *p;
    if(front==NULL)
    {
        printf("Underflow");
    }
    else{
        p=front;
        printf("The element %d is dequeued",p->i);
        front=front->link;
        free(p);
    }


}
void display()
{
    Node *t;
    t=front;
    if(t==NULL)
    {
        printf("No elements");
    }
    else{
        printf("Printing elements:\n");
        while(t!=NULL)
        {
            printf("%d ",t->i);
            t=t->link;

        }
    }

}
