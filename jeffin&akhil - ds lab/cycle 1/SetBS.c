#include<stdio.h>
int repeat(int a[],int n,int e);
int member(int a[],int n,int e);
void main()
{
    int u[50],s1[50],s2[50],n,n1,n2,t,f,m;

    printf("Enter the number of elements in the Universal Set :");
    scanf("%d",&n);
    printf("Enter the element 1 of the Universal Set : ");
    scanf("%d",&u[0]);

    for(int i=1;i<n;i++)
    {   
        printf("Enter the element %d of the Universal Set : ",i+1);
        scanf("%d",&t);
        f=repeat(u,n,t);
        while(f==1)
        {
            printf("\nElement already exists in the Universal Set.\nEnter another element for position %d: ",i+1);
            scanf("%d",&t);
            f=repeat(u,n,t);
        }
        u[i]=t;
    }

    printf("Universal set is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",u[i]);
    }
    

    printf("\vEnter the number of elements in the Set 1 :");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("\nEnter the element %d of the Set 1 : ",i+1);
        scanf("%d",&t);
        f=repeat(s1,i,t);
        m=member(u,n,t);
        while(f==1||m==0)
        {
            if(f==1)
                printf("\nElement already exists in Set 1.\n Enter another element from Universal set for position %d: ",i+1); 
            if(m==0)
                printf("\nElement is not a member of Universal Set.\n Enter another element from Universal set for position %d: ",i+1); 
            
            scanf("%d",&t);
            f=repeat(s1,i,t);
            m=member(u,n,t);
        }
        s1[i]=t;
    }

    printf("\vEnter the number of elements in the Set 2 :");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("\nEnter the element %d of the Set 2 : ",i+1);
        scanf("%d",&t);
        f=repeat(s2,i,t);
        m=member(u,n,t);
        while(f==1||m==0)
        {
            if(f==1)
                printf("\nElement already exists in Set 2.\n Enter another element from Universal set for position %d: ",i+1); 
            if(m==0)
                printf("\nElement is not a member of Universal Set.\n Enter another element from Universal set for position %d: ",i+1); 
            
            scanf("%d",&t);
            f=repeat(s2,i,t);
            m=member(u,n,t);
        }
        s2[i]=t;
    }

    int S1[n],S2[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if(u[i]==s1[j])
            {
                S1[i]=1;
                break;
            }
            S1[i]=0;   
            
        }
        for(int j=0;j<n2;j++)
        {
            if(u[i]==s2[j])
            {
                S2[i]=1;
                break;
            }
            S2[i]=0;  
        }
    }
    printf("\n\nBitstring of Set 1\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",S1[i]);
    }
    printf("\n\nBitstring of Set 2\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",S2[i]);
    
    }
    int uni[n],inter[n],diff[n];
    for(int i=0;i<n;i++)
     {
        if (S1[i]==1 || S2[i]==1)
            uni[i]=1;
        else
            uni[i]=0;
     }
     for(int i=0;i<n;i++)
     {
        if (S1[i]==1 && S2[i]==1)
            inter[i]=1;
        else
            inter[i]=0;
     }
     for(int i=0;i<n;i++)
     {
        if (S1[i]==1 && S2[i]==0)
            diff[i]=1;
        else
            diff[i]=0;
     }
    printf("\n\nS1 U S2 = ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",uni[i]);
    }

    printf("\n\nS1^S2 = ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",inter[i]);
    }

    printf("\n\nS1-S2 = ");
    for(int i=0;i<n;i++)
    {
    printf("%d ",diff[i]);
    }


}

int repeat(int a[],int n, int e)
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            f=1;
            break;
        }
    }
    return f;
}

int member(int a[],int n,int e)
{
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            m=1;
            break;
        }
    }
    return m;
}