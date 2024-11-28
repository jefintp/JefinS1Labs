#include<stdio.h>
#include<conio.h>
#include<windows.h>
void display(int cqueue[],int n);
void enqueue(int cqueue[],int n);
void dequeue(int cqueue[],int n);
int front=-1,rear=-1;
void main()
{
    int cqueue[10],n,i,choice=0;
    printf("Enter the size of the queue :\t");
    scanf("%d",&n);
    Beep(1000,150);

    while(choice<4)
    {
        printf("\nQueue operations\n");
        printf("1.Display \n2.Enqueue \n3.Dequeue \n4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            display(cqueue,n);
            break;
        case 2:
            enqueue(cqueue,n);
            break;
        case 3:
            dequeue(cqueue,n);
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}

void display(int cqueue[],int n)
{
    
    if(front==-1)
    {
        printf("\nQueue is empty\v");
        Beep(530,200);
    }
    else if(front==rear)
    {
        printf("\nElements are: \n%d",cqueue[front]);
    }
    else if((rear+1%n)==front)
    {
        int i=front;
        printf("\nElements are: \n");
        while(i!=rear)
        {
            printf("%d\t",cqueue[i]);
            i=(i+1)%n;
        }
        printf("\v");
    }
    else
    {
        int i=front;
        printf("\nElements are: \n");
        while(i!=(rear+1)%n)
        {
            printf("%d\t",cqueue[i]);
            i=(i+1)%n;
        }
        printf("\v");
       
    }
}

void enqueue(int cqueue[],int n)
{
    int item;
    if((rear+1)%n==front)
    {
        printf("\nQueue is full!!!\v");
        Beep(530,200);
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d",&item);
        if(front==-1)
        {
            front++;
            cqueue[++rear]=item;

        }
        else
        {
            rear=(rear+1)%n;
            cqueue[rear]=item;
        }
        printf("\v");
    }
    printf("%d\t%d",front,rear);
}

void dequeue(int cqueue[],int n)
{
    int item;
    if(front==-1)
    {
        printf("\nQueue is empty!!!\v");
        Beep(530,200);
    }
    else
    {
        if(front==rear)
        {   
            item=cqueue[front];
            printf("\nElement deleted is %d\v",item);
            front=-1;
            rear=-1;
        }
        else
        {   
            item=cqueue[front];
            front=(front+1)%n;
            printf("\nElement deleted is %d\v",item);
        }
        
    }
}