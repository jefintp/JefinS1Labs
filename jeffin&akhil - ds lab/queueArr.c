#include<stdio.h>
#include<conio.h>
#include<windows.h>
void display(int queue[]);
void enqueue(int queue[],int n);
void dequeue(int queue[]);
int front=-1,rear=-1;
void main()
{
    int queue[10],n,i,choice=0;
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
            display(queue);
            break;
        case 2:
            enqueue(queue,n);
            break;
        case 3:
            dequeue(queue);
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}

void display(int queue[])
{
    if(front==-1)
    {
        printf("\nQueue is empty\v");
        Beep(530,200);
    }
    else
    {
        printf("\nElements are: \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\v");
    }
}

void enqueue(int queue[],int n)
{
    int item;
    if(rear==n-1)
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
            queue[++rear]=item;

        }
        else
        {
            queue[++rear]=item;
        }
        printf("\v");
    }
}

void dequeue(int queue[])
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
            item=queue[front];
            printf("\nElement deleteded is %d\v",item);
            front=-1;
            rear=-1;
        }
        else
        {
            item=queue[front++];
            printf("\nElement deleteded is %d\v",item);
        }
        
    }
}