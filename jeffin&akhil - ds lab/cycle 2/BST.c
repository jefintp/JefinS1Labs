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
        printf("\nElement already inserted!\n");
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
        while(temp!=NULL)
        {
            if(temp->left==NULL)
            {
                succ=temp;
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
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
        while(temp!=NULL)
        {
            if(temp->right==NULL)
            {
                pre=temp;
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
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
    int t,f;
    struct node *p,*succ,*pre;
    printf("\nEnter the element to delete : ");
    scanf("%d",&t);
    f=inordertraversal(root,t);
    if(f==1) 
    {
        //deleting root node
        if(t==root->data)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                root=NULL;
            }
            else
            {
                temp=successor(root);
                if(temp==NULL)
                {
                    temp=predecessor(root);
                }
                p=parent(temp->data);
                root->data=temp->data;
                if(p->left->data==temp->data)
                {
                    p->left=NULL;
                }
                else
                {
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
                succ=successor(temp);
                p=parent(succ->data);
                temp->data=succ->data;
                if(p->left->data==succ->data)
                {
                    p->left=NULL;
                }
                else
                {
                    p->right=NULL;
                }

            }

            else if(temp->right==NULL&&temp->left!=NULL)
            {
                pre=predecessor(temp);
                p=parent(succ->data);
                temp->data=succ->data;
                if(p->left->data==pre->data)
                {
                    p->left=NULL;
                }
                else
                {
                    p->right=NULL;
                }

            }

            //deleting node with two children
            else
            {
                
            }
        }

    }
    else
    {
        printf("\nElement not present in the tree!\n");
    }
}

void main()
{
    int choice=0;
    while(choice<4)
    {
        printf("\nBST List operations\n");
        printf("1.Display \n2.Insertion \n3.Deletion \n4.Exit\n");
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
                break;
            case 4:
                break;
            default:
                break;
        }
    }

}
