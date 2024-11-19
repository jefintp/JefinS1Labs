#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *front=NULL,*rear=NULL,*temp,*newnode;
int n;

void display()
{
    if(front==NULL)
    {
        printf("\nQueue is empty!!!\n");
    }
    else
    {
        printf("\n");
        temp=front;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int count()
{
    int count=0;
    if(front==NULL)
    {
        return count;
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
}

void enqueue()
{
    int c;
    c=count();
    if(c==n)
    {
        printf("\nQueue is full!!\n");
    }
    else if (rear==NULL)
    {
        newnode=(struct node*)malloc(sizeof(newnode));
        printf("Enter the element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
        printf("\nInserted %d\n",newnode->data);
        display();
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(newnode));
        printf("Enter the element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
        printf("\nInserted %d\n",newnode->data);
        display();
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("\nQueue is empty!!\n");
    }
    else if (front==rear)
    {
        temp=front;
        front=NULL;
        rear=NULL;
        printf("\nDeleted %d\n",temp->data);
        printf("\nQueue is empty\n");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("\nDeleted %d\n",temp->data);
        free(temp);
        display();
    }
}

void main()
{
    printf("Enter the size of the Queue : ");
    scanf("%d",&n);
    int choice=0;
    while(choice<4)
    {
        printf("\nQueue operations\n");
        printf("1.Display \n2.enqueue \n3.dequeue \n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                break;
            default:
                break;
        }
    }

}
