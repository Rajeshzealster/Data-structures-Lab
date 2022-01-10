/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *Left=(int*)malloc((n1+1)*sizeof(int));
	int *Right=(int*)malloc((n2+1)*sizeof(int));


	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	Left[n1]=INT_MAX;
    Right[n2]=INT_MAX;
    i=0;j=0;
    for(k=l;k<=r;k++)
    {
        if(Left[i]<Right[j])
        {
            arr[k]=Left[i];
            i++;
        }
        else{
            arr[k]=Right[j];
            j++;
        }
    }
	free(Left);
    free(Right);
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r) {
		int m =l + (r-l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/*void printArray(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}*/
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main()
{
	printf("###performance of merge sort on different kinds of array\n\n");
	printf("  n(size)\t\t");
	printf("(unsorted)\t\t");
	printf("(sorted)\t\t");
	printf("(almost sorted)\n\n");
	srand((int)time(NULL));

	for(int k=4;k<8;k++){
	    int n=pow(10,k);
	    printf("%8d\t\t",n);
        int *arr = (int *) malloc(n * sizeof(int));
        for(int i=0;i<n;i++)
        {
            arr[i]=rand()%10000000000;
        }

        double time_spent = 0.0;
        clock_t c1,c2;
        c1= clock();

        merge_sort(arr,0,n-1);

        c2= clock();
        time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;

        printf("%f\t\t", time_spent);

        time_spent = 0.0;
        c1= clock();

        merge_sort(arr,0,n-1);

        c2= clock();
        time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;
        printf("%f\t\t", time_spent);
        free(arr);

        int *arr1 = (int *) malloc(n * sizeof(int));
        for(int i=0;i<n;i++)
        {
            arr1[i]=rand()%10000000000;
        }
        //swapping 1% pairs of array
        for(int i=0;i<(n/100);i++)
        {
            int r=rand()%n;
            swap(&arr1[r],&arr1[r+1]);
        }
        time_spent = 0.0;
        c1= clock();

        merge_sort(arr1,0,n-1);

        c2= clock();
        time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;
        printf(" %f\n", time_spent);
        free(arr1);

	}
    return 0;
}
