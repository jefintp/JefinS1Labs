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


int inordertraversal(struct node *temp,int key)
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
            l=inordertraversal(temp->left,key);
            if(l==1)
                return 1;
            r=inordertraversal(temp->right,key);
            if(r==1)
                return 1;
            
        }
        
    }
    else
    {
        return 0;
    }
}

/*
int count()
{
    int count=0;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
}
*/

void insert()
{
    int t,f;
    printf("\nEnter the element : ");
    scanf("%d",&t);
    f=inordertraversal(root,t);
    if(f==0)
    {
        newnode=(struct node*)malloc(sizeof(newnode));
        newnode->data=t;
        newnode->left=NULL;
        newnode->right=NULL;

        if(root==NULL)
        {
            root=newnode;
            printf("\nInserted %d\n",newnode->data);
            printf("\nNew tree is\n");
            inorderdisplay(root);
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                if(t<temp->data)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        printf("\nInserted %d\n",newnode->data);
                        printf("\nNew tree is\n");
                        inorderdisplay(root);
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        printf("\nInserted %d\n",newnode->data);
                        printf("\nNew tree is\n");
                        inorderdisplay(root);
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }
    }
    
    else
    {
        printf("\nElement already present!\n");
    }
    
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

struct node* predecessor(struct node *temp)
{
    struct node *pre;
    if(temp->left==NULL)
    {
        pre=NULL;
    }
    else
    {
        temp=temp->left;
        while(temp!=NULL)
        {
            if(temp->right==NULL)
            {
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
        pre=temp;
    }
    return pre;
}

struct node* parent(int key)
{
    struct node *p=root;
    while(p!=NULL)
    {
        if(p->left->data==key || p->right->data==key)
        {
            break;
        }
        if(key>p->data)
        {
            p=p->right;
        }
        else
        {
            p=p->left;
        }
    }
    return p;
}

struct node* del_node(int key)
{
    temp=root;
    while (temp!=NULL)
    {
        if(temp->data==key)
        {
            break;
        }
        else if(key<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    
    return temp;
}

void delete()
{
    int t,f,pr=0,su=0;
    struct node *p,*succ,*pre,*c;
    printf("\nEnter the element to delete : ");
    scanf("%d",&t);
    f=inordertraversal(root,t);
    if(f==1) 
    {
        printf("\nElement present\n");
        //deleting root node
        if(t==root->data)
        {
            printf("\nDeleteing root\n");
            if(root->left==NULL&&root->right==NULL)
            {
                root=NULL;
                printf("\ntree empty\n");
            }
            else
            {
                temp=successor(root);
                su=1;
                if(temp==NULL)
                {
                    temp=predecessor(root);
                    su=0;
                    pr=1;
                }
                printf("\nReplacing root with %d",temp->data,"\n");
                p=parent(temp->data);
                root->data=temp->data;
                if(p->left->data==temp->data)
                {
                    if(su==1)
                        if(temp->right!=NULL)
                            p->left=temp->right;
                        else
                            p->left=NULL;
                    else
                        if(temp->left!=NULL)
                            p->left=temp->left;
                        else
                            p->left=NULL;
                }
                else
                {
                    if(su==1)
                        if(temp->right!=NULL)
                            p->right=temp->right;
                        else
                            p->right=NULL;
                    else
                        if(temp->left!=NULL)
                            p->right=temp->left;
                        else
                            p->right=NULL;
                }

            }
        }

        else
        {
            temp=del_node(t);
        	p=parent(temp->data);

            //deleting leaf node
            if(temp->left==NULL&&temp->right==NULL)
            {
                printf("\ndeleting leaf node\n");
                if(p->left->data==temp->data)
                {
                    p->left=NULL;
                }
                else
                {
                    p->right=NULL;
                }
            }

            //deleting node with one child
            else if(temp->left==NULL&&temp->right!=NULL)
            {
                printf("\nDeleting node with right child\n");
                succ=temp->right;
                printf("\nReplacing node with %d",succ->data,"\n");
                p=parent(temp->data);
                temp->data=succ->data;
                if(p->left->data==temp->data)
                {
                    p->left=succ;
                }
                else
                {
                    p->right=succ;
                }

            }

            else if(temp->right==NULL&&temp->left!=NULL)
            {
                printf("\nDeleting node with left child\n");
                pre=temp->left;
                printf("\nReplacing node with %d",pre->data,"\n");
                p=parent(temp->data);
                temp->data=pre->data;
                if(p->left->data==temp->data)
                {
                    p->left=pre;
                }
                else
                {
                    p->right=pre;
                }

            }

            //deleting node with two children
            else
            {
                printf("\nDeleting node with two children\n");
                c=successor(temp);
                if(c==NULL)
                {
                    c=predecessor(temp);
                }
                printf("\nReplacing node with %d",c->data,"\n");
                p=parent(c->data);
                temp->data=c->data;
                if(p->left->data==c->data)
                {
                    if(c->right!=NULL)
                        p->left=c->right;
                    else
                        p->left=NULL;
                }
                else
                {
                    if(c->left!=NULL)
                        p->right=c->left;
                    else
                        p->right=NULL;
                }
            }
        }
    printf("\nElement deleted\n");
    }
    else
    {
        printf("\nElement not present in the tree!\n");
    }
}

void deletenode(struct node *temp)
{

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
                insert();
                printf("\n");
                break;
            case 3:
                delete();
                printf("\n");
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
