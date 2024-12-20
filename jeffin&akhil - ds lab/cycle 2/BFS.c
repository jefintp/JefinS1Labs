#include<stdio.h>
#include<conio.h>

int ar[25][25],visited[25],queue[25],front=-1,rear=-1;

void enqueue(int key)
{
    if(rear==-1)
    {
        front++;
        queue[++rear]=key;
    }
    else
    {
        queue[++rear]=key;
    }
}

int dequeue()
{
    int node;
    if(front==rear)
    {
        node=queue[front];
        front=-1;
        rear=-1;
    }
    else
    {
        node=queue[front++];
    }
    return node;
}

void bfs(int start,int n)
{
    int node;
    printf("\nVisited - %d ",start);
    enqueue(start);
    visited[start]=1;
    while(front!=-1)
    {
        node=dequeue();
        for(int i=0;i<n;i++)
            if(ar[node][i]==1 && visited[i]!=1)
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
    }
}

void main()
{
    int n,start,k;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            printf("Enter the element A[%d][%d] : ",i,j);
            scanf("%d",&k);
            ar[i][j]=k;
            ar[j][i]=k;
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
    printf("BFS Traversal :\n");
    bfs(start,n);
    getch();
}