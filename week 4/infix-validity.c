#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define STR_SIZE 20
char * infixtopostfix(char *);
char s[100];
int top_of_stack = -1;

void push(char a)
{
    s[++top_of_stack] = a;
}

char pop()
{
    if(top_of_stack == -1)
        return -1;
    else
        return s[top_of_stack--];
}

int precedence(char a)
{
    if(a == '(' || a == '[' || a == '{')
        return 0;
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/')
        return 2;
}
char get_open_brackets(char c)
{
    char ch;
    if(c==')')
       ch='(';
    if(c=='}')
        ch='{';
    if(c==']')
        ch='[';
    return ch;
}
char get_close_brackets(char c)
{
    char ch;
    if(c=='(')
       ch=')';
    if(c=='{')
        ch='}';
    if(c=='[')
        ch=']';
    return ch;
}
 char * reverse(char* expression)
 {
    int count=0,end,begin;
    //char* infix_reverse=(char *)malloc(STR_SIZE*sizeof(char));
    static char infix_reverse[STR_SIZE];
    while(expression[count]!='\0')
        count++;

    end=count-1;
    //Reversing the infix expression
    for(begin=0;begin<count;begin++)
    {
        if(expression[end]=='(' || expression[end]=='{' || expression[end]=='[' ){
            infix_reverse[begin]=get_close_brackets(expression[end]);

        }
        else if(expression[end]==')' || expression[end]=='}' || expression[end]==']'){
            infix_reverse[begin]=get_open_brackets(expression[end]);
        }
        else
            infix_reverse[begin]=expression[end];
            end--;


    }
    infix_reverse[begin]='\0';
    return infix_reverse;
 }
 char* infixtoprefix(char* expression)
{
    char *infix_reverse=reverse(expression);
   // printf("%s",infix_reverse);
    char* output=infixtopostfix(infix_reverse);

    char *prefix_exp=reverse(output);
    return prefix_exp;
}
char* infixtopostfix(char* exp)
{
    char a;
    int i=0;
    static char output[20];
    //char *output=(char*)malloc(STR_SIZE*sizeof(char));
    while(*exp != '\0')
    {
        if(isalnum(*exp))
            output[i++]=*exp;
        else if((*exp == '(') || (*exp == '[') || (*exp == '{') )
            push(*exp);
        else if((*exp == ')') || (*exp == ']') || (*exp == '}'))
        {
            char ch1=get_open_brackets(*exp);
            while((a = pop()) != ch1 )
                output[i++]=a;
            //a=pop(ch1);
        }
        else
        {
            while(precedence(s[top_of_stack]) >= precedence(*exp))
                output[i++]=pop();
            push(*exp);
        }
        exp= exp + 1;
    }
    while(top_of_stack != -1)
    {
        output[i++]=pop();;
    }
    output[i]='\0';
    //printf("%s",output);
    //free(output);
    return output;
}

int isoperator(char ch)
{
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' ||ch=='^' || ch=='%' || ch=='^')
        return 1;
    else
        return 0;
}
int isoperand(char ch)
{
    if(ch>='a' &&ch<='z' ||ch>='A' && ch<='Z')
        return 1;
    else
        return 0;
}
int balanced_parnthesis(char* infix)
{
    int ch=0;
    char ele;
    while(infix[ch]!='\0'){
        if(infix[ch]=='(' || infix[ch]=='{' || infix[ch]=='[')
            push(infix[ch]);
        else if(infix[ch]==')' || infix[ch]=='}' || infix[ch]==']'){
            if(top_of_stack!=-1){
                ele=pop();
                if(( ele != get_open_brackets(infix[ch]))){
                     //printf("Brackets are not balanced..\n");
                     return 0;
                }

            }
            else{
                //printf("Closed bracket encountered without opening bracket..\n");
                return 0;
            }

        }
       // else if(infix[ch]=='{' || infix[ch]=='}' || infix[ch]=='[' || infix[ch]==']' ||infix[ch]=='$'|| infix[ch]=='#')
           // return 0;

        ch=ch+1;
    }
    if(top_of_stack==-1)
        return 1;

    else
        return 0;
}
int is_open_brace(char c)
{
    if(c=='{' || c=='[' || c=='(')
        return 1;
    return 0;

}
int is_closed_brace(char c)
{
    if(c=='}' || c==']' || c==')')
        return 1;
    return 0;

}

int isvalid_infix(char* infix)
{
    if(balanced_parnthesis(infix))
    {
        for(int i=0;i<strlen(infix);i++)
        {
            if(isoperator(infix[i]))
            {
                if(isoperator(infix[i+1]) || infix[i+1]=='\0' || !(isoperand(infix[i+1]) || is_open_brace(infix[i+1])) || !(isoperand(infix[i-1]) || is_closed_brace(infix[i-1])) )
                    return 0;
            }
            if(isoperand(infix[i]))
            {
                if(isoperand(infix[i+1]))
                    return 0;
            }
             if((is_open_brace(infix[i]) && is_closed_brace(infix[i+1])))
                return 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    char *expression=(char*)malloc(STR_SIZE*sizeof(char));
    //char *postfix=(char*)malloc(STR_SIZE*sizeof(char));
    printf("Enter the  Infix expression you want to convert:  ");
    gets(expression);
    if(isvalid_infix(expression)){
        printf("\nThe infix expression is valid\n");
        printf("\nThe postfix expression is ");
        char* postfix =infixtopostfix(expression);
        puts(postfix);
        char * prefix=infixtoprefix(expression);
        printf("\nThe prefix expression is ");
        puts(prefix);
        free(expression);
        //free(prefix);
        //free(postfix);
        return 0;
    }
    else{
        printf("\nInvalid infix expression..");
        return 0;
    }

}
