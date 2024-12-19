#include<stdio.h>
#include<conio.h>

int ar[25][25],visited[25];

void dfs(int start,int n)
{
    visited[start]=1;
    printf("%d ",start);
    for(int i=0;i<n;i++)
        if(ar[start][i]==1 && visited[i]!=1)
            dfs(i,n);
}

void main()
{
    int n,start;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the element A[%d][%d] : ",i,j);
            scanf("%d",&ar[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ar[i][j]);
        }
        printf("\n");
    }

    printf("Enter the starting node for traversal : ");
    scanf("%d",&start);
    printf("DFS Traversal :\n");
    dfs(start,n);
}