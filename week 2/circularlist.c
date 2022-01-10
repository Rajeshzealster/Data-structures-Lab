#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Number_of_strings 3
#define Size_of_list 5
#define SIZE 20

void insert_list(char*[]);



typedef struct node
{
    char *info[Number_of_strings];
    struct node *next;
}Node;

Node *last;

void insert_list(char* a[])
{
    Node *temp=(Node*)malloc(sizeof(Node*));
    for(int i = 0; i < Number_of_strings; i++)
		temp->info[i] = (char*)malloc(SIZE*sizeof(char));

    for(int i=0;i<Number_of_strings;i++)
    {
        strcpy(temp->info[i],&a[i]);
    }
    if(last==NULL)
    {
        last=temp;
        temp->next=last;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }


}
void display(){
	int i,n= 0;
	Node *temp =last->next;
	if(last == NULL)
		printf("\nEmpty List");

	while(n< Size_of_list){
			for(i = 0; i < Number_of_strings; i++)
				printf("%s\t ",temp->info[i]);
			temp = temp->next;
			n++;
			printf("\n");
	}
}

void display_second(){

	int count = 0;
	Node *temp = last->next;

	if(last == NULL)
		printf("\n Empty List");

	printf("\n\nStrings at second position:\n");

	while(count < Size_of_list){
			printf("%s\t ",temp->info[1]);
			temp = temp->next;
			count++;
			printf("\n");
	}
}

void string_match(){

	Node *temp = last->next;
	int count = 0,f;

	while(count < Size_of_list){

		if(strcmp(temp->info[Number_of_strings-1] , temp->next->info[0]) != 0)
			f=1;

		temp = temp->next;
		count++;
	}

	if(f == 1)
		printf("\n\nStrings do not match!");
	else
		printf("\n\nValid Strings!");

}
void replace_string(Node* temp)
{
    char ar[SIZE];
    printf("\n\nEnter changing value for first string: ");
	scanf("%s",ar);

	strcpy(temp->info[0],ar);
}

void main()
{
    char *a[Number_of_strings];
    int i,j;
    for(i=0;i<Size_of_list;i++)
    {
        printf("\nEnter the strings for node %d(separating with spaces):",i+1);
        for(j=0;j<Number_of_strings;j++)
        {
            scanf("%s",&a[j]);
        }
        insert_list(a);

    }
    display();
    string_match();
    display_second();
    printf("\nFor first node:\n");
    replace_string(last->next);


    printf("\nFor last node:\n");
    replace_string(last);
    display();
    string_match();

}
