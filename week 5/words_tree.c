#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
#define CAPACITY 10

//structure for leaf nodes
typedef struct leaf{
    int freq;
}Leaf;

//structure for words under category
typedef struct words{
    char s[SIZE];
    struct leaf *l;//pointer to leaf node(frequency)
    int limit;
}Words;

//structure for categories under root
typedef struct category{
    char s[SIZE];
    struct words *w[CAPACITY];//array of pointers to words under caategory
    int c;
}Category;
//structure for root
typedef struct root{
    char s[SIZE];
    struct category *c[CAPACITY];
}Root;
typedef struct array{
	char s[SIZE];
	int freq;
}Array;

Root* r=NULL;

//create root
Root* create_root( char s[]){
	int i;
	Root *temp = (Root*)malloc(sizeof(Root));
	strcpy(temp->s,s);
	for(i=0;i<CAPACITY;i++)
		temp->c[i] = NULL;

	return temp;
}

//create category
Category* create_category(char s[]){
	int i;
	Category* temp = (Category*)malloc(sizeof(Category));
	strcpy(temp->s,s);
	temp->c = -1;
	for(i-0;i<CAPACITY;i++)
		temp->w[i] = NULL;
	return temp;
}
//create words
Words* create_words(char s[],int limit){
	Words* temp = (Words*)malloc(sizeof(Words));
	strcpy(temp->s,s);
	temp->l = NULL;
	temp->limit=limit-1;

	return temp;
}

//create leaf
Leaf *create_leaf(){
	Leaf *temp = (Leaf*)malloc(sizeof(Leaf));
	temp->freq = 2;
	return temp;
}

int check_cat(char s[]){
	int i;
	Root *temp = r;

	while(temp->c[i] != NULL && i < CAPACITY){
		if(strcmp(temp->c[i]->s,s)==0)
			return 1;
		i++;
	}
	return 0;
}
Root *insert_category(Root *r, char s[]){

	Root *temp = r;
	int i = 0,j;

    if(check_cat(s))
        printf("\nCategory already present!");
    else{
        while(i < CAPACITY){
            if(temp->c[i] == NULL)
                break;
            i++;
        }
        if(i!=CAPACITY){
            temp->c[i] = create_category(s);
            temp->c[i]->c = i+1;
        }
        else{
            printf("\nNo more categories allowed");
        }
    }

	return temp;
}

