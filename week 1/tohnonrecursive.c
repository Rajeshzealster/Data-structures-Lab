#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
typedef struct Stack
{
int n;
int top;
int *array;
}Stack;


Stack* createStack(int n)
{
	Stack* stack =(Stack*) malloc(sizeof(Stack));
	stack -> n =n;
	stack -> top = -1;
	stack -> array =(int*) malloc(stack -> n * sizeof(int));
	return stack;
}




void push(Stack *stack, int item)
{
	if (stack->top==stack->n-1)
    {
        return;
    }
	stack -> array[++stack -> top] = item;
}


int pop(Stack* stack)
{
	if (stack->top==-1)
		return INT_MIN;
	return stack -> array[stack -> top--];
}


void movement(char source, char destination, int diskno)
{
	printf("Move the disk %d from \'%c\' to \'%c\'\n",diskno, source, destination);
}


void move_disk(Stack *source,Stack *destination, char s, char d)
{
	int pole1_disk = pop(source);
	int pole2_disk = pop(destination);


	if (pole1_disk == INT_MIN)
	{
		push(source, pole2_disk);
		movement(d, s, pole2_disk);
	}


	else if (pole2_disk == INT_MIN)
	{
		push(destination, pole1_disk);
		movement(s, d, pole1_disk);
	}


	else if (pole1_disk > pole2_disk)
	{
		push(source, pole1_disk);
		push(source, pole2_disk);
		movement(d, s, pole2_disk);
	}


	else
	{
		push(destination, pole2_disk);
		push(destination, pole1_disk);
		movement(s, d, pole1_disk);
	}
}
void toh_nonrecursive(int n,Stack
			*source, Stack *use,
			Stack *destination)
{
	int i, moves;
	char s = 'S', d = 'D', u ='U';
	if (n % 2 == 0)
	{
		char t = d;
		d = u;
		u = t;
	}
	moves = (1<<n)-1;

	//Larger disks will be pushed first
	for (i = n; i >= 1; i--)
		push(source, i);

	for (i = 1; i <=moves; i++)
	{
		if (i % 3== 1)
		move_disk(source, destination, s, d);

		else if (i % 3 == 2)
		move_disk(source, use, s, u);

		else if (i % 3 == 0)
		move_disk(use, destination, u, d);
	}
}
void main()
{

	//int n=4;
	int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
	Stack *source, *destination, *use;
	source = createStack(n);
	use= createStack(n);
	destination = createStack(n);

	toh_nonrecursive(n,source, use,destination);

}
