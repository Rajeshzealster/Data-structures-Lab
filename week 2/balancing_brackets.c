#include<stdio.h>
#define max 100

void push(char);
char pop();
int isMatchingPair(char, char);

char s[max];
int top;

void main()
{
    char exp[50];
    char ch,ch1;
    int i;
    top=-1;
    printf("\nEnter the string containing only [,],{,},(,) characters:");
    fgets(exp,50,stdin);
    //printf("%s",exp);
    while((ch=exp[i++])!='\n')
    {
        if(ch=='(' ||ch=='{' ||ch=='[')
       {
           push(ch);
       }

        else if(ch==')' ||ch=='}' ||ch==']')
        {
             ch1=pop();
             if(!isMatchingPair(ch1,ch)){
                printf("\nThe expression is not balanced  - FALSE\n");
                return;
             }
        }


    }
    if(top==-1)
        printf("\nThe expression is fully balanced - TRUE\n");
    else
        printf("\nThe expression is not balanced - FALSE\n");
}
void push(char ch)
{
    s[++top]=ch;
}
char pop()
{
    char ele;
    ele=s[top--];
    return ele;
}
int isMatchingPair(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')')
        return 1;
    else if (ch1 == '{' && ch2 == '}')
        return 1;
    else if (ch1 == '[' && ch2 == ']')
        return 1;
    else
        return 0;
}
