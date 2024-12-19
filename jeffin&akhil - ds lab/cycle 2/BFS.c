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
    printf("\nEnqued front=%d rear=%d",front,rear);
}

int dequeue()
{
    if(front==rear)
    {
        return queue[front];
        front=-1;
        rear=-1;
    }
    else
    {
        return queue[front++];
    }
    printf("\ndequed front= %d rear= %d",front,rear);
}

void bfs(int start,int n)
{
    int node;
    printf("\nVisited - %d ",start);
    enqueue(start);
    visited[start]=1;
    printf("\nVisited of %d = 1",start);
    while(front<=rear)
    {
        node=dequeue();
        printf("\nnode = %d",node);
        for(int i=0;i<n;i++)
            if(ar[node][i]==1 && visited[i]!=1)
            {
                printf("\nVisited - %d ",i);
                visited[i]=1;
                enqueue(i);
            }
    }
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
    printf("BFS Traversal :\n");
    bfs(start,n);
    getch();
}