#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 40

void insert(int,int);
void delete(int);
void display(int);
int maxi(int[]);
int min(int[]);
int queue_array[MAX];

//I was taking the size of each queue as 10..

int rear[]={-1,10,20,30};//for holding rear values of all queues to insert
int front[]= {-1,10,20,30};//for holding front values of all queues to delete
int initials[]={-1,10,20,30};//holds initial rear& front values of all queues
int queue_elements[]={0,0,0,0};//holds number of elements in each queue

void main()
{
    int ch,qno,max,item;
    //5 elements initially in Q1
    insert(0,12);
    insert(0,21);
    insert(0,34);
    insert(0,43);
    insert(0,54);
    //3 elements into Q2
    insert(1,41);
    insert(1,32);
    insert(1,61);
    //2 elements in Q3
    insert(2,78);
    insert(2,53);
    //6 elements in Q4
    insert(3,87);insert(3,86);insert(3,58);insert(3,47);
    insert(3,97);insert(3,69);
    printf("\n=============================================================\n");
    printf("0.Exit \n");
    printf("1.Display all Queues(Initially not empty) \n");
    printf("2.Display all elements of array \n");
    printf("3.Insert into minimum elements queue \n");
    printf("4.delete from maximum elements queue \n");
    printf("5.Sequence of operations &display all 4 queues(3 delete(),2 insert() & delete())\n");
    while (1)
    {

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        if(ch==1)
        {
            for(qno=0;qno<4;qno++)
            {
                display(qno);
            }

        }
        else if(ch==2){
            for(int i=0;i<MAX;i++)
            {
                printf(" %d",queue_array[i]);
            }
        }
        else if(ch==3)
        {
            qno=min(queue_elements);
            printf("Inset the element in queue : ");
            scanf("%d", &item);
            insert(qno,item);
        }
        else if(ch==4)
        {
            qno=maxi(queue_elements);
            delete(qno);
        }
        else if(ch==5)
        {
            delete(maxi(queue_elements));
            delete(maxi(queue_elements));
            delete(maxi(queue_elements));
            printf("Enter element for 1st insert() operation:");
            scanf("%d",&item);
            insert(min(queue_elements),item);
            printf("Enter element for 2nd insert() operation:");
            scanf("%d",&item);
            insert(min(queue_elements),item);
            delete(maxi(queue_elements));
            for(qno=0;qno<4;qno++)
            {
                display(qno);
            }

        }

        else if(ch==0)
        {
            exit(1);
        }
        else
        {
             printf("Wrong choice \n");
        }

    }
}

void insert(int q,int item)
{
    int r,f,m;
    r=rear[q];
    f=front[q];
   if (r == front[q+1] - 1)
        printf("Queue Overflow \n");
    else
    {
        if (f == initials[q])
        {
        	f = initials[q]+1;
		}
        r = r + 1;
        queue_array[r] = item;
    }
    rear[q]=r;
    front[q]=f;
    queue_elements[q]=queue_elements[q]+1;
}

void delete(int q)
{
    int r,f,m;
    r=rear[q];
    f=front[q];
    if (f == initials[q] || f > r)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[f]);
        queue_array[f]=0;
        f = f + 1;
    }
    front[q]=f;
    queue_elements[q]--;
}

void display(int q)
{
    int i;
    int r,f;
    r=rear[q];
    f=front[q];
    if (f == initials[q])
        printf("Queue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = f; i <= r; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
int maxi(int a[])
{
    int i,max=0,index;
    for(i=0;i<4;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            index=i;
        }
    }
    return index;
}
int min(int a[])
{
    int i,min=INT_MAX,index;
    for(i=0;i<4;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            index=i;
        }
    }
    return index;
}
