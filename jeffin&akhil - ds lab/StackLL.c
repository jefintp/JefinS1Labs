#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *top=NULL,*temp,*current,*newnode;
int n;

void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty!!!\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp=temp->next;
        }
    }
}

int count()
{
    int count=0;
    if(top==NULL)
    {
        return count;
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
}

void push()
{
    int c;
    c=count();
    if(c==n)
    {
        printf("\nOverflow!!\n");
    }
    else if (c==0)
    {
        newnode=(struct node*)malloc(sizeof(newnode));
        printf("Enter the element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(newnode));
        printf("Enter the element : ");
        scanf("%d",&newnode->data);
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    int c;
    c=count();
    if(c==0)
    {
        printf("\nUnderflow!!\n");
    }
    else if (c==1)
    {
        temp=top;
        top=NULL;
        printf("\nDeleted %d\n",temp->data);
        printf("\nStack is empty\n");
    }
    else
    {
        temp=top;
        top=top->next;
        printf("\nDeleted %d\n",temp->data);
        free(temp);
        display();
    }
}

void main()
{
    printf("Enter the size of the stack : ");
    scanf("%d",&n);
    int choice=0;
    while(choice<4)
    {
        printf("\nStack operations\n");
        printf("1.Display \n2.Push \n3.Pop \n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                push();
                break;
            case 3:
                pop();
                break;
            case 4:
                break;
            default:
                break;
        }
    }

}
