#include<stdio.h>
void display(int a[],int n);
void insert(int a[],int n);
void delete(int a[],int n);
void sort(int a[],int n);
void search(int a[],int n);

void main()
{
    int n,i;
    printf("Ënter the number of items in array :");
    scanf("%d",&n);
    int a[10],o=0;
    printf("Enter the elements of array :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    while(o<6)
    {
        printf("\nArray operations\n");
        printf("1.Display \n2.Insertion \n3.Deletion \n4.Search \n5.Sort \n6.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&o);
    
    switch (o)
    {
    case 1:
        display(a,n);
        break;
    case 2:
        n++;
        insert(a,n);
        display(a,n);
        break;
    case 3:
        delete(a,n);
        n--;
        display(a,n);
        break;
    case 4:
        search(a,n);
        break;
    case 5:
        sort(a,n);
        display(a,n);
        break;
    case 6:
        break;    
    default:
        break;
    }
    }

}

void display(int a[],int n)
{
    printf("\nElements are: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void insert(int a[],int n)
{
    int p,item;
    printf("Enter the item and position : ");
    scanf("%d%d",&item,&p);
    for(int i=n;i>p;i--)
    {
        a[i]=a[i-1];
    }
    a[p]=item;
}


void delete(int a[],int n)
{
    int p,item;
    printf("Enter the index : ");
    scanf("%d",&p);
    item=a[p];
    for(int i=p;i<n;i++)
    {
        a[i]=a[i+1];
    }
    printf("\nItem deleted is %d\n",item);
}

void search(int a[],int n)
{
    int item;
    printf("\nEnter the item to be searched : ");
    scanf("%d",&item);
    for(int i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("\nItem found at index %d\n",i);
            return;
        }
    }
    printf("\nElement not found\n");
}
void sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}