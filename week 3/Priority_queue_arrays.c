#include<stdio.h>
#define N 20
int Priority_gatescore[N];
char *name[N];
int r = -1,f = -1;
void enqueue(char *data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			name[r] = data;
			Priority_gatescore[r] = p;

		}

		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Priority_gatescore[i])
				{
					name[i+1] = name[i];
					Priority_gatescore[i+1] = Priority_gatescore[i];
				}
				else
					break;
			}
			name[i+1] = data;
			Priority_gatescore[i+1] = p;
			r++;
		}
	}

}
void print() //print the data of Queue
{
int i;
	for(i=f;i<=r;i++)
	{
		printf("\nName = %s\tPriority = %d",name[i],Priority_gatescore[i]);
	}
}
int dequeue() //remove the data from front
{
	if(f == -1)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("deleted Element = %s\t Its Priority = %d",name[f],Priority_gatescore[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
int main()
{
	int opt,n,i,p;
	char data[20];

	do{
		printf("\n\n1 To Insert the Data in Queue\n2 To show the Data in Queue \n3 To Delete the data from the Queue\n0 To Exit");
		printf("\nEnter Your Choice:-");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter size of data:");
				scanf("%d",&n);

				i=0;
				while(i<n){
                    printf("\nEnter the name and Priority ");
					scanf("%s %d",&data,&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");

		}
	}while(opt!=0);
        return 0;
}
