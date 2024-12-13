#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *right;
        struct node *left;
    };
struct node *root=NULL,*temp,*current,*newnode;

void inorderdisplay(struct node *temp)
{
    if(root==NULL)
    {
        printf("\nTree empty!\n");
    }
    else
    {
        if(temp!=NULL)
        {
            inorderdisplay(temp->left);
            printf("%d ",temp->data);
            inorderdisplay(temp->right);
        }   
           
    }
}

void treedisplay(struct node *node, int n)
{
    if(node==NULL)
    {
        return;
    }
    n++;
    treedisplay(node->right,n);
    if(n==1)
        printf("Root -> ");
    else
    {
        for(int i=0;i<n;i++)
        {
            printf("\t");            
        }
    }
    printf("%d\n",node->data);
    treedisplay(node->left,n);
}


int searchnode(struct node *temp,int key)
{
    if(temp!=NULL)
    {   
        int l,r;
        if(temp->data==key)
        {
            return 1;
        }
        else
        {
            l=searchnode(temp->left,key);
            if(l==1)
                return 1;
            r=searchnode(temp->right,key);
            if(r==1)
                return 1;
            
        }
        
    }
    else
    {
        return 0;
    }
}

struct node* nodecreation(int data)
{
    newnode=(struct node*)malloc(sizeof(newnode));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

struct node* insert(struct node *root,struct node *newnode)
{
    if (root==NULL)
        root=newnode;
        
    else if (newnode->data>root->data)
        root->right=insert(root->right,newnode);
        
    else
        root->left=insert(root->left,newnode);

    return root;       
}


void insertion()
{
    int t,f;
    printf("\nEnter the element : ");
    scanf("%d",&t);
    f=searchnode(root,t);
    if(f==0)
    {
        newnode=nodecreation(t);
        root=insert(root,newnode);
    }
    else
        printf("\nElement already present!\n");
}

struct node* successor(struct node *temp)
{
    struct node *succ;
    if(temp->right==NULL)
    {
        succ = NULL;
    }
    else
    {
        temp=temp->right;
        while(temp!=NULL)
        {
            if(temp->left==NULL)
            {
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
        succ=temp;
    }
    return succ;
}

struct node *delete(struct node *root, int key)
{
    if(key>root->data)
        root->right=delete(root->right,key);

    else if(key<root->data)
        root->left=delete(root->left,key);

    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            return temp;
        }
        else
        {
            temp=successor(root);
            root->data=temp->data;
            root->right=delete(root->right,root->data);
        }
    }
    return root;
}

void deletion()
{
    int key,f;
    printf("\nEnter the data to delete : ");
    scanf("%d",&key);
    f=searchnode(root,key);
    if(f==0)
        printf("\nElement not present in the tree!\n");

    else
        root=delete(root,key);
    
}


void main()
{
    int choice=0;
    while(choice<5)
    {
        printf("\nBST List operations\n");
        printf("1.Display \n2.Insertion \n3.Deletion \n4.Tree display \n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                inorderdisplay(root);
                break;
            case 2:
                insertion();
                break;
            case 3:
                deletion();
                break;
            case 4:
                treedisplay(root,0);
                break;
            case 5:
                break;
            default:
                break;
        }
    }

}
