#include<stdio.h>
void main()
{
    int u[50],s1[50],s2[50],n,n1,n2,t;

    printf("Enter the number of elements in the Universal Set :");
    scanf("%d",&n);
    printf("Enter the element 1 of the Universal Set : ");
    scanf("%d",&u[0]);
    for(int i=1;i<n;i++)
    {   
        printf("Enter the element %d of the Universal Set : ",i+1);
        scanf("%d",&t);
        for(int j=0;j<=i;j++)
            if(t==u[i])
                printf("\nEntered element already exist");
                printf("\nEnter the element %d of the Universal Set : ",i+1);
                scanf("%d",&u[i]);
            else
                u[i]=t;
    }

    printf("Enter the number of elements in the Set 1 :");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("Enter the element %d of the Set 1 : ",i+1);
        scanf("%d",&s1[i]);
    }

    printf("Enter the number of elements in the Set 2 :");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter the element %d of the Set 2 : ",i+1);
        scanf("%d",&s2[i]);
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
    printf("Bitstring of Set 1\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",S1[i]);
    }
    printf("Bitstring of Set 2\n");
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
    printf("\nS1 U S2=");
    for(int i=0;i<n;i++)
    {
    printf("%d ",uni[i]);
    }

    printf("\nS1^S2=");
    for(int i=0;i<n;i++)
    {
    printf("%d ",inter[i]);
    }

    printf("\nS1-S2=");
    for(int i=0;i<n;i++)
    {
    printf("%d ",diff[i]);
    }


}