int get_cat(char *s){
	Root *temp = r;
	int i=0;
	if(check_cat(s)){
			while(strcmp(temp->c[i]->s,s) != 0){
				i++;
		}
		return i;
	}
	return -1;
}
Root *insert_word(Root *r){

	Root *temp = r;
	Words *word;
	int i = 0,j=0,limit;
	char s[SIZE],s1[SIZE];
	printf("\nEnter word to be inserted:");
    scanf(" %[^\n]s",s);
    printf("\nEnter category to be inserted the given word: ");
    scanf(" %[^\n]s",s1);
    i = get_cat(s1);
    if(i != -1){
        while(j < CAPACITY){
            if(temp->c[i]->w[j]!= NULL)	{
                if(strcmp(temp->c[i]->w[j]->s,s) == 0) {
                    if(temp->c[i]->w[j]->l == NULL)
                    {
                        if(temp->c[i]->w[j]->limit!=0){
                            temp->c[i]->w[j]->l = create_leaf();
                            printf("\nAlready present. Leaf is now created & Frequency is %d",temp->c[i]->w[j]->l->freq);
                            temp->c[i]->w[j]->limit--;
                        }
                        else{
                            printf("Limit on this word [%s] exceeded",s);
                        }

                    }
                    else{
                        if(temp->c[i]->w[j]->limit!=0){
                            temp->c[i]->w[j]->l->freq++;
                            printf("\nLeaf already had created & Frequency is %d",temp->c[i]->w[j]->l->freq);
                            temp->c[i]->w[j]->limit--;
                        }
                        else{
                            printf("Limit on this word [%s] exceeded",s);
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("\nEnter the limit frequency for this word:");
                scanf("%d",&limit);
                word = create_words(s,limit);
                temp->c[i]->w[j] = word;
                //printf("creation of word success");
                break;
            }
            j++;
        }
        if(j == CAPACITY){
            printf("\ncapacity of words is over!");
        }
    }
    else{
        printf("\nCategory not present!");
    }
    return temp;
}

void display_categoriesandwords(){
	Root *temp = r;
	int i = 0, j = 0;
	while(i < CAPACITY){
		if(temp->c[i] != NULL){
				printf("\nCategory : %s",temp->c[i]->s);
			printf("\nWords are: ");
			j = 0;
			while(temp->c[i]->w[j] != NULL && j < CAPACITY){
				printf("%s\t",temp->c[i]->w[j]->s);
				j++;
			}
		}

		i++;
	}
}
int is_category(char s[])
{
    Root* temp=r;
    int i=0,f=0;
    while(i<CAPACITY)
    {
        if(temp->c[i]!=NULL){
            if(strcmp(temp->c[i]->s,s)==0)
            {
                f=1;
                break;
            }
        }
        i++;
    }
    return f;
}
int is_word(char s[])
{
    Root* temp=r;
    int i=0,j=0;
    while(i<CAPACITY && temp->c[i]!=NULL)
    {
        j=0;
        while(j<CAPACITY && temp->c[i]->w[j]!=NULL )
        {
            if(strcmp(temp->c[i]->w[j]->s,s)==0)
                return 1;
            j++;
        }
        i=i+1;
    }
    return 0;
}
void degree_node(Root* r,char s[])
{
    Root* temp=r;
    int i=0,k=0,j=0;
    if(strcmp(temp->s,s)==0)
    {
        while(i<CAPACITY)
        {
            if(temp->c[i]==NULL)
                break;
            i++;
        }
        printf("\nDegree of [%s] :%d",s,i);
    }
    else if(is_category(s))
    {
        while(k<CAPACITY)
        {
            if(temp->c[k]!=NULL){
                if(strcmp(temp->c[k]->s,s)==0)
                {
                    break;
                }
            }
            k++;
        }
        while(temp->c[k]->w[j] != NULL && j < CAPACITY)
            j++;

        printf("\nDegree of [%s] :%d",s,j);
    }
    else if(is_word(s))
    {
        i=0,j=0,k=0;
        while(i<CAPACITY)
        {
            if(temp->c[i]!=NULL){
                if(temp->c[i]->w[j]!=NULL)
                {
                    while(j<CAPACITY)
                    {
                        if(strcmp(temp->c[i]->w[j]->s,s)==0)
                        {
                            k=i;
                            break;
                        }
                        j++;
                    }
                }

            }
            i++;
         }
         if(temp->c[k]->w[j]->l==NULL)
            printf("\nDegree of [%s]:0",s);
         else
            printf("\nDegree of [%s]:1",s);
    }
    else
        printf("\n %s is not found in the tree",s);

}
void depth_node(Root* r,char s[])
{
    if(strcmp(r->s,s)==0)
        printf("\nDepth of [%s]:0",s);
    else if(is_category(s))
        printf("\nDepth of [%s]:1",s);
    else if(is_word(s))
        printf("\nDepth of [%s]:2",s);
    else
        printf("\n[%s] not found in tree",s);
}
void display_leaves()
{
    Root *temp=r;
    int i=0;
    int j=0;
    if(temp->c[0]==NULL)
        printf("%s ",temp->s);

    while(i<CAPACITY)
    {
        if(temp->c[i]!=NULL){
            if(temp->c[i]->w[0]==NULL)
                printf("%s ",temp->c[i]->s);
            j=0;
            while(temp->c[i]->w[j] != NULL && j < CAPACITY){
                if(temp->c[i]->w[j]->l==NULL)
                    printf("%s ",temp->c[i]->w[j]->s);
                j++;
            }
        }
        i++;
    }

}
void display_desc_frequency()
{
    Root * temp=r;
    Array arr[50];
    char c[50];
    int f;
    int i=0,j=0,k=0;
    while(i<CAPACITY)
    {
        if(temp->c[i]!=NULL)
        {
            j=0;
            while(temp->c[i]->w[j] != NULL && j < CAPACITY){
                strcpy(arr[k].s,temp->c[i]->w[j]->s);
                if(temp->c[i]->w[j]->l!=NULL)
                    arr[k].freq=temp->c[i]->w[j]->l->freq;
                else
                    arr[k].freq=1;
                k++;
                j++;
            }
        }
        i++;
    }
    for(i=0;i<k;i++){
		for(j=0;j<k-i-1; j++){
			if(arr[j].freq < arr[j+1].freq){
				strcpy(c,arr[j].s);
				strcpy(arr[j].s,arr[j+1].s);
				strcpy(arr[j+1].s,c);

				f = arr[j].freq;
				arr[j].freq = arr[j+1].freq;
				arr[j+1].freq = f;
			}
		}
	}

	for(i=0;i<k;i++){
			printf("\n%s - Frequency - %d",arr[i].s,arr[i].freq);
	}

}
void main(){

	int x,ch;
	char s[SIZE],r1[CAPACITY],ans;
	printf("\nEnter the root string:");
	scanf("%[^\n]s",s);//reads the string until new line encounters
	r = create_root(s);
	printf("\nRoot is : %s", r->s);
    printf("\n1.Insert Category\n2.Insert word\n3.Display categories & words\n4.Degree of node\n5.Depth of node\n6.Display leaves excluding level 4\n7.Display words in frequency descending order\n8.Exit");

	do{


        printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\nEnter category name:");
			scanf(" %[^\n]s",s);
			r = insert_category(r,s);
		}
		else if(ch == 2){
			r = insert_word(r);
		}
		else if(ch == 3)
			display_categoriesandwords();
		else if(ch == 4){
            printf("\nEnter node name:");
			scanf(" %[^\n]s",s);
			degree_node(r,s);
		}
		else if(ch == 5){
			printf("\nEnter node name:");
			scanf(" %[^\n]s",s);
			depth_node(r,s);
		}
		else if(ch == 6){
            printf("\nThe leaves excluding level 4 nodes are:");
            display_leaves();
		}

		else if(ch == 7)
			display_desc_frequency();
        else if(ch==8)
            printf("\nExit point");

	}while(ch != 8);
}


