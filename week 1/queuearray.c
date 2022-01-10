//Queue visualized as circular array i,e array of size n equivalent to (n-1) sized queue

#include<stdio.h>

void enqueue(int item);
void dequeue();
void display();


int queue[100],max,ch,item,rear=0,front=0;

void main()
{
    printf("Enter the size of queue:");
    scanf("%d",&max);

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
    //rear=(rear+1)%(max+1);
    if(front==(rear+1)%(max+1))
    {
        printf("queue overflow");
    }
    else
    {
        rear=(rear+1) % (max+1);
        queue[rear]=item;

    }

}
void dequeue()
{
    if(front==rear)
    {
        printf("queue underflow");
    }
    else
    {
        front=(front+1)%(max+1);
        printf("dequeued element is %d",queue[front]);
    }


}
void display()
{
    int i=front;
    if(front==rear)
    {
        printf("\n No elements to display.");
    }
        else{
            while (i!=rear)
            {
                i=(i+1)%(max+1);
                printf("%d ",queue[i]);

            }
        }

}
