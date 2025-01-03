#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };
struct node *top=NULL,*temp,*newnode;
int n;

void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty!!!\n");
    }
    else
    {
        printf("\n");
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n^\n",temp->data);
            temp=temp->next;
        }
        printf("!\n");
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
    else if (top==NULL)
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
    if(top==NULL)
    {
        printf("\nUnderflow!!\n");
    }
    else if (top->next==NULL)
    {
        temp=top;
        top=NULL;
        printf("\nDeleted %d\n",temp->data);
        printf("\nStack is empty\n");
        free(temp);
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
