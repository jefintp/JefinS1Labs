#include<stdio.h>
#include<conio.h>
#include<windows.h>
void display(int stack[]);
void push(int stack[],int n);
void pop(int stack[]);
int top=-1;
void main()
{
    int stack[10],n,i,choice=0;
    printf("Enter the size of the stack :\t");
    scanf("%d",&n);
    Beep(1000,150);

    while(choice<6)
    {
        printf("\nStack operations\n");
        printf("1.Display \n2.Push \n3.Pop \n4.Peek \n5.Count \n6.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            display(stack);
            break;
        case 2:
            push(stack,n);
            break;
        case 3:
            pop(stack);
            break;
        case 4:
            if(top==-1)
            {
                printf("\nStack is empty\v");
                Beep(200,200);
            }
            else
            {
                printf("\nTop item in Stack is %d\v",stack[top]);
            }
            break;
        case 5:
            printf("\nNumber of items in Stack is %d\v",top+1);
            break;
        default:
            break;
        }
    }
}

void display(int stack[])
{
    if(top==-1)
    {
        printf("\nStack is empty\v");
        Beep(530,200);
    }
    else
    {
        printf("\nElements are: \n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
        printf("\v");
    }
}

void push(int stack[],int n)
{
    int item;
    if(top==n-1)
    {
        printf("\nStack Overflow!!!\v");
        Beep(530,200);
    }
    else
    {
        printf("\nEnter the element to push: ");
        scanf("%d",&item);
        stack[++top]=item;
        printf("\v");
    }
}

void pop(int stack[])
{
    int item;
    if(top==-1)
    {
        printf("\nStack Underflow!!!\v");
        Beep(530,200);
    }
    else
    {
        item=stack[top--];
        printf("\nElement popped is %d\v",item);
    }
}