#include<stdio.h>
#define MAX 50
int heap_size,n,ch;

void swap(int* a,int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void heapify(int a[],int index)
{
    int l,r,largest=0,smallest=0;
    l=2*index;
    r=2*index+1;
    if(ch==1)
    {
        if(l<=heap_size && a[l]>a[index])
            largest=l;
        else
            largest=index;
        if(r<=heap_size && a[r]>a[largest])
            largest=r;
        if(largest!=index)
        {
            swap(&a[index],&a[largest]);
            heapify(a,largest);
        }
    }
    else
    {
        if(l<=heap_size && a[l]<a[index])
            smallest=l;
        else
            smallest=index;
        if(r<=heap_size && a[r]<a[smallest])
            smallest=r;
        if(smallest!=index)
        {
            swap(&a[index],&a[smallest]);
            heapify(a,smallest);
        }
    }

}
void build_heap(int a[],int n)
{

    heap_size=n;
    for(int i=n/2;i>=1;i--)
    {
        heapify(a,i);
    }


}
void heap_sort(int a[],int n)
{
    build_heap(a,n);
    for(int i=n;i>=1;i--)
    {
        swap(&a[1],&a[i]);
        heap_size--;
        heapify(a,1);
    }


}
void insert_heap(int a[],int ele)
{
    int i;
    n=n+1;
    heap_size=n;
    a[n]=ele;
    i=n;
    if(ch==1)
    {
       while(i>1 && a[i/2]<a[i])
        {
            swap(&a[i],&a[i/2]);
            i=i/2;
        }
    }
    else{
        while(i>1 && a[i/2]>a[i])
        {
            swap(&a[i],&a[i/2]);
            i=i/2;
        }
    }


}
void delete_heap(int a[],int ele)
{
    int i,last_element=a[n];
    for(i=1;i<=n;i++)
    {
        if(a[i]==ele)
            break;
    }
    if(i==n+1)
        printf("\n%d does not exists in the heap..",ele);
    else{
        swap(&a[i],&a[n]);
        n=n-1;
        heap_size--;
        heapify(a,i);
        printf("\n%d exists in the heap& gets deleted..",ele);
    }

}

int main()
{
    int i,a[MAX],ch1,ele;
    //choice:
    do{
        printf("\n1.Sorting using Max_heapify\n2.Sorting using Min_heapify\n3.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1 || ch==2)
        {
            printf("\n1.Build heap\n2.Insert into heap\n3.Delete from heap\n4.Sort\n5.Exit\n");

            do{
                printf("\n\nEnter your choice:");
                scanf("%d",&ch1);
                if(ch1==1)
                {
                    printf("\nEnter the number of elements into heap:");
                    scanf("%d",&n);
                    printf("\nEnter elements:\n");
                    for(int i=1;i<=n;i++)
                    {
                        scanf("%d",&i[a]);
                    }
                    build_heap(a,n);
                    printf("\nheap is builded.....");
                    printf("%d ",heap_size);

                }
                else if(ch1==2)
                {
                    printf("\nEnter element to insert into heap:");
                    scanf("%d",&ele);
                    insert_heap(a,ele);
                }
                else if(ch1==3)
                {
                    printf("\nEnter element to delete from heap:");
                    scanf("%d",&ele);
                    delete_heap(a,ele);
                }
                else if(ch1==4)
                {
                    heap_sort(a,n);
                    if(ch==1)
                        printf("\nElements after sorting(max heap):\n");
                    else
                        printf("\nElements after sorting(min heap):\n");
                    for(int i=1;i<=n;i++)
                    {
                        printf("%d ",a[i]);
                    }
                }
                else if(ch1==5)
                    printf("\nExit point..");
                else
                    printf("\nEnter a valid choice..");
            }while(ch1!=5);

        }
        else if(ch==3)
            printf("\nExit point..");
        else{
            printf("\nEnter a valid choice");
            //goto choice;
        }
    }while(ch!=3);

    return 0;
}
