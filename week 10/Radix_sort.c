#include<stdio.h>
#include<stdlib.h>

void Counting_sort(int* input,int place,int n)
{
    int i,value;
    //count array holding the count of each element from 0 to 9..
    int* count=(int *)calloc(10,sizeof(int));
    //output array storing the output of counting sort..
    int* output=(int *)malloc(n*sizeof(int));
    //Building the count array
    for(i=0;i<n;i++)
    {
        value=(input[i]/place)%10;
        count[value]+=1;
    }
    //storing the cumulative sum in the count array
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    //storing the elements into output array in the sorted array..
    i=n-1;
    while(i>=0)
    {
        value=(input[i]/place)%10;
        output[count[value]-1]=input[i];
        count[value]-=1;
        i--;
    }
    //storing output array into input array...so that sorting can be done again on ten's place....so on
    for(i=0;i<n;i++)
    {
        input[i]=output[i];
    }
    free(count);
    free(output);
}

void Radix_sort(int* input,int n)
{
    int i,max_ele=-1,place;
    //for finding the max element of the array
    for(i=0;i<n;i++)
    {
       if(input[i]>max_ele)
            max_ele=input[i];
    }
    //apply counting sort on unit's,ten's ....places
    place=1;
    while(max_ele/place >0)
    {
        Counting_sort(input,place,n);
        place*=10;
    }

}
int main()
{
    int n,i;
    int *input=(int *)malloc(n*sizeof(int));
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    printf("The elements of the array before sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

    Radix_sort(input,n);

    printf("\nThe elements of the array after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }
    free(input);

    return 0;
}
