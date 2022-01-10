#include<stdio.h>
#include<conio.h>
void push(int item);
void pop();
void display();

int stack[100],top,max,ch,item;



//driver code
void main()
{

    printf("Enter the size of stack:");
    scanf("%d",&max);
    top=-1;

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
//for pushing items into stack
void push(int item)
{

    if(top==max-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        stack[++top]=item;
    }
}
//for poping/removing the last inserted element from stack--LIFO order
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
       // int ele=stack[top--];
        printf("Element %d is poped from stack\n",stack[top--]);
    }
}
//displaying the elements of stack
void display()
{
    int i;
    if (top==-1)
    {
        printf("No elements in the stack");
    }
    for(i=0;i<=top;i++)
    {
        printf("%d\t",stack[i]);
        printf("\n");
    }
}
