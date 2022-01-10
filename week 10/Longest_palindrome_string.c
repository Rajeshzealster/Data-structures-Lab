#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

void Longest_Palindrome(char str[])
{
    int i,j,len,n;
    int begin=0,Pal_length=1;
    //Length of the string
    i=0,n=0;
    while(str[i++]!='\0')
        n++;
    int table[n][n];//for storing whether [i.....j] is a palindrome or not in table[i][j]....1 if yes,0 otherwise
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            table[i][j]=0;
    //Every string of length 1 is a palindrome...
    for(i=0;i<n;i++)
        table[i][i]=1;

    //for strings of length 2..
    for(i=0;i<n;i++)
    {
        if(str[i]==str[i+1])
        {
            table[i][i+1]=1;
            begin=i;
            Pal_length=2;
        }
    }
    //sub strings of length >2..
    for(len=3;len<=n;len++)
    {
        for(i=0;i<n-len+1;i++)
        {
           j=i+len-1;
           if(table[i+1][j-1] && str[i]==str[j])
           {
               table[i][j]=1;
               if(len>Pal_length)
               {
                   Pal_length=len;
                   begin=i;
               }
           }
        }
    }
    printf("The longest palindromic string is:");
    for(i=begin;i<(begin+Pal_length);i++)
    {
        printf("%c",str[i]);
    }
    printf("\nThe length of longest palindromic string is %d",Pal_length);
}
int main()
{
    char str[SIZE];
    int i;
    printf("Enter your String:");
    scanf("%[^\n]s",str);

    Longest_Palindrome(str);

    return 0;
}
