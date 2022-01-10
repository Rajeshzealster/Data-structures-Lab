//The results provided by me in the output file are from the online compiler OnlineGDB.....

#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>

void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int h)
{
    int x,i,j;
    x=a[h];
    i=(l-1);
    for(j=l;j<h;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return(i+1);
}
int median_pivot(int a[],int l,int m,int h)
{

    if ((a[l] > a[m]) ^ (a[l] > a[h]))
        swap(&a[l],&a[h]);
    else if ((a[m] < a[l]) ^ (a[m] < a[h]))
        swap(&a[m],&a[h]);

    return (partition(a,l,h));
}
int random_pivot(int a[],int l,int h)
{
   int random=l+rand()%(h-l);
   swap(&a[random],&a[h]);
   return (partition(a,l,h));
}


void quick_sort(int a[],int l,int h,int type)
{
    if(l<h)
    {
        int p,m=(l+h)/2;

        if(type==1)
        {
            swap(&a[l],&a[h]);
            p=partition(a,l,h);
        }
        //printf("%d",p);
        else if(type==2)
        {
            p=random_pivot(a,l,h);
        }
        else if(type==3){
             p=median_pivot(a,l,m,h);
        }
        else if(type==4){
            int m1,m2,m3;
            m1=l+((h-l)/4);
            m2=l+((h-1)/2);
            m3=l+(3*((h-l)/4));
            p=median_pivot(a,m1,m2,m3);
        }
        quick_sort(a,l,p-1,type);
        quick_sort(a,p+1,h,type);
    }

}
void main()
{
   printf("###performance of quick sort on different kinds of array\n\n");
	printf("  n(size)\t\t");
	printf("pivot type\t\t");
	printf("(Random)\t\t");
	printf("(sorted)\t\t");
	printf("(almost sorted)\n\n");
	srand((int)time(NULL));

	for(int k=4;k<8;k++){
        for(int type=1;type<5;type++)
        {
            int n=pow(10,k);
            printf("%8d\t\t",n);
            if(type==1)
                printf("First_pivot\t\t");
            else if(type==2)
                printf("Random_pivot\t\t");
            else if(type==3)
                printf("Median_pivot1\t\t");
            else if(type==4)
                printf("Median_pivot2\t\t");
            int *a= (int *) malloc(n * sizeof(long int));
            for(int i=0;i<n;i++)
            {
                a[i]=rand()%10000000000;
            }

            double time_spent = 0.0;
            clock_t c1,c2;
            c1= clock();

            quick_sort(a,0,n-1,type);

            c2= clock();
            time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;

            printf("%f\t\t", time_spent);

            time_spent = 0.0;
            c1= clock();

            quick_sort(a,0,n-1,type);

            c2= clock();
            time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;
            printf("%lf\t\t", time_spent);
            free(a);

            int *a1 = (int *) malloc(n * sizeof(long int));
            for(int i=0;i<n;i++)
            {
                a1[i]=rand()%10000000000;
            }
            //swapping 1% pairs of array
            for(int i=0;i<(n/100);i++)
            {
                int r=rand()%n;
                swap(&a1[r],&a1[r+1]);
            }
            time_spent = 0.0;
            c1= clock();

            quick_sort(a1,0,n-1,type);

            c2= clock();
            time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;
            printf(" %lf\n", time_spent);
            free(a1);
        }
        printf("\n\n");

	}



}

