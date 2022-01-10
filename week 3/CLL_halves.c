#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *last,*head1,*head2;
void insert_list(int);
void display_list(Node *);
void split_list();
int count=0;

void split_list()
{
   Node *head=last->next;
   Node *ptr1 = head;
   Node *ptr2= head;

    if(head == NULL)
        return;


    while(ptr2->next != head &&ptr2->next->next != head)
    {
        ptr2 = ptr2->next->next;
        ptr1 = ptr1->next;
    }


    if(ptr2->next->next == head)
        ptr2 = ptr2->next;

    head1= head;


    if(head->next != head)
        head2 = ptr1->next;

    ptr2->next = ptr1->next;


    ptr1->next = head;

}
void display_list(Node *head)
{
  Node *temp = head;
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
  else{
    printf("\nlist is empty.");
  }
}

void insert_list(int ele)
{
    Node *new=(Node*)malloc(sizeof(Node*));
    new->data=ele;
    if(last==NULL)
    {
        last=new;
        new->next=last;
        printf("\nElement %d is inserted into list",ele);
        count++;
    }
    else{
        new->next=last->next;
        last->next=new;
        last=new;
        printf("\nElement %d is inserted into list",ele);
        count++;
    }

}
void main()
{
    int ch,ele;
    //printf("\nEnter the size of Circular linked list:");
    //scanf("%d",&n);
    do{
        printf("\n1.Insert an element to list\n2.Display the list\n3.Split list into two halves\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("\nEnter an element to insert:");
            scanf("%d",&ele);
            insert_list(ele);
        }
        else if(ch==2)
        {

            printf("\nThe elements of list are:\n");
            display_list(last->next);
            printf("\nThe number of elements of list= %d",count);
        }
        else if(ch==3)
        {
            split_list();
            printf("\nThe first half:\n");
            display_list(head1);
            printf("\nThe second half:\n");
            display_list(head2);
            return;
        }
        else if(ch==3)
        {
            printf("\nExit point");
        }
        else{
            printf("\nPlease enter a valid choice:");
        }

    }while(ch!=4);



}

