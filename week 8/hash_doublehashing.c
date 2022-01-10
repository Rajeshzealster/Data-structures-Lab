#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define PRIMENUMBER 13
#define SIZE 20

int hash[SIZE]={INT_MIN};


int hash2_function(int key)
{
    return (PRIMENUMBER-(key%PRIMENUMBER));
}
void insert_hash(int ele)
{
    int hash_key,hash_index,i;
    hash_key=ele%SIZE;
    for(i=0;i<SIZE;i++)
    {
        hash_index=(hash_key+i*hash2_function(ele))%SIZE;
        if(hash[hash_index]==INT_MIN || hash[hash_index]==INT_MAX)//INT_MIN for empty slot & INT_MAX for deleted empty slot
        {
            hash[hash_index]=ele;
            break;
        }
    }
    if(i==SIZE)
    {
        printf("\nyou cannot insert %d into the table now..",ele);
    }
}
void display_hash()
{
    printf("\nThe elements of Hash table are:\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",hash[i]);
    }
}
int search_hash(int ele)
{
    /*int i,hash_key,j=0,c=0;
    hash_key=ele%SIZE;
    for(i=hash_key;c<SIZE;i=(hash_key+j*hash2_function(ele))%SIZE)
    {
        if(hash[i]==ele)
        {
            printf("\nElement %d is present..",ele);
            return 1;
            break;
        }
        j++;
        c++;
    }
    if(c==SIZE)
    {
        printf("\No such element is present..");
        return 0;
    }*/
    int hash1=ele%SIZE;
    int hash2=hash2_function(ele);
    int i=0,c=0;
    while(hash[(hash1 + i*hash2)%SIZE]!=ele){
        if(hash[(hash1+i*hash2)%SIZE]==INT_MIN || c>SIZE)
        {
            printf("Element %d does not exists",ele);
            return;
        }
        i++;
        c++;
    }
    printf("The element %d present in the table",ele);


}
void delete_hash(int ele)
{
    int i,hash_key,j=0,c=0;
    hash_key=ele%SIZE;
    if(search_hash(ele))
    {
        for(i=hash_key;c<SIZE;i=(hash_key+j*hash2_function(ele))%SIZE)
        {
            if(hash[i]==ele)
            {
                hash[i]=INT_MAX;//indicating that the element
                break;
            }
            j++;
            c++;
        }
        printf("\nElement %d gets deleted..",ele);
    }
}
void load_factor()
{
    int i,count=0;
    float lf=0.0;
    for(i=0;i<SIZE;i++)
    {
        if(hash[i]!=INT_MIN)
        {
            count++;
        }
    }
    //printf("%d",count);
    lf=(count/(float)SIZE);
    printf("\nLoad factor of hash table is %.2f",lf);
}
int main()
{
    int ch,ele;
    for(int i=0;i<SIZE;i++)
    {
        hash[i]=INT_MIN;
    }
    printf("1.Insert()\n2.Display()\n3.Search\n4.Delete\n5.Load factor\n6.Exit\n");
    do{
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter element to insert into hash table:");
            scanf("%d",&ele);
            insert_hash(ele);
        }
        else if(ch==2)
        {
            display_hash();
        }
        else if(ch==3)
        {
            printf("\nEnter element to search in the hash table:");
            scanf("%d",&ele);
            //double time_spent = 0.0;
            //clock_t c1= clock();

            search_hash(ele);

            //clock_t c2= clock();
            //time_spent += (double)(c2-c1)/(double)CLOCKS_PER_SEC;
            //printf("\nTime spent for searching the element is : ");
            //printf(" %f\n", time_spent);

        }
        else if(ch==4)
        {
            printf("\nEnter element to delete in the hash table:");
            scanf("%d",&ele);
            delete_hash(ele);
        }
        else if(ch==5)
        {
            load_factor();
        }
        else if(ch==6)
        {
            printf("Exit point");
        }
        else{
            printf("\nEnter a valid choice..");
        }
    }while(ch!=6);
    return 0;
}
