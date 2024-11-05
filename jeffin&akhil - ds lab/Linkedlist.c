#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *head=NULL,*temp,*current,*newnode;


void display()
{
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
}

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

void insert()
{
    newnode=(struct node*)malloc(sizeof(newnode));
    printf("Enter the element : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        int c,p,n;
        n=count();
        printf("Where do you want to insert \n1.Begining 2.Specific position 3. End : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            newnode->next=head;
            head=newnode;
            break;

        case 2:
            printf("Enter the position to enter : ");
            scanf("%d",&p);
            if(p==1)
            {
                newnode->next=head;
                head=newnode;
                break;
            }
            else if(p==n)
            {
                temp=head;
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                break;
            }
            if(p>n)
            {
                printf("Invalid position");
                break;
            }
            temp=head;
            for(int i=2;i<p;i++)
            {
              temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            break;
            
        case 3:
            temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            break;

        default:
            break;
        }
    }
}

void delete()
{
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else
    {
        int c,p;
        printf("Which node do you want to delete \n1.Begining 2.Specific node 3. End : ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                temp=head;
                head=head->next;
                free(temp);
                break;

            case 2:
                printf("Enter the position to delete : ");
                scanf("%d",&p);
                current=head;
                for(int i=2;i<p;i++)
                {
                current=current->next;
                }
                temp=current->next;
                current->next=temp->next;
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
        printf("\nLinked List operations\n");
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

