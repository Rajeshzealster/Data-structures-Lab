#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left,*right;

}Node;

int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(Node* node)
{
   if(!node)
        return 0;
   else
        return (1+max(height(node->left),height(node->right)));
}

int balanced_factor(Node* node)
{
    if(!node)
        return 0;
    else
        return (height(node->left)-height(node->right));
}
Node* rotate_clockwise(Node* node)
{
    Node *y;
    y=node->left;
    node->left=y->right;
    y->right=node;
    return(y);
}
Node* rotate_anticlockwise(Node* node)
{
    Node *y;
    y=node->right;
    node->right=y->left;
    y->left=node;
    return(y);
}
Node* LL(Node* node)
{
    node=rotate_clockwise(node);
    return node;
}
Node* LR(Node* node)
{
    node->left=rotate_anticlockwise(node->left);
    node=rotate_clockwise(node);
    return node;
}
Node* RR(Node* node)
{
    node=rotate_anticlockwise(node);
    return node;
}
Node* RL(Node* node)
{
    node->right=rotate_clockwise(node->right);
    node=rotate_anticlockwise(node);
    return node;
}
Node* insert(Node* node,int ele)
{
   if(node==NULL)
   {
       Node* node=(Node*)malloc(sizeof(Node));
       node->data=ele;
       node->left=node->right=NULL;
       return node;
   }
   if(ele>node->data)
   {
       node->right=insert(node->right,ele);

   }
   else{
        node->left=insert(node->left,ele);

   }
   if(balanced_factor(node)<-1)
   {
       if(ele>node->right->data)
            node=RR(node);
       else
            node=RL(node);
   }
    if(balanced_factor(node)>1)
    {
       if(ele<node->left->data)
            node=LL(node);
       else
            node=LR(node);
    }
    return node;
}
Node* minimum_right_subtree(Node* node)
{
    while(node && node->left!=NULL)
        node=node->left;
    return node;

}
Node* delete(Node* node,int ele)
{
    if(node==NULL)
        return node;
    if(ele<node->data)
        node->left=delete(node->left,ele);
    else if(ele>node->data)
        node->right=delete(node->right,ele);
    else
    {
        if(node->left==NULL)
        {
            Node* t=node->right;
            free(node);
            return t;
        }
        else if(node->right==NULL)
        {
            Node* t=node->left;
            free(node);
            return t;
        }
        else{
            Node* t=minimum_right_subtree(node->right);
            node->data=t->data;
            node->right=delete(node->right,t->data);
        }
    }
    int bfactor=balanced_factor(node);
    if(bfactor>1)
    {
        if(balanced_factor(node->left)>=0)
            node=LL(node);
        else
            node=LR(node);
    }
    if(bfactor<-1)
    {
        if(balanced_factor(node->right)<=0)
            node=RR(node);
        else
            node=RL(node);
    }

    return node;

}
int search_element(Node* node,int ele)
{
    if(node==NULL)
        return 0;
    if(node->data==ele){
        return 1;
    }
    else
    {
        int ls=search_element(node->left,ele);
        int rs=search_element(node->right,ele);
        return ls||rs;
    }
}
int print_level(Node* node,int level)
{
    if(node==NULL)
        return 0;
    if(level==1){
        printf("%d ",node->data);
        return 1;
    }
    else
    {
        int l=print_level(node->left,level-1);
        int r=print_level(node->right,level-1);
        return l||r;
    }
}
void level_order_traversal(Node* node)
{
    int level=1;
    while(print_level(node,level))
    {
        printf("\n");
        level++;
    }
}
void inorder(Node* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d(bfactor=%d) ",root->data,balanced_factor(root));
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void preorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void sum_leftsubtree(Node* node,int* sum)
{
    if(!node)
        return;
    *sum+=node->data;
    sum_leftsubtree(node->left,sum);
    sum_leftsubtree(node->right,sum);

}

int main()
{
   int ch,ele;
    Node* root=NULL;
    printf("\n1.Insert into AVL tree\n2.Delete from AVL tree\n3.Print In-order,Pre-order,Post-order & Level-Order Traversal of AVL tree\n4.Sum of all nodes of left-subtree of root node\n5.Exit");

    do{
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter element to insert into AVL tree:");
            scanf("%d",&ele);
            if(!search_element(root,ele))
            {
                root=insert(root,ele);
            }
            else
                printf("\nElement %d is already present in AVL tree & No repeated elements allowed",ele);

        }
        else if(ch==2)
        {
            printf("\nEnter element to delete from AVL tree:");
            scanf("%d",&ele);
            if(search_element(root,ele))
            {
                root=delete(root,ele);
            }
            else
                printf("\nElement %d not found in AVL tree",ele);
        }
        else if(ch==3)
        {
            printf("\nIn-order traversal:");
            inorder(root);
            printf("\nPre-order traversal:");
            preorder(root);
            printf("\nPost-order traversal:");
            postorder(root);
            printf("\nLevel-order traversal:\n");
            level_order_traversal(root);
            printf("\nHeight of tree:%d",height(root));
        }
        else if(ch==4)
        {
            int sum_left_subtree=0;
            sum_leftsubtree(root->left,&sum_left_subtree);
            printf("\nThe sum of all nodes of left subtree of root node:%d",sum_left_subtree);
        }
        else if(ch==5)
        {
            printf("\nExit point");
        }
        else
            printf("\nEnter a valid choice");
    }while(ch!=5);
    return 0;
}
