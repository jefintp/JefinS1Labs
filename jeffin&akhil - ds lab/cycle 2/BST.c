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
    if(temp!=NULL)
    {   
        printf("%d ",temp->data);
        inorderdisplay(temp->left);
        inorderdisplay(temp->right);
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
    newnode=(struct node*)malloc(sizeof(newnode));
    printf("\nEnter the element : ");
    scanf("%d",&newnode->data);
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
        
    
    }
}

void delete()
{
    int n;
    n=count();
    if(head==NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        printf("\nDeleted %d\n",temp->data);
        printf("\nNew list is empty\n");
        free(temp);
    }
    else
    {
        int c,p;
        printf("\n1.Begining \n2.Specific node \n3. End\nWhich node do you want to delete : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                temp=head;
                head=head->next;
                head->prev=NULL;
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                free(temp);
                break;

            case 2:
                printf("Enter the position to delete : ");
                scanf("%d",&p);
                if(p>n)
                {
                    printf("\nInvalid position!!!\n");
                    break;
                }
                if(p==1)
                {
                    temp=head;
                    head=head->next;
                    head->prev=NULL;
                }
                else
                {
                    current=head;
                    for(int i=2;i<p;i++)
                    {
                    current=current->next;
                    }
                    if(current->next->next==NULL)
                    {
                        temp=current->next;
                        current->next=NULL;
                    }
                    else
                    {
                        temp=current->next;
                        current->next=temp->next;
                        temp->next->prev=current;
                    }
                }
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                free(temp);
                break;
                
            case 3:
                current=head;
                while (current->next->next!=NULL)
                {
                    current=current->next;
                }
                temp=current->next;
                current->next=NULL;
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                free(temp);
                break;

            default:
                break;
        } 
    }
}

void main()
{
    int choice=0;
    while(choice<4)
    {
        printf("\nDoubly Linked List operations\n");
        printf("1.Display \n2.Insertion \n3.Deletion \n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                break;
            default:
                break;
        }
    }

}
