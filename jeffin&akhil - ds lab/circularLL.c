#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *head=NULL,*temp,*current,*newnode,*tail=NULL;


void display()
{
    if(head==NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        temp=head;
        do
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }while(temp!=head);
        printf("HEAD\n");
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
        do
        {
            count++;
            temp=temp->next;
        }
        while(temp!=head);
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
        tail=newnode;
        newnode->next=head;
        printf("\nInserted %d\n",newnode->data);
        printf("\nNew list is\n");
        display();
        printf("head %d tail %d",head->data,tail->data);
    }
    else
    {
        int c,p,n;
        n=count();
        printf("\n1.Begining \n2.Specific position \n3.End \nWhere do you want to insert : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            tail->next=newnode;
            newnode->next=head;
            head=newnode;
            printf("\nInserted %d",newnode->data);
            printf("\nNew list is\n");
            display();
            printf("head %d tail %d",head->data,tail->data);
            break;

        case 2:
            printf("Enter the position to enter : ");
            scanf("%d",&p);
            if(p>n+1)
            {
                printf("\nInvalid position!!!\n");
                break;
            }
            if(p==1)
            {
                tail->next=newnode;
                newnode->next=head;
                head=newnode;
                printf("\nInserted %d\n",newnode->data);
                printf("\nNew list is\n");
                display();
                printf("head %d tail %d",head->data,tail->data);
                break;
            }
            
            temp=head;
            for(int i=2;i<p;i++)
            {
              temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            if(newnode->next==head)
            {
                tail=newnode;
            }
            printf("\nInserted %d\n",newnode->data);
            printf("\nNew list is\n");
            display();
            printf("head %d tail %d",head->data,tail->data);
            break;
            
        case 3:
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
            printf("\nInserted %d\n",newnode->data);
            printf("\nNew list is\n");
            display();
            printf("head %d tail %d",head->data,tail->data);
            break;

        default:
            break;
        }
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
    else if(head->next==head)
    {
        temp=head;
        head=NULL;
        tail=NULL;
        printf("\nDeleted %d\n",temp->data);
        printf("\nNew list is empty\n");
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
                printf("\nhead %d tail %d\n",head->data,tail->data);
                head=temp->next;
                tail->next=head;
                printf("\n\nhead %d tail %d tail next %d\n\n",head->data,tail->data,tail->next->data);
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                printf("head %d tail %d",head->data,tail->data);
                
                printf("tail next %d",tail->next->data);
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
                    tail->next=head;
                }
                else
                {
                    current=head;
                    for(int i=2;i<p;i++)
                    {
                    current=current->next;
                    }
                    temp=current->next;
                    current->next=temp->next;
                    if(temp==tail){
                        tail=current;
                    }
                }
                
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                printf("head %d tail %d",head->data,tail->data);
                break;
                
            case 3:
                current=head;
                while (current->next!=tail)
                {
                    current=current->next;
                }
                temp=current->next;
                current->next=head;
                tail=current;
                printf("\nDeleted %d\n",temp->data);
                printf("\nNew list is\n");
                display();
                printf("current %d head %d tail %d",current->data,head->data,tail->data);
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
