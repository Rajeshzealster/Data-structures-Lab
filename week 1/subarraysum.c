//Smallest sub array with sum greater than given value..
#include<stdio.h>
#include<limits.h>
int leftindex=0,rightindex=0;

int small_sub_array_len(int[],int,int);
int min(int,int);

int min(int x,int y)
{
    return (x>y)?x:y;
}
int small_sub_array_len(int a[],int n,int value)
{
    int sum=0;
    int length=INT_MAX;
    int right=0,left=0;
    for(right=0;right<n;right++)
    {
        sum+=a[right];
        while(sum>value && left<right)
        {
            //length=min(len,right-left+1);
            if(length>(right-left+1))
            {
                length=right-left+1;
                leftindex=left;
                rightindex=right;
            }
            sum-=a[left++];
        }

    }
    return length;
}

void main()
{
    int n,i,len,val;
    //int a[];
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nThe elements of array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter the value(sub array sum > value):");
    scanf("%d",&val);
    len=small_sub_array_len(a,n,val);
    if(len!=INT_MAX)
    {
        printf("\nThe length of minimum sub array with sum greater than %d : %d",val,len);
        printf("\nThe obtained minimum array is:\n");
        for(i=leftindex;i<=rightindex;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n The minimum sub array after adding its length to each & every element of it:\n");
        for(i=leftindex;i<=rightindex;i++)
        {
            printf("%d\t",a[i]+len);
        }
    }
    else{
        printf("No such sub array exists");
    }

}
