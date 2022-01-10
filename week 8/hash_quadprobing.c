#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int hash[SIZE];


void insert_hash(int ele)
{
    int hash_key,hash_index,i;
    hash_key=ele%SIZE;
    for(i=0;i<SIZE;i++)
    {
        hash_index=(hash_key+i*i)%SIZE;
        if(hash[hash_index]==INT_MIN)
        {
            hash[hash_index]=ele;
            break;
        }
    }
    if(i==SIZE)
    {
        printf("\nHash table is full& you cannot insert.");
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
    int i,hash_key,j=0,c=0;
    hash_key=ele%SIZE;
    for(i=hash_key;c<SIZE;i=(hash_key+j*j)%SIZE)
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
    }


}
void delete_hash(int ele)
{
    int i,hash_key,j=0,c=0;
    hash_key=ele%SIZE;
    if(search_hash(ele))
    {
        for(i=hash_key;c<SIZE;i=(hash_key+j*j)%SIZE)
        {
            if(hash[i]==ele)
            {
                hash[i]=INT_MIN;
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
            search_hash(ele);
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
