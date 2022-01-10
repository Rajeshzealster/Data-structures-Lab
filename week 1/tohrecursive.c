#include <stdio.h>
void TOH(int n, char S, char D, char U)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", S, D);
        return;
    }
    TOH(n-1, S, U, D);
    printf("\n Move disk %d from tower %c to tower %c", n, S, D);
    TOH(n-1, U,D,S);
}

void main()
{
   // int n = 4;
   int n;
    printf("\nEnter number of disks:");
    scanf("%d",&n);
    TOH(n, 'S', 'D', 'U');
    printf("\nTotal number of movements are %d",(1<<n)-1);
}
