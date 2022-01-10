#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct node{
    int data;
    struct node *left,*right;
}Node;

Node* create_tree(int a[],Node *root,int index,int n)
{
    if(index<n)
    {
        Node * temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=a[index];
        temp->left=NULL;
        temp->right=NULL;
        root=temp;

        root->left=create_tree(a,root->left,2*index+1,n);

        root->right=create_tree(a,root->right,2*index+2,n);
    }
    return root;

}
void spaces(int n)
{
    for(int i=0;i<n;i++)
        printf("  ");
}
void print(Node* root,int n)
{
    if(root==NULL)
        return;
    else{
        print ( root->right, n+3);
        spaces ( n );
        printf ( " %d\n", root->data );
        print ( root->left, n + 3 );
    }

}
int height_tree(Node* root)
{
    if(root==NULL)
        return 0;
    else{
        int left_height=height_tree(root->left);
        int right_height=height_tree(root->right);

        if(left_height>right_height)
            return (left_height+1);
        else
            return (right_height+1);
    }

}
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main()
{
   //int a[]={1,2,3,4,5,6,7,8};
   int n,h;
   int a[max];
   printf("\nEnter the number of nodes of a tree:");
   scanf("%d",&n);
   printf("\nEnter all the %d nodes level by level:\n",n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   Node *root=create_tree(a,root,0,n);
   printf("\nThe tree is as shown(Horizontally):\n");

   h=height_tree(root);
   print(root,h);
   printf("\nHeight of the tree : %d",h);
   printf("\nInorder traversal of tree:\n");
   inorder(root);
   printf("\npreorder traversal of tree:\n");
   preorder(root);
   printf("\npostorder traversal of tree:\n");
   postorder(root);

}
