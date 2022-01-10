#define max 50
#include <ctype.h>
#include <stdio.h>
#include <math.h>

char s[max];
int top = -1;




void push(char ele) {
 //s[++top] = ele;
 if(top>100)
    {
        printf("overflow");
    }
   /* if(top!=-1 &&s[top]>=0 && s[top]<=9)
    {
        s[top]*=10;
        s[top]+=ele;
    }*/
    else
        s[++top]=ele;
}


char pop() {
 return (s[top--]);
}


int pr(char elem) {
  if(elem=='$')
        return 0;
    else if(elem=='(')
        return 1;
    else if(elem=='+' || elem=='-')
        return 2;
    else if(elem=='*' || elem=='/')
        return 3;
    else
        return 4;

}

/*
Function to convert from infix to postfix expression
*/
void infix_to_postfix(char *infix, char *postfix) {
 char ch, elem;
 int i = 0, k = 0;


 push('$');

 while ((ch = infix[i++]) != '\n')
{
     if (ch == '(')
        push(ch);
     else if (isalnum(ch))
        postfix[k++] = ch;
     else if (ch == ')')
     {
     while (s[top] != '(')
        postfix[k++] = pop();
     elem = pop();
     }
     else
     {
         while (pr(s[top]) >= pr(ch))
         postfix[k++] = pop();
         push(ch);
     }
}

 while (s[top] != '$')
 postfix[k++] = pop();

 postfix[k] = '\0';
}


int eval_postfix(char *postfix) {
 char ch;
 int i = 0, op1, op2;
 while((ch = postfix[i++]) != '\0')
 {
     if(isdigit(ch))
        push(ch-'0');
     else
     {
         if(isalnum(ch))
         {
             printf("\nEvaluation is not possible");
             return 0;
         }

         op2 = pop();
         //printf("\n%d",op2);
         op1 = pop();
         //printf(" %d",op2);
         if(ch=='+')
            push(op1+op2);
         else if(ch=='-')
            push(op1-op2);
         else if(ch=='*')
            push(op2*op1);
         else if(ch=='/')
            push(op1/op2);
         else if(ch=='^')
            push(pow(op1,op2));
     }
 }

 return s[top];
}

void main()
{

 char infix[50], postfix[50];
 printf("\nInput the infix expression(without spaces): ");
 fgets(infix, 50, stdin);

 infix_to_postfix(infix, postfix);

 printf("Given Infix Expression: %sPostfix Expression: %s", infix, postfix);
 top = -1;
 printf("\nResult of evaluation of postfix expression : %d", eval_postfix(postfix));

}
